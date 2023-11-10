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

%type<str> fdtype dtype id param_list id_list graph_and_array_list matrix_list RHS constants arith_op logical_op func_calls binary_op unary_op arg_list call_head
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
							class_insert($2);
						} class_items '}' {level--; inClass = 0;} ';' {fprintf(fparse, " : CLASS DEFINITION");}
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
						
struct					: STRUCT id '{'{level++; struct_insert($2);} struct_items '}' {level--;}';' {fprintf(fparse, " : STRUCT DEFINITION");}
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
							funcIndex = func_size-1;
						}
						;
						
Parameters				: '(' ')'
						| '(' {level++;} param_list ')'{level--;}
						;
						
						
fdtype					: dtype {$$ = $1;}
						| VOID {$$ = $1;}
						;
						
param_list				: dtype id ',' param_list {
							if(inClass == 0) add_args($1);
							else class_add_args(class_size-1, $1); 
							var_insert(0, level, $2, $1, "", -1, -1);	
						}
						| dtype id {
							if(inClass == 0) add_args($1);
							else class_add_args(class_size-1, $1); 
							var_insert(0, level, $2, $1, "", -1, -1);
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
						
function_body			: '{' { level++; } statements '}' {var_delete(); level--;}
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
						
label_stmt				: id ':' function_body {fprintf(fparse, " : LABEL");}
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

return_stmt 			: RETURN RHS';' {fprintf(fparse, " : RETURN STATEMENT");}
						| RETURN extra_consts ';' {fprintf(fparse, " : RETURN STATEMENT");}
						| RETURN graph_impr ';' {fprintf(fparse, " : RETURN STATEMENT");}
						| RETURN matrix_impr ';' {fprintf(fparse, " : RETURN STATEMENT");}
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
						| EXPR LHS '=' arith_op 
						| EXPR LHS '=' func_calls
						| EXPR LHS '=' impr
						| EXPR LHS '=' graph_impr
						| EXPR LHS '=' vect_stmt_body
						| EXPR LHS '=' matrix_impr
						;

while_loop				: WHILE '('RHS')' function_body
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
						
LHS						: id {
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
						| LHS ARROW id {
							char* dType = var_symb[var_search($1.name)].type;
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
										currentFuncIndex = k;
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
								arr_size++;
							}
						| id '[' INT_CONST ']'
							{
								arr[arr_size] = $1;
								dimA[arr_size] = atoi($3);
								arr_size++;
							}
						;

matrix_list				: id '[' INT_CONST ']' '[' INT_CONST ']' ',' matrix_list
							{
								arr[arr_size] = $1;
								dimA[arr_size] = atoi($3);
								dimB[arr_size] = atoi($6);
								arr_size++;
							}
						| id '[' INT_CONST ']' '[' INT_CONST ']'
							{
								arr[arr_size] = $1;
								dimA[arr_size] = atoi($3);
								dimB[arr_size] = atoi($6);
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

ifcond_stmt				: IF '(' RHS ')' {fprintf(fparse, " : CONDITIONAL STATEMENT");} if_body
						;

if_body					: function_body ELSE function_body
						| function_body
						;

switch_stmt				: SWITCH '(' RHS ')' {fprintf(fparse, " : CONDITIONAL STATEMENT");} switch_body
						;

switch_body				: '{' {level++;} cases DEFAULT ':' function_body '}' {level--;}
						;

cases					: CASE INT_CONST ':' function_body cases
						| CASE INT_CONST ':' function_body
						;

						
RHS						: constants {$$=$1;}
						| arith_op {$$=$1;}
						| logical_op {$$=$1;}
						| func_calls {$$=$1;}
						| impr {$$ = "improvised";}
						;						

						
constants				: INT_CONST {$$="int";}
						| FLOAT_CONST {$$="float";}
						| CHAR_CONST {$$="char";}
						| STR_CONST {$$="string";}
						| BOOL_CONST {$$ = "bool";}
						| LHS {$$ = $1.type;}
						;
						
						
extra_consts			: array_const
						| graph_const
						| vect_const
						| matrix_const
						| '{' '}'
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
						
impr					: resultant '.' LENGTH '(' ')'
						| resultant '.' AT '(' remove_body ')'
						| resultant '.' TRACE '(' ')'
						| resultant '.' STRLEN '(' ')'
						| STRCMP '(' RHS ',' RHS ')'
						| resultant '.' STRCUT '(' remove_body ',' remove_body ')'
						| STRJOIN '(' RHS ',' RHS ')'
						;
						

						
graph_impr				: resultant '.' TRAVERSAL '(' remove_body ')'
						| resultant '.' GRTOMATX '(' ')'
						| resultant '.' SHPATH '(' remove_body ',' remove_body ')'
						| resultant '.' SHPATH_VAL '(' remove_body ',' remove_body ')'
						;
						
						
matrix_impr				: MATXOP '(' matr_body ',' matr_body ')'
						| resultant '.' TRANSPOSE '(' ')' 
						| resultant '.' MAXTOGR '(' ')'
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
								$$ = func_symb[currentFuncIndex].type;
							}
							else{
								$$ = class_symb[classIndex].func_list[currentFuncIndex].type;
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




