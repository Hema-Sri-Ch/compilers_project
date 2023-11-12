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
	int currentFuncIndex = -1; // To be used by call statements to grab func details
	int classIndex = -1; // To be used by call statements to grab func details
	int funcIndex = -1;
	int callClassIndex=-1;
	int callFuncIndex=-1;
	int myIndex = 0; // for argument checking in function calls
	int returnStmtCount = 0; //for counting the return statements in a function
	
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
	int dummy_size = 0;
	int newArr[20];
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
	struct
	{
		int cols;
	} Cols;
}

%type<str> fdtype dtype id id_list graph_and_array_list matrix_list return_stmt RHS constants extra_consts impr matrix_impr graph_impr arith_op logical_op func_calls binary_op unary_op arg_list call_head for_RHS myId vect_append resultant vect_stmt_body remove_body int_list float_list bool_list char_list str_list val_list array_const matr_body
%type<details> function function_head func_definition LHS
%type<Cols> mat_list int_float_list

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
								printf("%d ERROR: Struct or class name already exists\n", yylineno);
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
									printf("%d ERROR: Struct or class name already exists\n", yylineno);
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
							{
								currentFuncIndex = -1; 
								if(returnStmtCount==0)	printf("%d ERROR : Expected atlease one return statement\n", yylineno);
								returnStmtCount = 0;
							}
						;
						
function_head			: func_definition Parameters { 
							$$=$1; 
							// if(inClass == 0) printFuncDetails(-1, func_size-1);
							// else printFuncDetails(class_size-1, -1); 
							fprintf(fparse, " : FUNCTION HEAD");
						}
						;


func_definition			: FUNC fdtype id {
							$$.name = $3;
							$$.type = $2;
							if(inClass == 0) {
								int i = func_search($3);
								if(i >= 0) {
									printf("%d ERROR : function name %s already declared\n", yylineno, $3);
									exit(1);
								}
								func_insert($3, $2);
								currentFuncIndex = func_size - 1;
							}
							else {
								int i = class_func_search($3, class_size-1);
								if(i >= 0) {
									printf("%d ERROR : function name %s already declared\n", yylineno, $3);
									exit(1);
								}
								class_func_insert(class_size-1, $3, $2);
								currentFuncIndex = class_symb[class_size-1].cl_func_size - 1;
							}
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
							
							
								char* myType = (char*)malloc(strlen($1)+1);
								strncpy(myType, $1 + 1, strlen($1));
								myType[strlen($1)] = '\0';
								var_insert(0, level, $2, "vect", myType, -1, -1);
								free(myType);
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
									printf("%d Error: Using undefined datatype %s\n", yylineno, $1);
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
						| return_stmt {fprintf(fparse," : RETURN STATEMENT");}
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
									printf("%d ERROR: Label name already exists\n", yylineno);
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

vect_stmt_body			: resultant '.' APPEND '(' vect_append ')' { 
							// printf("%d::Initial resultant - %s\n",yylineno, $1);
							if($1[0] != '*'){
								printf("%d Error: invalid type for clear\n", yylineno);
								exit(1);
							}
							
							else{
								char* myType = (char*)malloc(strlen($1)+1);
								strncpy(myType, $1 + 1, strlen($1));
								myType[strlen($1)] = '\0';
								if(strcmp(myType, $5)){
									int a = !strcmp(myType, "float") && (!strcmp($5, "int") || !strcmp($5, "bool"));
									int b = !strcmp(myType, "int") && (!strcmp($5, "bool"));
									int c = !strcmp(myType, "bool") && (!strcmp($5, "float") || !strcmp($5, "int") || !strcmp($5, "char") || !strcmp($5, "string"));
									if(!(a || b || c)){
										printf("%d ERROR: appending the wrong dtype; expected %s; given %s\n", yylineno, myType, $5);
										free(myType);
										exit(1);
									}
								}
								
								else{
									// printf("%d::resultant: %s; appending: %s\n", yylineno, $1, $5);
									$$ = $1;
									free(myType);
								}
							}
						}
						| resultant '.' REMOVE '(' remove_body ')' {
							// printf("%d::Initial resultant - %s\n",yylineno, $1);
							if($1[0] != '*'){
								printf("%d Error: invalid type for clear\n", yylineno);
								exit(1);
							}
							
							else{
								if(!(!strcmp("int", $5) || !strcmp("float", $5) || !strcmp("bool", $5))){
									printf("%d ERROR: providing invalid index type %s to vector remove\n", yylineno, $5);
									exit(1);
								} else {
									$$ = $1;
								}
							}
						}
						| resultant '.' SORT '(' ')' {
							// printf("%d::Initial resultant - %s\n",yylineno, $1);
							if($1[0] != '*'){
								printf("%d Error: invalid type for sort\n", yylineno);
								exit(1);
							}
							else {
								$$ = $1;
							}
						}
						| resultant '.' CLEAR '(' ')' {
							// printf("%d::Initial resultant - %s\n", yylineno, $1);
							if($1[0] != '*'){
								printf("%d Error: invalid type for clear\n", yylineno);
								exit(1);
							}
							else{
								$$ = $1;
							}
						}
						;
						
						

remove_body				: INT_CONST {$$="int";}
						| FLOAT_CONST {$$="float";}
						| LHS {$$=$1.type;}
						| func_calls {$$=$1;}
						| arith_op {$$=$1;}
						| logical_op {$$=$1;}
						| impr {$$=$1;}
						;
						
						
vect_append				: RHS {$$=$1;}
						| extra_consts {$$=$1;}
						;
						
return_stmt 			: RETURN RHS';'
							{	returnStmtCount++;
								if(inClass==0)
								{		
									if(strcmp($2,func_symb[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
								else
								{
									if(strcmp($2,class_symb[class_size-1].func_list[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
							} 				
							{fprintf(fparse, " : RETURN STATEMENT");}
						| RETURN extra_consts ';' 
						 	{	returnStmtCount++;
								if(inClass==0)
								{
									if(strcmp($2,func_symb[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n", yylineno);
									}
								}
								else
								{
									if(strcmp($2,class_symb[class_size-1].func_list[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
						 	}
							{fprintf(fparse, " : RETURN STATEMENT");}
						| RETURN graph_impr ';'
							{	returnStmtCount++;
								if(inClass==0)
								{
									if(strcmp($2,func_symb[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
								else
								{
									if(strcmp($2,class_symb[class_size-1].func_list[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
						 	} 
							{fprintf(fparse, " : RETURN STATEMENT");}
						| RETURN matrix_impr ';'
							{	returnStmtCount++;
								if(inClass==0)
								{
									if(strcmp($2,func_symb[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
								else
								{
									if(strcmp($2,class_symb[class_size-1].func_list[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
							}  
							{fprintf(fparse, " : RETURN STATEMENT");}
						| RETURN vect_stmt_body ';'
						{	returnStmtCount++;
							if(inClass==0){
								if(strcmp($2,func_symb[currentFuncIndex].type)){
									printf("%d ERROR : func type and return type are mismatched\n",yylineno);
								}
							}
							else{
								if(strcmp($2,class_symb[class_size-1].func_list[currentFuncIndex].type)){
									printf("%d ERROR : func type and return type are mismatched\n",yylineno);
								}
							}
						}
						| RETURN null ';'
							{	returnStmtCount++;
								if(inClass==0)
								{
									if(strcmp("void",func_symb[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
								else
								{
									if(strcmp("void",class_symb[class_size-1].func_list[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
							} 
							{fprintf(fparse, " : RETURN STATEMENT");}
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
									printf("%d Error: Expression statement, type mismatch\n", yylineno);
									exit(1);
								}
							}
						}
						;
						
for_RHS					: arith_op {$$ = $1;}
						| func_calls {$$ = $1;}
						| impr {$$ = "improvised";}
						| graph_impr {$$ = "improvised";}
						| vect_stmt_body {$$ = $1;}
						| matrix_impr {$$ = $1;}
						;

while_loop				: WHILE '('RHS')' {
							int a = !strcmp($3, "int") || 
									!strcmp($3, "float") || 
									!strcmp($3, "bool") ||
									!strcmp($3, "string") ||
									!strcmp($3, "char")
									;
							if(!a) {
								printf("%d Error : Invalid conditional argument\n", yylineno);
							}
						} function_body
						;
						
expr_stmt				: EXPR LHS '=' RHS ';' {
							if(strcmp($2.type, $4)){
								int a = !strcmp($2.type, "int") || !strcmp($2.type, "float") || !strcmp($2.type, "bool");
								int b = !strcmp($4, "int") || !strcmp($4, "float") || !strcmp($4, "bool");
							
								if(!(a && b)){
									printf("%d Error: Expression statement, type mismatch\n", yylineno);
									exit(1);
								}
							}
							
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
						| EXPR LHS '=' extra_consts ';'
							{
								int dimAval, dimBval;
								char* element_type;
								int ind = var_search($2.name);
								if(ind==-1) 
								{
									ind = class_declr_search($2.name, class_size-1);
									dimAval = class_symb[class_size-1].declr_list[ind].dim_A;
									dimBval = class_symb[class_size-1].declr_list[ind].dim_B;
									element_type = class_symb[class_size-1].declr_list[ind].ele_type;
								}
								else
								{
									dimAval = var_symb[ind].dim_A;
									dimBval = var_symb[ind].dim_B;
									element_type = var_symb[ind].ele_type;
								}
								 

								if(strcmp("graph", $2.type)==0)
								{
									for(int i=0; i<dummy_size; i++)
									{
										if(newArr[i]>dimAval)
										{
											printf("%d ERROR: Vertex used is not present in the graph\n", yylineno);
											exit(1);
										}
									}
									dummy_size=0;
								}
								else if(strcmp("matrix", $2.type)==0)
								{
									if(dummy_size!=dimAval) 
									{
										printf("%d ERROR: Number of rows mismatch\n", yylineno);
										exit(1);
									}
									for(int i=0; i<dummy_size; i++)
									{
										if(newArr[i]!=dimBval)
										{
											printf("%d ERROR: Number of columns mismatch\n", yylineno);
											exit(1);
										}
									}
									dummy_size=0;
								}
								else if(strcmp("array", $2.type)==0)
								{
									if(strcmp(element_type, $4)!=0 && strcmp($4, "any")!=0)
									{
										printf("%d ERROR: Element-type mismatch in array\n", yylineno);
										exit(1);
									}
									if(dummy_size!=dimAval)
									{
										printf("%d ERROR: Array length is not matching\n", yylineno);
										exit(1);
									}
									
									dummy_size=0;
								}
							}
							{fprintf(fparse, " : EXPRESSION STATEMENT");}

						| EXPR LHS '=' graph_impr ';' {
							if(strcmp($2.type, $4)){
								int a = !strcmp($2.type, "int") || !strcmp($2.type, "float") || !strcmp($2.type, "bool");
								int b = !strcmp($4, "int") || !strcmp($4, "float") || !strcmp($4, "bool");
							
								if(!(a && b)){
									printf("%d Error: Expression statement, type mismatch\n", yylineno);
									exit(1);
								}
							}
							
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
						| EXPR LHS '=' matrix_impr ';' {
							if(strcmp($2.type, $4)){
								printf("%d Error: Expression statement, type mismatch\n", yylineno);
								exit(1);
							}
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
						| EXPR LHS '=' vect_stmt_body ';' {
							if(strcmp($2.type, $4)) {
								printf("%d Error: Expression statement, type mismatch\n", yylineno);
								exit(1);
							}
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
						;
						
						
LHS						: myId {

							classIndex = -1;
							int i = var_search($1);
							int j, l;
							if(inClass) j = class_declr_search($1, class_size-1);
							else j = -1;
							int k = func_search($1);
							if(inClass) l = class_func_search($1, class_size-1);
							else l = -1;
							
							if(i<0 && j<0 && k<0 && l<0){
								printf("%d Error: Accessing undeclared identifier/function %s\n", yylineno, $1);
							}
							
							// class declare variable (class attirbute)
							if(j>=0) {
								$$.name = $1;
								if(strcmp(class_symb[class_size-1].declr_list[j].type, "vect") == 0) {
								    char* result;
									char* A = "*";
								    result = (char*)malloc(strlen(A) + strlen(class_symb[class_size-1].declr_list[j].ele_type) + 1);
								    strcpy(result, A);
								    strcat(result, class_symb[class_size-1].declr_list[j].ele_type);
										    // dataType = 2;
				   				     $$.type = result;
								}
								else {
									$$.type = class_symb[class_size-1].declr_list[j].type;
								}
								// printf("%s : %s\n", $$.name, $$.type);
								classIndex=class_size-1;
							}
							
							// declare variable
							else if(i>=0){
								$$.name = $1;
								if(!strcmp(var_symb[i].type, "vect")){
									char* result;
									char* A = "*";
									result = (char*)malloc(strlen(A) + strlen(var_symb[i].ele_type) + 1);
									strcpy(result, A);
					     	    	strcat(result, var_symb[i].ele_type);
										    // dataType = 2;
						   			$$.type = result;
								}
								else{
									$$.type = var_symb[i].type;
								}
								// printf("%s : %s\n", $$.name, $$.type);
							}
							
							// class function
							else if(l >= 0){
								$$.name = $1;
								$$.type = class_symb[class_size-1].func_list[l].type;
								classIndex = class_size-1;
								funcIndex = l;
								// printf("%s : %s\n", $$.name, $$.type);
							}
							
							// normal funciton
							else if(k >= 0){
								$$.name = $1;
								$$.type = func_symb[k].type;
								funcIndex = k;
								// printf("%s : %s\n", $$.name, $$.type);
							}
							
							// printf("%d:: LHS.name - %s; LHS.type - %s\n", yylineno, $$.name, $$.type);
							
							
						}
						| LHS ARROW myId {
							char* dType = $1.type;
							
							// check if dType is declared in struct or in class
							int i = struct_search(dType);
							if(i < 0){
								i = class_search(dType);
								if(i < 0){
									
									// item is not defined in class and struct
									printf("%d Error: Accessing undefined datatype %s\n", yylineno, dType);
									exit(1);
								}
								
								else{
									
									int j = class_declr_search($3, i);
									int k = class_func_search($3, i);
									if(j < 0 && k < 0){
										printf("%d Error: Accessing undefined function/attribute %s of class %s\n", yylineno,$3, $1.type);
										// printClassNode(class_symb[i]);
										exit(1);
									}
									
									if(j >= 0){
										$$.name = $3;
										$$.type = class_symb[i].declr_list[j].type;
										
										if(strcmp(class_symb[i].declr_list[j].type, "vect") == 0){
										    char* result;
										    char* A = "*";
										    result = (char*)malloc(strlen(A) + strlen(class_symb[i].declr_list[j].ele_type) + 1);
										    strcpy(result, A);
										    strcat(result, class_symb[i].declr_list[j].type);
										    // dataType = 2;
						   				     $$.type = result;
										}
										else {
											$$.type = class_symb[i].declr_list[j].type;	
										}
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
								// item defined in struct, now check its attributes
								int j = struct_declr_search($3, i);
								if(j < 0){
								
									// item is not attribute of this struct
									printf("%d Error: Accessing undefined attribute of struct %s\n", yylineno, $1.name);
									exit(1);
								}
								
								else{
									$$.name = $3;
									// $$.type = struct_symb[i].list[j].type;
									if(!strcmp(struct_symb[i].list[j].type, "vect")){
										char* result;
										    char* A = "*";
										    result = (char*)malloc(strlen(A) + strlen(struct_symb[i].list[j].ele_type) + 1);
										    strcpy(result, A);
										    strcat(result, struct_symb[i].list[j].ele_type);
										    // dataType = 2;
						   				     $$.type = result;
									}
									else{
										$$.type = struct_symb[i].list[j].type;
									}
								}
							}
						}
						;
						
						
myId					: id {$$=$1;}
						| id '[' RHS ']'{
							int a = !strcmp($3, "int") || !strcmp($3, "float");
							if(!a){
								printf("%d Error: invalid array index\n", yylineno);
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
										if(inClass==1 && class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										if(var_search(arr[i])!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										var_insert(1, level, arr[i], $1, "" , -1, -1);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										if(class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										add_class_declrs(arr[i], $1, 1, level, "", -1, -1);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										if(struct_declr_search(arr[i], struct_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
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
										if(inClass==1 && class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										if(var_search(arr[i])!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										var_insert(1, level, arr[i], $1, "" , dimA[i], -1);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										if(class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										add_class_declrs(arr[i], $1, 1, level, "", dimA[i], -1);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										if(struct_declr_search(arr[i], struct_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
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
										if(inClass==1 && class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										if(var_search(arr[i])!=-1)
										{
											printf("%d : Variable already declared\n", yylineno);
											exit(1);
										}
										var_insert(1, level, arr[i], $1, $3, -1, -1);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										if(class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										add_class_declrs(arr[i], $1, 1, level, $3, -1, -1);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										if(struct_declr_search(arr[i], struct_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
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
										if(inClass==1 && class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										if(var_search(arr[i])!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										var_insert(1, level, arr[i], $1, "" , dimA[i], dimB[i]);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										if(class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										add_class_declrs(arr[i], $1, 1, level, "", dimA[i], dimB[i]);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										if(struct_declr_search(arr[i], struct_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
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
										if(inClass==1 && class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										if(var_search(arr[i])!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										var_insert(1, level, arr[i], "array", $1 , dimA[i], -1);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										if(class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										add_class_declrs(arr[i], "array", 1, level, $1, dimA[i], -1);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										if(struct_declr_search(arr[i], struct_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										add_struct_declrs(arr[i], "array", 1, level, $1, dimA[i], -1);
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
											if(inClass==1 && class_declr_search(arr[i], class_size-1)!=-1)
											{
												printf("%d ERROR: Variable already declared\n", yylineno);
												exit(1);
											}
											if(var_search(arr[i])!=-1)
											{
												printf("%d ERROR: Variable already declared\n", yylineno);
												exit(1);
											}
											var_insert(1, level, arr[i], $1, "", -1, -1);
										}
									}
									else if(inClass==1)
									{
										for(int i=0; i<arr_size; i++)
										{
											if(class_declr_search(arr[i], class_size-1)!=-1)
											{
												printf("%d ERROR: Variable already declared\n", yylineno);
												exit(1);
											}
											add_class_declrs(arr[i], $1, 1, level, "", -1, -1);
										}
									}
									else
									{
										for(int i=0; i<arr_size; i++)
										{
											if(struct_declr_search(arr[i], struct_size-1)!=-1)
											{
												printf("%d ERROR: Variable already declared\n", yylineno);
												exit(1);
											}
											add_struct_declrs(arr[i], $1, 1, level, "", -1, -1);
										}
									}
									arr_size =0;
								}
								else
								{
									arr_size=0;
									printf("%d ERROR: No struct or class with that name is defined\n", yylineno);
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
									printf("%d ERROR: Dimension(s) has to be greater than 0\n", yylineno);
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
									printf("%d ERROR: Dimension(s) has to be greater than 0\n", yylineno);
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
									printf("%d ERROR: No of rows or columns has to be positive\n", yylineno);
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
									printf("%d ERROR: No of rows or columns has to be positive\n", yylineno);
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
								printf("%d Error : Invalid conditional argument\n", yylineno);
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
								printf("%d Error : Invalid conditional argument\n", yylineno);
							}
							fprintf(fparse, " : CONDITIONAL STATEMENT");
						} switch_body
						;
						

switch_body				: '{' {switch_insert(level); level++;} cases DEFAULT ':' function_body '}' { var_delete(level); level--; switch_delete();}
						;

cases					: cases CASE INT_CONST  {add_case(level-1, $3);} ':' function_body 
						| CASE INT_CONST  {add_case(level-1, $2);} ':' function_body
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
						
						
extra_consts			: array_const{$$ = $1;}
						| graph_const{$$="graph";}
						| vect_const{$$="vect";}
						| matrix_const{$$="matrix";}
						| '{' '}'{$$="1";}
						;

array_const				: '[' val_list ']'
							{
								$$ = $2;
							}
						| '[' ']'
							{
								$$ = "any";
							}
						;
						
val_list				: int_list
							{ $$ = "int";}
						| float_list
							{ $$  = "float";}
						| char_list
							{ $$ = "char";}
						| bool_list
							{ $$ = "bool";}
						| str_list
							{ $$ = "string";}
						;

resultant				: LHS{$$ = $1.type;}
						| matrix_impr {$$ = $1;}
						| graph_impr {$$ = $1;}
						| vect_stmt_body {$$ = $1;}
						| impr {$$ = $1;}
						;				
						
						
impr					: resultant '.' LENGTH '(' ')'{
							//printf("%d::Initial resultant type: %s\n",yylineno, $1);
							if($1[0] != '*'){
								printf("%d Error: invalid type for 'at'\n", yylineno);
								exit(1);
							} else {
								$$ = "int";
							}
						}
						| resultant '.' AT '(' remove_body ')'{
							//printf("%d::Initial resultant type: %s\n",yylineno, $1);
							if($1[0] != '*'){
								printf("%d Error: invalid type for 'at'\n", yylineno);
								exit(1);
							}
							else {
								if (!(!strcmp("int", $5) || !strcmp("float", $5) || !strcmp("bool", $5))){
									printf("%d ERROR: appending the wrong dtype\n", yylineno);
									exit(1);
								}
								else{
									char* myType = (char*)malloc(strlen($1)+1);
									strncpy(myType, $1 + 1, strlen($1));
									myType[strlen($1)] = '\0';
									$$ = myType;
									free(myType);
								}
							} 
							
							// printf("%d::resultant - %s, index - %s, returning - %s\n", yylineno, $1, $5, $$);
						}
						| resultant '.' TRACE '(' ')' {
							//printf("%d::Initial resultant type: %s\n",yylineno, $1);
							if(strcmp("matrix", $1)){
								printf("%d Error: invalid type for trace\n", yylineno);
								exit(1);
							}else{
								$$ = "int";
							}
						}
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
						
						
matrix_impr				: MATXOP '(' matr_body ',' matr_body ')'{if(strcmp($3,"matrix") || strcmp($5,"matrix")){
											printf("%d, ERROR : argument is not a matrix\n",yylineno);exit(1);}
											$$ = $3;}
						| resultant '.' TRANSPOSE '(' ')' {$$ = "matrix";}
						| resultant '.' MAXTOGR '(' ')' {$$ = "graph";}
						;
						
matr_body				: RHS {$$ = $1;}
						| matrix_impr {$$ = $1;}
						;
						
graph_const				: '{' graph_type1 '}'
						| '{' graph_type2 '}'
						;

graph_type1				: INT_CONST ':' int_list ';' graph_type1
							{
								newArr[dummy_size] = atoi($1);
								dummy_size++;
							}
						| INT_CONST ':' int_list ';'
							{
								newArr[dummy_size] = atoi($1);
								dummy_size++;
							}
						;

graph_type2				: INT_CONST ':' weight_list ';' graph_type2
							{
								newArr[dummy_size] = atoi($1);
								dummy_size++;
							}
						| INT_CONST ':' weight_list ';'
							{
								newArr[dummy_size] = atoi($1);
								dummy_size++;
							}
						;

int_list				: INT_CONST ',' int_list
							{
								newArr[dummy_size] = atoi($1);
								dummy_size++;
							}
							{
								$$ = "int";
							}
						| INT_CONST
							{
								newArr[dummy_size] = atoi($1);
								dummy_size++;
							}
							{
								$$ = "int";
							}
						;

float_list				: FLOAT_CONST ',' float_list
							{
								$$ = "float";
								dummy_size++;
							}
						| FLOAT_CONST
							{
								$$ = "float";
								dummy_size++;
							}
						;

char_list				: CHAR_CONST ',' char_list
							{
								$$ = "char";
								dummy_size;
							}
						| CHAR_CONST
							{
								$$ = "char";
								dummy_size++;
							}
						;

bool_list				: BOOL_CONST ',' bool_list
							{
								$$ = "bool";
								dummy_size;
							}
						| BOOL_CONST
							{
								$$ = "bool";
								dummy_size;
							}
						;

str_list				: STR_CONST ',' str_list
							{
								$$ = "string";
								dummy_size;
							}
						| STR_CONST
							{
								$$ = "string";
								dummy_size++;
							}
						;

weight_list				: '(' INT_CONST ',' INT_CONST ')' ',' weight_list
							{
								newArr[dummy_size] = atoi($2);
								dummy_size++;
							}
						| '(' INT_CONST ',' INT_CONST ')'
							{
								newArr[dummy_size] = atoi($2);
								dummy_size++;
							}
						| '(' INT_CONST ',' FLOAT_CONST ')' ',' weight_list
							{
								newArr[dummy_size] = atoi($2);
								dummy_size++;
							}
						| '(' INT_CONST ',' FLOAT_CONST ')'
							{
								newArr[dummy_size] = atoi($2);
								dummy_size++;
							}
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
							{
								$$.cols = $3.cols+1;
							}
						| FLOAT_CONST ',' int_float_list
							{
								$$.cols = $3.cols+1;
							}
						| INT_CONST
							{
								$$.cols=1;
							}
						| FLOAT_CONST
							{
								$$.cols=1;
							}
						;

mat_list				: '[' int_float_list ']'';' mat_list
							{
								newArr[dummy_size]=$2.cols;
								dummy_size++;
							}
						| '[' int_float_list ']'';'
							{
								newArr[dummy_size]=$2.cols;
								dummy_size++;
							}
							
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
									printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
								}
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
							}
						}
						;
						
unary_op				: UNARYOP '(' RHS ')' {
							if(!strcmp($3, "int") || !strcmp($3, "bool")|| !strcmp($3, "float")){
								$$ = "int";
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
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
									printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
								}
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
							}
						}
						| NOT '(' RHS ')' {
							if(!strcmp($3, "int") || !strcmp($3, "bool")|| !strcmp($3, "float")){
								$$ = "int";
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
							}
						}
						;
						
call_stmt				: func_calls ';' {fprintf(fparse, " : CALL STATEMENT"); classIndex = -1;}
						;
						
						
						
func_calls				: call_head arguments {
							$$ = $1;
							
							int num;
							if(callClassIndex == -1) num = func_symb[callFuncIndex].param_no;
							else num = class_symb[callClassIndex].func_list[callFuncIndex].param_no;
							if(myIndex < num) {
								printf("%d Error : Too few functional arguments;\n Expected number of arguments: %d;\n Provided number of arguments: %d\n", yylineno  , num, myIndex);
								exit(1);
							}
							// restore indices to -1 (to be redefined by LHS)
							callClassIndex = -1;
							callFuncIndex = -1;
							myIndex = 0;
						}
						;
						
						
call_head				: CALL LHS  {
							callClassIndex = classIndex;
							callFuncIndex = funcIndex;
							if(callClassIndex == -1){
								$$ = func_symb[callFuncIndex].type;
							}
							else{
								$$ = class_symb[callClassIndex].func_list[callFuncIndex].type;
							}
							myIndex = 0;
						}
						;
						
arguments				: '(' arg_list ')'
						| '(' ')'
						;
						
arg_list				: RHS {

							// tot size; list
							
							int maxSize;
							if(callClassIndex == -1) maxSize = func_symb[callFuncIndex].param_no;
							else maxSize = class_symb[callClassIndex].func_list[callFuncIndex].param_no;
							
							if(myIndex >= maxSize){
								printf("%d Error: Excess functional arguments for function %s\n", yylineno, func_symb[callFuncIndex].name);
								exit(1);
							}
							
							else{
								char* myType = NULL;
								if(callClassIndex == -1) {
									int k = strlen(func_symb[callFuncIndex].args[myIndex]);
									myType = (char*)malloc(k+1);
									myType = func_symb[callFuncIndex].args[myIndex];
									myType[k] = '\0';
								}
								else {
									int k = strlen(class_symb[callClassIndex].func_list[callFuncIndex].args[myIndex]);
									myType = (char*)malloc(k+1);
									myType = class_symb[callClassIndex].func_list[callFuncIndex].args[myIndex];
									myType[k]='\0';
								}
								
								if(strcmp(myType, $1)){
									// type mismatched. Now check if it is ignorable or not
									int a = !strcmp(myType, "int") || !strcmp(myType, "float") || !strcmp(myType, "bool");
									int b = !strcmp($1, "int") || !strcmp($1, "float") || !strcmp($1, "bool");
									
									if(!(a && b)){
										printf("%d Error: for argument-%d expected argument type: %s, given argument type %s\n", yylineno, myIndex+1, myType, $1);
										free(myType);
										exit(1);
									}
									
									else {
										myIndex++;
										free(myType);
									}
								}
								
								else myIndex++;
								free(myType);
								
							}
						}
						| arg_list ',' RHS {
							int maxSize;
							if(callClassIndex == -1) maxSize = func_symb[callFuncIndex].param_no;
							else maxSize = class_symb[callClassIndex].func_list[callFuncIndex].param_no;
							
							if(myIndex >= maxSize){
								printf("%d Error: Excess functional arguments for function %s\n", yylineno, func_symb[callFuncIndex].name);
								exit(1);
							}
							
							else{
								char* myType;
								if(callClassIndex == -1) {
									int k = strlen(func_symb[callFuncIndex].args[myIndex]);
									myType = (char*)malloc(k+1);
									myType = func_symb[callFuncIndex].args[myIndex];
									myType[k] = '\0';
								}
								else {
									int k = strlen(class_symb[callClassIndex].func_list[callFuncIndex].args[myIndex]);
									myType = (char*)malloc(k+1);
									myType = class_symb[callClassIndex].func_list[callFuncIndex].args[myIndex];
									myType[k]='\0';
								}
								
								if(strcmp(myType, $3)){
									// type mismatched. Now check if it is ignorable or not
									int a = !strcmp(myType, "int") || !strcmp(myType, "float") || !strcmp(myType, "bool");
									int b = !strcmp($3, "int") || !strcmp($3, "float") || !strcmp($3, "bool");
									
									if(!(a && b)){
										printf("%d Error: for argument-%d expected argument type: %s, given argument type %s\n", yylineno, myIndex, myType, $3);
										free(myType);
										exit(1);
									}
									
									else myIndex++;
								}
								
								else myIndex++;
								free(myType);
							}
						}
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
 	FILE* fp = fopen("inp.vgm", "r");
    yyin = fp;
    fparse = fopen("parsed.txt", "w");
 	FILE* ft = fopen("tokens.txt", "w");
 	yyout = ft;

 	yyparse();

	fclose(fparse);
 	fclose(ft);
 	fclose(fp);
 }




