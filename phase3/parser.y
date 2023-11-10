%{
	#include<stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "symbol_table.c"
	extern int yylineno;
	extern FILE* yyin, *yyout;
    FILE* fparse;
	int yylex(void);
	int yyerror(const char *s);
	
	// flags
	int inClass=0;
	int inStruct=0;
	int level=0;  // indicates level of scope
	int inFunc=0;
	int currentFuncIndex; // To be used by call statements to grab func details
	int classIndex = -1; // To be used by call statements to grab func details
	int funcIndex = -1;
	
	int dataType;
	/*
		dataType = 0 --> standard
		dataType = 1 --> array
		dataType = 2 --> vector
		dataType = 3 --> matrix
		dataType = 4 --> graph
		dataType = 5 --> struct
		dataType = 6 --> class
	*/
	
	char* arr[20];
	int arr_size=0;
	int dimA[20];
	int dimB[20];
	/*
		MY ASSUMPTIONS:
			--> if it is parameter, only type check is feasible, but no attibute check non-standard datatypes
	*/
%}

%union{
	char* str;
	struct{
		char* name;
		char* type;
	} details;
	
}

%type<str> fdtype dtype id id_list graph_and_array_list matrix_list return_stmt RHS constants extra_consts impr matrix_impr graph_impr arith_op logical_op func_calls binary_op unary_op arg_list call_head for_RHS myId
%type<details> function function_head func_definition LHS

%token <str> newid
%token <str> INT_CONST
%token  FLOAT_CONST
%token CHAR_CONST
%token STR_CONST
%token BOOL_CONST
%token ARROW
%token PUNC
%token <str> DATATYPE
%token <str> VOID
%token RETURN
%token IF
%token ELSE
%token CONTINUE
%token BREAK
%token <str> MATRIX
%token <str> GRAPH
%token <str> VECT
%token SWITCH
%token CASE
%token DEFAULT
%token CLASS
%token STRUCT
%token LOGOP
%token ARITHOP
%token NOT
%token UNARYOP
%token DECLR
%token EXPR
%token CALL
%token FUNC
%token LOOP
%token null
%token FOR
%token WHILE
%token <str> APPEND
%token <str> REMOVE
%token <str> LENGTH
%token <str> SORT
%token <str> CLEAR
%token <str> AT
%token <str> TRANSPOSE
%token <str> TRACE
%token <str> TRAVERSAL
%token <str> STRLEN
%token <str> STRCUT
%token <str> STRCMP
%token <str> STRJOIN
%token <str> MATXOP
%token <str> MAXTOGR
%token <str> GRTOMATX
%token <str> SHPATH
%token <str> SHPATH_VAL
%token GOTO

%start program_unit

%%
program_unit			: models
 						;
 						
models					: model models
						| model
						;
						
model					: function
						| class
						| struct
						;
						
class					: CLASS id '{' {
							level++; 
							inClass = 1;
							if(class_search($2)!=-1 || struct_search($2)!=-1)
							{
								printf("Struct or class name already exists\n");
								exit(1);
							}
								
							else class_insert($2);
							
						} class_items '}' { var_delete(level); level--; inClass = 0; } ';' {fprintf(fparse, " : CLASS DEFINITION");}
						;

id						: newid {$$=$1;}
						| APPEND {$$=$1;}
						| REMOVE {$$=$1;}
						| LENGTH {$$=$1;}
						| SORT {$$=$1;}
						| CLEAR {$$=$1;}
						| AT {$$=$1;}
						| TRANSPOSE {$$=$1;}
						| TRACE {$$=$1;}
						| TRAVERSAL {$$=$1;}
						| STRLEN {$$=$1;}
						| STRCUT {$$=$1;}
						| STRJOIN {$$=$1;}
						| STRCMP {$$=$1;}
						| MAXTOGR {$$=$1;}
						| GRTOMATX {$$=$1;}
						| SHPATH {$$=$1;}
						| SHPATH_VAL {$$=$1;}
						;
						
class_items				: class_item class_items
						| class_item
						;
						
class_item				: declr_stmt
						| function 
						;
						
struct					: STRUCT id '{'
							{
								level++; 
								if(class_search($2)!=-1 || struct_search($2)!=-1)
								{
									printf("Struct or class name already exists\n");
									exit(1);
								}
								
								else struct_insert($2);
								
							} 
							struct_items '}' { var_delete(level); level--;}';' {fprintf(fparse, " : STRUCT DEFINITION");}
						;
						
struct_items			: declr_stmt struct_items
						| declr_stmt
						;
						
function				: function_head function_body
						;
						
function_head			: func_definition Parameters { 
							$$=$1; 
							if(inClass == 0) printFuncDetails(-1, func_size-1);
							else printFuncDetails(class_size-1, -1); 
							fprintf(fparse, " : FUNCTION HEAD");
						}
						;


func_definition			: FUNC fdtype id {
							$$.name = $3;
							$$.type = $2;
							if(inClass == 0) func_insert($3, $2);
							else class_func_insert(class_size-1, $3, $2);
							currentFuncIndex = func_size-1;
						}
						;
						
Parameters				: '(' ')'
						| '(' param_list ')'
						;
						
						
fdtype					: dtype {$$ = $1;}
						| VOID {$$ = $1;}
						;
						
						
param_list				: param_list ',' param
						| param
						;
						
						
param					: dtype id {
							if(inClass == 0) add_args($1);
							else class_add_args(class_size-1, $1);
							if(dataType == 0) var_insert(0, level, $2, $1, "", -1, -1);
							else if(dataType == 2){
								strncpy($1, $1 + 1, strlen($1)-1);
								var_insert(0, level, $2, "vect", $1, -1, -1);
							}
							else if(dataType == 3) {
								var_insert(0, level, $2, "matrix", "", -1, -1);
							}
							else if(dataType == 4) {
								var_insert(0, level, $2, "graph", "", -1, -1);
							}
							else if(dataType == 5){
								var_insert(0, level, $2, $1, "", -1, -1);
							}
							else if(dataType == 6) {
								var_insert(0, level, $2, $1, "", -1, -1);
							}

						}
						| dtype id '[' ']' {
							var_insert(0, level, $2, "array", $1, -1, -1);
						}
						;
						
						
						
dtype					: DATATYPE {$$ = $1; dataType = 0;}
						| MATRIX {$$ = $1; dataType = 3;}
						| GRAPH {$$ = $1; dataType = 4;}
						| VECT '<' dtype '>' { 
							char* result;
							char* A = "*";
						    result = (char*)malloc(strlen(A) + strlen($3) + 1);
						    strcpy(result, A);
						    strcat(result, $3);
						    dataType = 2;
						    $$ = result;
						}
						| id {
							int i = struct_search($1);
							if(i < 0) {
								i = class_search($1);
								if(i < 0){
									printf("Error: Using undefined datatype %s\n", $1);
								}
								else{
									dataType = 6;
									$$ = $1;
								}
							}
							else{
								dataType = 5;
								$$ = $1;
							}
						}
						;
						
function_body			: '{' { level++; } statements '}' {var_delete(level); level--;}
						| '{' '}'
						;
						
statements				: statement statements
						| statement
						| function_body statements
						| function_body
						;
						
statement				: expr_stmt
						| call_stmt
						| declr_stmt 
						| ifcond_stmt
						| switch_stmt
						| jump_stmt
						| loop_stmt
						| return_stmt
						| unary_stmt
						| vect_stmt
						| BREAK ';' {fprintf(fparse, " : BREAK STATEMENT");}
						| CONTINUE ';' {fprintf(fparse, " : CONTINUE STATEMENT");}
						;
						
unary_stmt				: unary_op ';' {fprintf(fparse, " : UNARY STATEMENT");}
						;
						
jump_stmt				: label_stmt
						| goto_stmt
						;
						
label_stmt				: id 
							{
								if(label_search($1)!=-1) 
								{
									printf("Label name already exists\n");
									exit(1);
								}
								else label_insert($1);
							}
							':' function_body {fprintf(fparse, " : LABEL");}
						;
						
goto_stmt				: GOTO id ';' {fprintf(fparse, " : GOTO STATEMENT");}
						;

vect_stmt				: vect_stmt_body ';' {fprintf(fparse, " : INDEPENDENT METHOD");}
						;

vect_stmt_body			: resultant '.' APPEND '(' vect_append ')'
						| resultant '.' REMOVE '(' remove_body ')'
						| resultant '.' SORT '(' ')'
						| resultant '.' CLEAR '(' ')'
						;
						

remove_body				: INT_CONST
						| FLOAT_CONST
						| LHS
						| func_calls
						| arith_op
						| logical_op
						| impr
						;
						
						
vect_append				: RHS
						| extra_consts
						;
return_stmt 			: RETURN RHS';'{if(inClass==0){
								if(strcmp($2,func_symb[currentFuncIndex].type)){printf("error\n");}
							}
							else{
								if(strcmp($2,class_symb[class_size-1].func_list[currentFuncIndex-1].type)){
									printf("error\n");
								}
							}
							} {fprintf(fparse, " : RETURN STATEMENT");}
						| RETURN extra_consts ';' 
						 {
							if(inClass==0){
								if(strcmp($2,func_symb[currentFuncIndex].type)){printf("error\n");}
							}
							else{
								if(strcmp($2,class_symb[class_size-1].func_list[currentFuncIndex-1].type)){
									printf("error\n");
								}
							}
						 }{fprintf(fparse, " : RETURN STATEMENT");}
						| RETURN graph_impr ';'
						{
							if(inClass==0){
								if(strcmp($2,func_symb[currentFuncIndex].type)){printf("error\n");}
							}
							else{
								if(strcmp($2,class_symb[class_size-1].func_list[currentFuncIndex-1].type)){
									printf("error\n");
								}
							}
						 } {fprintf(fparse, " : RETURN STATEMENT");}
						| RETURN matrix_impr ';'{if(inClass==0){
								if(strcmp($2,func_symb[currentFuncIndex].type)){printf("error\n");}
							}
							else{
								if(strcmp($2,class_symb[class_size-1].func_list[currentFuncIndex-1].type)){
									printf("error\n");
								}
							}
							}  {fprintf(fparse, " : RETURN STATEMENT");}
						| RETURN vect_stmt_body ';' {fprintf(fparse, " : RETURN STATEMENT");}
						| RETURN null ';' {fprintf(fparse, " : RETURN STATEMENT");}
						;
				
						

loop_stmt				: LOOP loop_type {fprintf(fparse, " : LOOP");}
						; 

loop_type				: for_loop
						| while_loop
						;
				
for_loop				: FOR '(' expr_stmt logical_op ';' for_expr ')' function_body
						;

for_expr				: unary_op
						| EXPR LHS '=' for_RHS {
							if(strcmp($2.type, $4)){
								int a = !strcmp($2.type, "int") || !strcmp($2.type, "float") || !strcmp($2.type, "bool");
								int b = !strcmp($4, "int") || !strcmp($4, "float") || !strcmp($4, "bool");
							
								if(!(a && b)){
									printf("%s:%s != <name>:%s\n", $2.name, $2.type, $4);
									printf("Error: Expression statement, type mismatch\n");
									exit(1);
								}
							}
						}
						;
						
for_RHS					: arith_op {$$ = $1;}
						| func_calls {$$ = $1;}
						| impr {$$ = "improvised";}
						| graph_impr {$$ = "improvised";}
						| vect_stmt_body {$$ = "improvised";}
						| matrix_impr {$$ = "improvised";}
						;

while_loop				: WHILE '('RHS')' {
							int a = !strcmp($3, "int") || 
									!strcmp($3, "float") || 
									!strcmp($3, "bool") ||
									!strcmp($3, "string") ||
									!strcmp($3, "char")
									;
							if(!a) {
								printf("Error : Invalid conditional argument\n");
							}
						} function_body
						;
						
expr_stmt				: EXPR LHS '=' RHS ';' {
							if(strcmp($2.type, $4)){
								int a = !strcmp($2.type, "int") || !strcmp($2.type, "float") || !strcmp($2.type, "bool");
								int b = !strcmp($4, "int") || !strcmp($4, "float") || !strcmp($4, "bool");
							
								if(!(a && b)){
									printf("%s:%s != <name>:%s\n", $2.name, $2.type, $4);
									printf("Error: Expression statement, type mismatch\n");
									exit(1);
								}
							}
							
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
						| EXPR LHS '=' extra_consts ';' {fprintf(fparse, " : EXPRESSION STATEMENT");}
						| EXPR LHS '=' graph_impr ';' {fprintf(fparse, " : EXPRESSION STATEMENT");}
						| EXPR LHS '=' matrix_impr ';' {fprintf(fparse, " : EXPRESSION STATEMENT");}
						| EXPR LHS '=' vect_stmt_body ';' {fprintf(fparse, " : EXPRESSION STATEMENT");}
						;
						
						
LHS						: myId {
							// printf("%s\n", $1);
							classIndex = -1; // indicates it is independent function(for call statements)
							int i = var_search($1);
							printf("%s - %d\n", $1, i);
							if( i < 0){
								printf("Error: Accessing undeclared identifier %s\n", $1);
								exit(1);
							}
							else{
								$$.name = $1;
								$$.type = var_symb[i].type;
							}
						}
						| LHS ARROW myId {
							int ind = var_search($1.name);
							
							if(ind < 0){
								printf("Error: Accessing undefined identifier %s\n", $1.name);
								exit(1);
							}
							char* dType = var_symb[ind].type;
							int i = struct_search(dType);
							if(i < 0){
								i = class_search(dType);
								if(i < 0){
									
									// item is not defined in class and struct
									printf("Error: Accessing undefined datatype %s\n", $1.name);
									exit(1);
								}
								
								else{
									
									int j = class_declr_search($3, i);
									int k = class_func_search($3, i);
									if(j < 0 && k < 0){
										printf("Error: Accessing undefined function/attribute of class %s\n", $1.name);
										exit(1);
									}
									
									if(j >= 0){
										$$.name = $3;
										$$.type = class_symb[i].declr_list[j].type;
									}
								
									else if(k >= 0){
									
										// set global variables of required indices for call statements
										funcIndex = k;
										classIndex = i;
										$$.name = $3;
										$$.type = "func"; // can be ignored
									}
								}
							}
							
							else {
								// item defined in struct
								int j = struct_declr_search($3, i);
								if(j < 0){
								
									// item is not attribute of this struct
									printf("Error: Accessing undefined attribute of struct %s\n", $1.name);
									exit(1);
								}
								
								else{
									$$.name = $3;
									$$.type = struct_symb[i].list[j].type;
								}
							}
						}
						;
						
						
myId					: id {$$=$1;}
						| id '[' RHS ']'{
							int a = !strcmp($3, "int") || !strcmp($3, "float");
							if(!a){
								printf("Error: invalid array index\n");
								exit(1);
							}
							$$ = $1;
						}
						;

declr_stmt				: DECLR declr_body ';' {fprintf(fparse, " : DECLARATION STATEMENT");}

declr_body				: DATATYPE id_list
							{
								if(currentFuncIndex!=-1)
								{
									for(int i=0; i<arr_size; i++)
									{
										var_insert(1, level, arr[i], $1, "" , -1, -1);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										add_class_declrs(arr[i], $1, 1, level, "", -1, -1);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										add_struct_declrs(arr[i], $1, 1, level, "", -1, -1);
									}
								}
								arr_size =0;
							}
						| GRAPH graph_and_array_list
							{
								if(currentFuncIndex!=-1)
								{
									for(int i=0; i<arr_size; i++)
									{
										var_insert(1, level, arr[i], $1, "" , dimA[i], -1);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										add_class_declrs(arr[i], $1, 1, level, "", dimA[i], -1);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										add_struct_declrs(arr[i], $1, 1, level, "", dimA[i], -1);
									}
								}
								arr_size=0;
							}
						| VECT '<' dtype '>' id_list
							{
								if(currentFuncIndex!=-1)
								{
									for(int i=0; i<arr_size; i++)
									{
										var_insert(1, level, arr[i], $1, $3, -1, -1);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										add_class_declrs(arr[i], $1, 1, level, $3, -1, -1);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										add_struct_declrs(arr[i], $1, 1, level, $3, -1, -1);
									}
								}
								arr_size=0;
							}
						| MATRIX matrix_list 
							{
								if(currentFuncIndex!=-1)
								{
									for(int i=0; i<arr_size; i++)
									{
										var_insert(1, level, arr[i], $1, "" , dimA[i], dimB[i]);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										add_class_declrs(arr[i], $1, 1, level, "", dimA[i], dimB[i]);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										add_struct_declrs(arr[i], $1, 1, level, "", dimA[i], dimB[i]);
									}
								}
								arr_size=0;
							}
						| DATATYPE graph_and_array_list
							{
								if(currentFuncIndex!=-1)
								{
									for(int i=0; i<arr_size; i++)
									{
										var_insert(1, level, arr[i], "array", $1 , -1, -1);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										add_class_declrs(arr[i], "array", 1, level, $1, -1, -1);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										add_struct_declrs(arr[i], "array", 1, level, $1, -1, -1);
									}
								}
								arr_size=0;
							}
						| id id_list
							{
								if(class_search($1)!=-1 || struct_search($1)!=-1)
								{
									if(currentFuncIndex!=-1)
									{
										for(int i=0; i<arr_size; i++)
										{
											var_insert(1, level, arr[i], $1, "", -1, -1);
										}
									}
									else if(inClass==1)
									{
										for(int i=0; i<arr_size; i++)
										{
											add_class_declrs(arr[i], $1, 1, level, "", -1, -1);
										}
									}
									else
									{
										for(int i=0; i<arr_size; i++)
										{
											add_struct_declrs(arr[i], $1, 1, level, "", -1, -1);
										}
									}
									arr_size =0;
								}
								else
								{
									arr_size=0;
									printf("No struct or class with that name is defined\n");
									exit(1);
								}
							}
						;

graph_and_array_list	: id '[' INT_CONST ']' ',' graph_and_array_list
							{
								arr[arr_size] = $1;
								dimA[arr_size] = atoi($3);
								if(dimA[arr_size]<=0)
								{
									printf("Number of vertices in a graph has to be greater than 0\n");
									exit(1);
								}
								arr_size++;
							}
						| id '[' INT_CONST ']'
							{
								arr[arr_size] = $1;
								dimA[arr_size] = atoi($3);
								if(dimA[arr_size]<=0)
								{
									printf("Number of vertices in a graph has to be greater than 0\n");
									exit(1);
								}
								arr_size++;
							}
						;

matrix_list				: id '[' INT_CONST ']' '[' INT_CONST ']' ',' matrix_list
							{
								arr[arr_size] = $1;
								dimA[arr_size] = atoi($3);
								dimB[arr_size] = atoi($6);
								if(dimA[arr_size]<=0 || dimB[arr_size]<=0)
								{
									printf("No of rows or columns has to be positive\n");
									exit(1);
								}
								arr_size++;
							}
						| id '[' INT_CONST ']' '[' INT_CONST ']'
							{
								arr[arr_size] = $1;
								dimA[arr_size] = atoi($3);
								dimB[arr_size] = atoi($6);
								if(dimA[arr_size]<=0 || dimB[arr_size]<=0)
								{
									printf("No of rows or columns has to be positive\n");
									exit(1);
								}
								arr_size++;
							}
						;

id_list					: id ',' id_list
							{
								arr[arr_size] = $1;
								arr_size++;
							}
						| id
							{
								arr[arr_size] = $1;
								arr_size++;
							}
						;

ifcond_stmt				: IF '(' RHS ')' {
							int a = !strcmp($3, "int") || 
									!strcmp($3, "float") || 
									!strcmp($3, "bool") ||
									!strcmp($3, "string") ||
									!strcmp($3, "char")
									;
							if(!a) {
								printf("Error : Invalid conditional argument\n");
							}
							fprintf(fparse, " : CONDITIONAL STATEMENT");
						} if_body
						;
						
						
if_body					: function_body ELSE function_body
						| function_body
						;

switch_stmt				: SWITCH '(' RHS ')' {
							int a = !strcmp($3, "int") || 
									!strcmp($3, "float") || 
									!strcmp($3, "bool") ||
									!strcmp($3, "string") ||
									!strcmp($3, "char")
									;
							if(!a) {
								printf("Error : Invalid conditional argument\n");
							}
							fprintf(fparse, " : CONDITIONAL STATEMENT");
						} switch_body
						;
						

switch_body				: '{' {level++;} cases DEFAULT ':' function_body '}' { var_delete(level); level--;}
						;

cases					: CASE INT_CONST ':' function_body cases
						| CASE INT_CONST ':' function_body
						;

						
						
RHS						: constants {$$=$1;}
						| arith_op {$$=$1;}
						| logical_op {$$=$1;}
						| func_calls {$$=$1;}
						| impr {$$ = $1;}
						;						

						
constants				: INT_CONST {$$="int";}
						| FLOAT_CONST {$$="float";}
						| CHAR_CONST {$$="char";}
						| STR_CONST {$$="string";}
						| BOOL_CONST {$$ = "bool";}
						| LHS {$$ = $1.type;}
						;
						
						
extra_consts			: array_const{$$ = "2";}
						| graph_const{$$="graph";}
						| vect_const{$$="vect";}
						| matrix_const{$$="matrix";}
						| '{' '}'{$$="1";}
						;

array_const				: '[' val_list ']'
						| '[' ']'
						;
						
val_list				: int_list
						| float_list
						| char_list
						| bool_list
						| str_list
						;

resultant				: LHS
						| matrix_impr 
						| graph_impr
						| vect_stmt_body
						| impr
						;		
						
impr					: resultant '.' LENGTH '(' ')'{$$ = "int";}
						| resultant '.' AT '(' remove_body ')'{$$ = "0";}
						| resultant '.' TRACE '(' ')' {$$ = "int";}
						| resultant '.' STRLEN '(' ')'{$$ = "int";}
						| STRCMP '(' RHS ',' RHS ')' {$$ = "bool";}
						| resultant '.' STRCUT '(' remove_body ',' remove_body ')'{$$ = "string";}
						| STRJOIN '(' RHS ',' RHS ')'{$$ =  "string";}
						;
						
graph_impr				: resultant '.' TRAVERSAL '(' remove_body ')'{$$ = "vect";}
						| resultant '.' GRTOMATX '(' ')'{$$ = "matrix";}
						| resultant '.' SHPATH '(' remove_body ',' remove_body ')'{$$ = "vect";}
						| resultant '.' SHPATH_VAL '(' remove_body ',' remove_body ')' {$$ = "int";}
						;
						
						
matrix_impr				: MATXOP '(' matr_body ',' matr_body ')'{$$ = "matrix";}
						| resultant '.' TRANSPOSE '(' ')' {$$ = "matrix";}
						| resultant '.' MAXTOGR '(' ')' {$$ = "matrix";}
						;
						
matr_body				: RHS
						| matrix_impr
						;
						
graph_const				: '{' graph_type1 '}'
						| '{' graph_type2 '}'
						;

graph_type1				: INT_CONST ':' int_list ';' graph_type1
						| INT_CONST ':' int_list ';'
						;

graph_type2				: INT_CONST ':' weight_list ';' graph_type2
						| INT_CONST ':' weight_list ';'
						;

int_list				: INT_CONST ',' int_list
						| INT_CONST
						;

float_list				: FLOAT_CONST ',' float_list
						| FLOAT_CONST
						;

char_list				: CHAR_CONST ',' char_list
						| CHAR_CONST
						;

bool_list				: BOOL_CONST ',' bool_list
						| BOOL_CONST
						;

str_list				: STR_CONST ',' str_list
						| STR_CONST
						;

weight_list				: '(' INT_CONST ',' INT_CONST ')' ',' weight_list
						| '(' INT_CONST ',' INT_CONST ')'
						| '(' INT_CONST ',' FLOAT_CONST ')' ',' weight_list
						| '(' INT_CONST ',' FLOAT_CONST ')'
						;
						
vect_const				: '{' vect_list '}'
						;

vect_list				: constants ',' vect_list
						| constants
						| extra_consts ',' vect_list
						| extra_consts
						;
						
matrix_const			: '[' mat_list ']'
						;

int_float_list			: INT_CONST ',' int_float_list
						| FLOAT_CONST ',' int_float_list
						| INT_CONST
						| FLOAT_CONST
						;

mat_list				: '[' int_float_list ']'';' mat_list
						| '[' int_float_list ']'';'
						;
						
arith_op				: binary_op
						| unary_op
						;
						
binary_op				: ARITHOP '(' RHS ',' RHS ')' {
							if(!strcmp($3, "int") || !strcmp($3, "bool")|| !strcmp($3, "float")){
								if(!strcmp($5, "int") || !strcmp($5, "bool") || !strcmp($5, "float")){
									if(!strcmp($5, "float") || !strcmp($3, "float")) $$ = "float";
									else $$ = "int";
								}
								else{
									printf("Error: Invalid argument for arithmetic operation\n");
								}
							}
							else{
								printf("Error: Invalid argument for arithmetic operation\n");
							}
						}
						;
						
unary_op				: UNARYOP '(' RHS ')' {
							if(!strcmp($3, "int") || !strcmp($3, "bool")|| !strcmp($3, "float")){
								$$ = "int";
							}
							else{
								printf("Error: Invalid argument for arithmetic operation\n");
							}
						}
						;
						
logical_op				: '(' RHS LOGOP RHS ')' {
							if(!strcmp($2, "int") || !strcmp($2, "bool")|| !strcmp($2, "float")){
								if(!strcmp($4, "int") || !strcmp($4, "bool") || !strcmp($4, "float")){
									if(!strcmp($2, "float") || !strcmp($4, "float")) $$ = "float";
									else $$ = "int";
								}
								else{
									printf("Error: Invalid argument for arithmetic operation\n");
								}
							}
							else{
								printf("Error: Invalid argument for arithmetic operation\n");
							}
						}
						| NOT '(' RHS ')' {
							if(!strcmp($3, "int") || !strcmp($3, "bool")|| !strcmp($3, "float")){
								$$ = "int";
							}
							else{
								printf("Error: Invalid argument for arithmetic operation\n");
							}
						}
						;
						
call_stmt				: func_calls ';' {fprintf(fparse, " : CALL STATEMENT"); classIndex = -1;}
						;
						
						
						
func_calls				: call_head arguments {$$ = $1;}
						;
						
						
call_head				: CALL LHS  {
							if(classIndex == -1){
								$$ = func_symb[funcIndex].type;
								
								// restore index to -1 (to be redegined by LHS)
								funcIndex = -1;
							}
							else{
								$$ = class_symb[classIndex].func_list[funcIndex].type;
								
								// restore indices to -1 (to be redefined by LHS)
								classIndex = -1;
								funcIndex = -1;
							}
						}
						;
						
arguments				: '(' arg_list ')'
						| '(' ')'
						;
						
arg_list				: RHS ',' arg_list
						| RHS
						;

%%

/*
int main(){
	yyparse();
	return 0;
}
*/


int yyerror(const char *msg)
{
	/*
	extern int yylineno;
	printf("Parsing Failed\nLine Number: %d %s\n",yylineno,msg);
	printf( " : invalid statement");
	return 0;
	*/
	printf("Parsing Failed\nLine Number: %d, %s\n",yylineno,msg);
	fprintf(fparse, " : invalid statement");
	exit(0);
}

int main() {
 	FILE* fp = fopen("inp.txt", "r");
    yyin = fp;
    fparse = fopen("parsed.txt", "w");
 	FILE* ft = fopen("tokens.txt", "w");
 	yyout = ft;

 	yyparse();

	fclose(fparse);
 	fclose(ft);
 	fclose(fp);
 }




