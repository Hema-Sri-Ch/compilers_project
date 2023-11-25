%{
	#include<stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "symbol_table.c"
	extern int yylineno;
	extern FILE* yyin, *yyout;
    FILE* fparse;
    FILE* fIR;
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
	char* LeftName;
	int arr_size=0;
	int dimA[20];
	int dimB[20];
	int dummy_size = 0;
	int newArr[20];
	/*
		MY ASSUMPTIONS:
			--> if it is parameter, only type check is feasible, but no attibute check non-standard datatypes
	*/
	
	void printTabs(){
		for(int i=0; i<level; i++){
			fprintf(fIR, "\t");
		}
	}
	
	
	int* splitStringToIntArray(const char* input, int* size) {
    	// Count the number of integers in the string
    	*size = 1; // At least one integer
    		for (const char* c = input; *c != '\0'; ++c) {
    	    if (*c == ',') {
    	        (*size)++;
    	    }
    	}
	
    	// Allocate memory for the integer array
    		int* result = (int*)malloc(*size * sizeof(int));
    	if (result == NULL) {
    	    // Memory allocation failure
    	    *size = 0;
    	    return NULL;
    		}
	
    	// Tokenize the string and convert tokens to integers
    	const char* delimiter = ", ";
    	char* token = strtok((char*)input, delimiter);
    	int i = 0;
	
    	while (token != NULL) {
    	    result[i++] = atoi(token);
    	    token = strtok(NULL, delimiter);
    	}

    	return result;
	}
	
	char** splitString(const char* input, const char* delimiter, size_t* count) {
    // Count the number of elements
    *count = 1; // at least one element even if the string is empty
    for (const char* c = input; *c != '\0'; ++c) {
        if (*c == delimiter[0]) {
            (*count)++;
        }
    }

    // Allocate memory for the array of strings
    char** result = (char**)malloc(*count * sizeof(char*));
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Copy and tokenize the input string
    char* inputCopy = strdup(input); // Duplicate the input string
    char* token = strtok(inputCopy, delimiter);
    size_t i = 0;

    while (token != NULL) {
        result[i] = strdup(token); // Duplicate the token
        token = strtok(NULL, delimiter);
        i++;
    }

    free(inputCopy); // Free the duplicated input string

    return result;
}

void freeStringArray(char** array, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        free(array[i]);
    }
    free(array);
}
%}

%union{
	char* str;
	struct{
		char* str;
		char* text;
	} Str;
	struct{
		char* text;
		char* name;
		char* type;
	} details;
	struct{
		char* text;
		char* name;
		char* type;
		char* eleType;
		int dimA;
		int dimB;
	} Details;
	struct
	{
		int cols;
		char* text;
	} Cols;
}

%type<Str> fdtype dtype id id_list graph_and_array_list matrix_list return_stmt RHS constants extra_consts impr matrix_impr graph_impr arith_op logical_op func_calls binary_op unary_op arg_list call_head for_RHS myId vect_append resultant vect_stmt_body remove_body int_list float_list bool_list char_list str_list val_list array_const matr_body param param_list Parameters arguments vect_list vect_item vect_const weight_list matrix_const print_body print_constants graph_const graph_type1 graph_type2
%type<details> function function_head func_definition
%type<Cols> mat_list int_float_list
%type<Details> LHS

%token <str> newid
%token <str> INT_CONST
%token <str> FLOAT_CONST
%token <str> CHAR_CONST
%token <str> STR_CONST
%token <str> BOOL_CONST
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
%token <str> LOGOP
%token <str> ARITHOP
%token NOT
%token <str> UNARYOP
%token DECLR
%token EXPR
%token CALL
%token FUNC
%token LOOP
%token null
%token FOR
%token WHILE
%token <str> GETVAL
%token <str> ADJNODE
%token <str> PRINTMATX
%token <str> PRINTARRAY
%token <str> PRINTVECT
%token <str> PRINTGRAPH
%token <str> ADDVAL
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
%token PRINT

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
							if(class_search($2.str)!=-1 || struct_search($2.str)!=-1)
							{
								printf("%d ERROR: Struct or class name already exists\n", yylineno);
								exit(1);
							}
								
							else class_insert($2.str);
							
							fprintf(fIR, "class %s {\npublic:", $2.text);
							
						} class_items '}' { var_delete(level); level--; inClass = 0; fprintf(fIR, "};\n");} ';' {fprintf(fparse, " : CLASS DEFINITION");}
						;

id						: newid {$$.str=$1; $$.text=$1;}
						| APPEND {$$.str=$1; $$.text=$1;}
						| REMOVE {$$.str=$1; $$.text=$1;}
						| LENGTH {$$.str=$1; $$.text=$1;}
						| SORT {$$.str=$1; $$.text=$1;}
						| CLEAR {$$.str=$1; $$.text=$1;}
						| AT {$$.str=$1; $$.text=$1;}
						| TRANSPOSE {$$.str=$1; $$.text=$1;}
						| TRACE {$$.str=$1; $$.text=$1;}
						| TRAVERSAL {$$.str=$1; $$.text=$1;}
						| STRLEN {$$.str=$1; $$.text=$1;}
						| STRCUT {$$.str=$1; $$.text=$1;}
						| STRJOIN {$$.str=$1; $$.text=$1;}
						| STRCMP {$$.str=$1; $$.text=$1;}
						| MAXTOGR {$$.str=$1; $$.text=$1;}
						| GRTOMATX {$$.str=$1; $$.text=$1;}
						| SHPATH {$$.str=$1; $$.text=$1;}
						| SHPATH_VAL {$$.str=$1; $$.text=$1;}
						| ADDVAL {$$.str=$1; $$.text=$1;}
						| GETVAL {$$.str=$1; $$.text=$1;}
						;
						
class_items				: class_item {fprintf(fIR, "\n");}class_items
						| class_item {fprintf(fIR, "\n");}
						;
						
class_item				: declr_stmt
						| function 
						;
						
struct					: STRUCT id '{'
							{
								level++; 
								if(class_search($2.str)!=-1 || struct_search($2.str)!=-1)
								{
									printf("%d ERROR: Struct or class name already exists\n", yylineno);
									exit(1);
								}
								
								else struct_insert($2.str);
								fprintf(fIR, "struct %s {\n", $2.text);
								inStruct = 1;
							} 
							struct_items '}' { var_delete(level); level--; fprintf(fIR, "};\n"); inStruct = 0;}';' {fprintf(fparse, " : STRUCT DEFINITION");}
						;
						
struct_items			: declr_stmt {fprintf(fIR, "\n");} struct_items
						| declr_stmt {fprintf(fIR, "\n");}
						;
						
function				: function_head function_body 
							{
								currentFuncIndex = -1; 
								if(returnStmtCount==0)	printf("%d ERROR : Expected atlease one return statement\n", yylineno);
								returnStmtCount = 0;
								var_delete(level);
								level--;
							}
						;
						
function_head			: func_definition Parameters { 
							$$=$1; 
							// if(inClass == 0) printFuncDetails(-1, func_size-1);
							// else printFuncDetails(class_size-1, -1); 
							fprintf(fparse, " : FUNCTION HEAD");
//							fprintf(fIR, ")\n");
						}
						;


func_definition			: FUNC fdtype id {
							$$.name = $3.str;
							$$.type = $2.str;
							if(inClass == 0) {
								int i = func_search($3.str);
								if(i >= 0) {
									printf("%d ERROR : function name %s already declared\n", yylineno, $3.str);
									exit(1);
								}
								func_insert($3.str, $2.str);
								currentFuncIndex = func_size - 1;
							}
							else {
								int i = class_func_search($3.str, class_size-1);
								if(i >= 0) {
									printf("%d ERROR : function name %s already declared\n", yylineno, $3.str);
									exit(1);
								}
								class_func_insert(class_size-1, $3.str, $2.str);
								currentFuncIndex = class_symb[class_size-1].cl_func_size - 1;
							}
							
							printTabs();
							fprintf(fIR, "%s %s ", $2.text, $3.text);
							level++;
						}
						;
						
Parameters				: '(' ')' {fprintf(fIR, "()\n");}
						| '(' param_list ')' {fprintf(fIR, "( %s )\n", $2.text);}
						;
						
						
fdtype					: dtype {$$.str = $1.str; $$.text = $1.text;}
						| VOID {$$.str = $1; $$.text = $1;}
						;
						
						
param_list				: param_list ',' param {
							char* myText = (char*)malloc(strlen($1.text)+strlen($3.text)+strlen(", ")+1);
							strcpy(myText, $1.text);
							strcat(myText, ", ");
							strcat(myText, $3.text);
							$$.text = myText;
//							free(myText);
						}
						| param{$$.text = $1.text;}
						;
						
						
param					: dtype id {
							char* myText = (char*)malloc(strlen($1.text)+strlen($2.text)+2);
							strcpy(myText, $1.text);
							strcat(myText, " ");
							strcat(myText, $2.text);
							$$.text = myText;
//							free(myText);
							// fprintf(fIR, "%s %s ", $1.text, $2.text);
							if(inClass == 0) add_args($1.str);
							else class_add_args(class_size-1, $1.str);
							if(dataType == 0) var_insert(0, level, $2.str, $1.str, "", -1, -1);
							else if(dataType == 2){
							
							
								char* myType = (char*)malloc(strlen($1.str)+1);
								strncpy(myType, $1.str + 1, strlen($1.str));
								myType[strlen($1.str)] = '\0';
								var_insert(0, level, $2.str, "vect", myType, -1, -1);
								free(myType);
							}
							else if(dataType == 3) {
								var_insert(0, level, $2.str, "matrix", "", -1, -1);
								$$.text = "matrix";
							}
							else if(dataType == 4) {
								var_insert(0, level, $2.str, "graph", "", -1, -1);
								$$.text = "graph";
							}
							else if(dataType == 5){
								var_insert(0, level, $2.str, $1.str, "", -1, -1);
								char* myText = (char*)malloc(strlen($1.text)+strlen($2.text)+1);
								
								strcpy(myText, $1.text);
								strcat(myText, " ");
								strcat(myText, $2.text);
								$$.text = myText;
							}
							else if(dataType == 6) {
								var_insert(0, level, $2.str, $1.str, "", -1, -1);
								char* myText = (char*)malloc(strlen($1.text)+strlen($2.text)+1);
							
								strcpy(myText, $1.text);
								strcat(myText, " ");
								strcat(myText, $2.text);
								$$.text = myText;
							}
							

						}
						| dtype id '[' ']' {
							var_insert(0, level, $2.str, "array", $1.str, -1, -1);
							char* myText = (char*)malloc(strlen($1.text)+strlen($2.text)+4);
							strcpy(myText, $1.text);
							strcat(myText, " ");
							strcat(myText, $2.text);
							char* A = "[]";
							strcat(myText, A);
							$$.text = myText;
						}
						;
						
						
						
dtype					: DATATYPE {$$.str = $1; $$.text=$1; dataType = 0;}
						| MATRIX {$$.str = $1; dataType = 3; $$.text = "matrix";}
						| GRAPH {$$.str = $1; dataType = 4; $$.text = "graph";}
						| VECT '<' dtype '>' { 
							char* result;
							char* A = "*";
						    result = (char*)malloc(strlen(A) + strlen($3.str) + 1);
						    strcpy(result, A);
						    strcat(result, $3.str);
						    dataType = 2;
						    $$.str = result;
						    
						    
						    char* myText = (char*)malloc(strlen("vector<>")+strlen($3.text)+1);
						    char* B = "vector<";
						    strcpy(myText, B);
						    strcat(myText, $3.text);
						    strcat(myText, ">");
						    $$.text = myText;
//						    free(result);
//						    free(myText);
						}
						| id {
							int i = struct_search($1.str);
							if(i < 0) {
								i = class_search($1.str);
								if(i < 0){
									printf("%d Error: Using undefined datatype %s\n", yylineno, $1.str);
								}
								else{
									dataType = 6;
									$$.str = $1.str;
									char* myText = (char*)malloc(strlen("class ")+strlen($1.text)+1);
									strcpy(myText, "class ");
									strcat(myText, $1.text);
									$$.text = myText;
								}
							}
							else{
								dataType = 5;
								$$.str = $1.str;
								char* myText = (char*)malloc(strlen("struct ")+strlen($1.text)+1);
								strcpy(myText, "struct ");
								strcat(myText, $1.text);
								$$.text = myText;
							}
						}
						;
						
function_body			: '{' {printTabs(); level++; fprintf(fIR, "{\n");} statements '}' {var_delete(level); level--; printTabs(); fprintf(fIR, "}\n");}
						| '{' '}' { printTabs(); fprintf(fIR, "{ }\n");}
						;
						
statements				: statement {fprintf(fIR, "\n");} statements
						| statement {fprintf(fIR, "\n");}
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
						| print_stmt
						| independent_funcs ';'
						;
						
independent_funcs		: resultant '.' ADDVAL '(' remove_body ',' remove_body ',' remove_body ')' {
							if(strcmp($1.str, "matrix")){
								printf("%d Error: Only matrix can call addVal function\n", yylineno);
								exit(1);
							}
							
							int a = !strcmp($5.str, "int");
							int b = !strcmp($7.str, "int");
							int c = !strcmp($9.str, "int") || !strcmp($9.str, "float") || !strcmp($9.str, "bool");
							
							if(!(a && b && c)){
								printf("%d Error: Invalid argument types for addVal function\n", yylineno);
								exit(1);
							}
							
							printTabs();
							fprintf(fIR, "%s.addValue(%s, %s, %s);\n", $1.text, $5.text, $7.text, $9.text);
						}
						| resultant '.' PRINTMATX '(' ')' {
							if(strcmp($1.str, "matrix")){
								printf("%d Error: Only matrix can call printMatrix function\n", yylineno);
								exit(1);
							}
							
							printTabs();
							fprintf(fIR, "%s.printMatrix();\n", $1.text);
						}
						| resultant '.' PRINTGRAPH '(' ')' {
							if(strcmp($1.str, "graph")){
								printf("%d Error: Only graph can call printGraph function\n", yylineno);
								exit(1);
							}
							
							printTabs();
							fprintf(fIR, "%s.printGraph();\n", $1.text);
						}
						| PRINTARRAY '(' resultant ')' {
							if($3.text[0] == '#'){
								printf("%d Error: Invalid argument for printArray function\n", yylineno);
								exit(1);
							}
							
							printTabs();
							fprintf(fIR, "printArray(%s);\n", $3.text);
						}
						| PRINTVECT '(' resultant ')' {
							if($3.str[0] != '*'){
								printf("%d Error: Invalid argument for printVect function\n", yylineno);
								exit(1);
							}
							
							printTabs();
							fprintf(fIR, "printVect(%s);\n", $3.text);
						}
						;
						
						

print_stmt				: PRINT '(' print_body ')' ';'
						 {
							fprintf(fparse, " : PRINT STATEMENT");
							printTabs();
							fprintf(fIR, "cout << %s << endl;", $3.text);
							
						 }
						;

print_body				: print_body ',' print_constants
							{
								char* myText = (char*)malloc(strlen($1.text)+strlen($3.text)+3);
								strcpy(myText, $1.text);
								strcat(myText, " << ");
								strcat(myText, $3.text);
								$$.text = myText;
							}
						| print_constants
							{
								$$.text = $1.text;
							}
						;

print_constants			: constants {
							int a = !(strcmp($1.str, "int")) || !(strcmp($1.str, "float")) || !(strcmp($1.str, "char")) || !(strcmp($1.str, "string")) || !(strcmp($1.str, "bool"));

							if(!a){
								printf("%d Error: Invalid argument as print object\n", yylineno);
								exit(1);
							}
							$$.text = $1.text;
						}
						| extra_consts {
							char* myText = (char*)malloc(strlen($1.text)+3);
							strcpy(myText, "\"");
							strcat(myText, $1.text);
							strcat(myText, "\"");
							$$.text = myText;
						}
						;
						
unary_stmt				: unary_op ';' {fprintf(fparse, " : UNARY STATEMENT"); printTabs(); fprintf(fIR, "%s;", $1.text);}
						;
						
jump_stmt				: label_stmt
						| goto_stmt
						;
						
label_stmt				: id 
							{
								if(label_search($1.str)!=-1) 
								{
									printf("%d ERROR: Label name already exists\n", yylineno);
									exit(1);
								}
								else label_insert($1.str);
								
								printTabs();
								fprintf(fIR, "%s: ", $1.text);
							}
							':' function_body {fprintf(fparse, " : LABEL");}
						;
						
goto_stmt				: GOTO id ';' {fprintf(fparse, " : GOTO STATEMENT"); printTabs(); fprintf(fIR, "goto %s;", $2.text);}
						;

vect_stmt				: vect_stmt_body ';' {fprintf(fparse, " : INDEPENDENT METHOD");}
						;

vect_stmt_body			: resultant  '.' APPEND '(' vect_append ')' { 
							// printf("%d::Initial resultant - %s\n",yylineno, $1);
							if($1.str[0] != '*'){
								printf("%d Error: invalid type for clear\n", yylineno);
								exit(1);
							}
							
							else{
								char* myType = (char*)malloc(strlen($1.str)+1);
								strncpy(myType, $1.str + 1, strlen($1.str));
								myType[strlen($1.str)] = '\0';
								if(strcmp(myType, $5.str)){
									int a = !strcmp(myType, "float") && (!strcmp($5.str, "int") || !strcmp($5.str, "bool"));
									int b = !strcmp(myType, "int") && (!strcmp($5.str, "bool"));
									int c = !strcmp(myType, "bool") && (!strcmp($5.str, "float") || !strcmp($5.str, "int") || !strcmp($5.str, "char") || !strcmp($5.str, "string"));
									if(!(a || b || c)){
										printf("%d ERROR: appending the wrong dtype; expected %s; given %s\n", yylineno, myType, $5.str);
										free(myType);
										exit(1);
									}
								}
								
								else{
									// printf("%d::resultant: %s; appending: %s\n", yylineno, $1, $5);
									$$.str = $1.str;
									
								}
								
								char* myText = (char*)malloc(256);
								strcpy(myText, "{vector<");
								strcat(myText, myType);
								strcat(myText, "> temp = ");
								strcat(myText, $1.text);
								strcat(myText, ";temp.push_back(");
								strcat(myText, $5.text);
								strcat(myText, ");");
								strcat(myText, $1.text);
								strcat(myText, " = temp;}");
								printTabs();
								fprintf(fIR, "%s\n", myText);
								$$.text = $1.text;
								
								free(myType);
								free(myText);
							}
							
						}
						| resultant '.' REMOVE '(' remove_body ')' {
							// printf("%d::Initial resultant - %s\n",yylineno, $1);
							if($1.str[0] != '*'){
								printf("%d Error: invalid type for clear\n", yylineno);
								exit(1);
							}
							
							else{
								if(!(!strcmp("int", $5.str) || !strcmp("float", $5.str) || !strcmp("bool", $5.str))){
									printf("%d ERROR: providing invalid index type %s to vector remove\n", yylineno, $5.str);
									exit(1);
								} else {
									$$.str = $1.str;
									
									char* myType = (char*)malloc(strlen($1.str)+1);
									strncpy(myType, $1.str + 1, strlen($1.str));
									myType[strlen($1.str)] = '\0';
								
								
									char* myText = (char*)malloc(512);
									strcpy(myText, "{vector<");
									strcat(myText, myType);
									strcat(myText, "> temp = ");
									strcat(myText, $1.text);
									strcat(myText, ";temp.erase(temp.begin()+");
									strcat(myText, $5.text);
									strcat(myText, ");");
									strcat(myText, $1.text);
									strcat(myText, " = temp;}");
									printTabs();
									fprintf(fIR, "%s\n", myText);
									$$.text = $1.text;
									
									free(myType);
									free(myText);
								}
							}
						}
						| resultant '.' SORT '(' ')' {
							// printf("%d::Initial resultant - %s\n",yylineno, $1);
							if($1.str[0] != '*'){
								printf("%d Error: invalid type for sort\n", yylineno);
								exit(1);
							}
							else {
								$$.str = $1.str;
								
								char* myType = (char*)malloc(strlen($1.str)+1);
								strncpy(myType, $1.str + 1, strlen($1.str));
								myType[strlen($1.str)] = '\0';
								
								
								char* myText = (char*)malloc(256);
								strcpy(myText, "{vector<");
								strcat(myText, myType);
								strcat(myText, "> temp = ");
								strcat(myText, $1.text);
								strcat(myText, ";sort(temp.begin(), temp.end());");
								strcat(myText, $1.text);
								strcat(myText, " = temp;}");
								printTabs();
								fprintf(fIR, "%s\n", myText);
								$$.text = $1.text;
								
								free(myType);
								free(myText);
							}
						}
						| resultant '.' CLEAR '(' ')' {
							// printf("%d::Initial resultant - %s\n", yylineno, $1);
							if($1.str[0] != '*'){
								printf("%d Error: invalid type for clear\n", yylineno);
								exit(1);
							}
							else{
								$$.str = $1.str;
								
								char* myType = (char*)malloc(strlen($1.str)+1);
								strncpy(myType, $1.str + 1, strlen($1.str));
								myType[strlen($1.str)] = '\0';
								
								
								char* myText = (char*)malloc(256);
								strcpy(myText, "{vector<");
								strcat(myText, myType);
								strcat(myText, "> temp = ");
								strcat(myText, $1.text);
								strcat(myText, ";temp.clear();");
								strcat(myText, $1.text);
								strcat(myText, " = temp;}");
								printTabs();
								fprintf(fIR, "%s\n", myText);
								$$.text = $1.text;
								
								free(myType);
								free(myText);
							}
						}
						;
						
						
remove_body				: INT_CONST {$$.str="int"; $$.text = $1;}
						| FLOAT_CONST {$$.str="float"; $$.text = $1;}
						| LHS {$$.str=$1.type; $$.text = $1.text;}
						| func_calls {$$.str=$1.str; $$.text = $1.text;}
						| arith_op {$$.str=$1.str; $$.text = $1.text;}
						| logical_op {$$.str=$1.str; $$.text = $1.text;}
						| impr {$$.str=$1.str; $$.text = $1.text;}
						;
						
						
vect_append				: RHS {$$.str=$1.str; $$.text = $1.text;}
						| extra_consts {$$.str=$1.str; $$.text = $1.text;}
						;
						
						
return_stmt 			: RETURN RHS';'
							{	returnStmtCount++;
							
								if(inClass == 0){
									char* A = $2.str;
									char* B = func_symb[currentFuncIndex].type;
									
									if(strcmp(A, B)){
										int a = !strcmp(A, "int") || !strcmp(A, "float") || !strcmp(A, "bool");
										int b = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool");
										
										int c = !strcmp(A, "bool");
										int d = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool") || !strcmp(B, "char") || !strcmp(B, "string");
										
										if(!(a&&b  ||  c&&d) ){
											printf("%d Warning: return type mismatched\n", yylineno);
										}
									}
								}
								
								else {
									char* A = $2.str;
									char* B = class_symb[class_size-1].func_list[currentFuncIndex].type;
									
									if(strcmp(A, B)){
										int a = !strcmp(A, "int") || !strcmp(A, "float") || !strcmp(A, "bool");
										int b = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool");
										
										int c = !strcmp(A, "bool");
										int d = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool") || !strcmp(B, "char") || !strcmp(B, "string");
										
										if(!(a&&b  ||  c&&d) ){
											printf("%d Warning: return type mismatched\n", yylineno);
										}
									}
								
								}
								printTabs();
								fprintf(fIR, "return %s;", $2.text);
							
							/*	if(inClass==0)
								{		
									if(strcmp($2.str,func_symb[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
								else
								{
									if(strcmp($2.str,class_symb[class_size-1].func_list[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}*/
							} 				
							{fprintf(fparse, " : RETURN STATEMENT");}
						| RETURN extra_consts ';' 
						 	{	returnStmtCount++;
								if(inClass==0)
								{
									if(strcmp($2.str,func_symb[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n", yylineno);
									}
								}
								else
								{
									if(strcmp($2.str,class_symb[class_size-1].func_list[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
								
								printTabs();
								fprintf(fIR, "return %s;", $2.text);
						 	}
							{fprintf(fparse, " : RETURN STATEMENT");}
						| RETURN graph_impr ';'
							{	returnStmtCount++;
								if(inClass == 0){
									char* A = $2.str;
									char* B = func_symb[currentFuncIndex].type;
									
									if(strcmp(A, B)){
										int a = !strcmp(A, "int") || !strcmp(A, "float") || !strcmp(A, "bool");
										int b = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool");
										
										int c = !strcmp(A, "bool");
										int d = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool") || !strcmp(B, "char") || !strcmp(B, "string");
										
										if(!(a&&b  ||  c&&d) ){
											printf("%d Warning: return type mismatched\n", yylineno);
										}
									}
								}
								
								else {
									char* A = $2.str;
									char* B = class_symb[class_size-1].func_list[currentFuncIndex].type;
									
									if(strcmp(A, B)){
										int a = !strcmp(A, "int") || !strcmp(A, "float") || !strcmp(A, "bool");
										int b = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool");
										
										int c = !strcmp(A, "bool");
										int d = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool") || !strcmp(B, "char") || !strcmp(B, "string");
										
										if(!(a&&b  ||  c&&d) ){
											printf("%d Warning: return type mismatched\n", yylineno);
										}
									}
								}
								
								printTabs();
								fprintf(fIR, "return %s;", $2.text);
						 	} 
							{fprintf(fparse, " : RETURN STATEMENT");}
						| RETURN matrix_impr ';'
							{	returnStmtCount++;
								if(inClass == 0){
									char* A = $2.str;
									char* B = func_symb[currentFuncIndex].type;
									
									if(strcmp(A, B)){
										int a = !strcmp(A, "int") || !strcmp(A, "float") || !strcmp(A, "bool");
										int b = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool");
										
										int c = !strcmp(A, "bool");
										int d = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool") || !strcmp(B, "char") || !strcmp(B, "string");
										
										if(!(a&&b  ||  c&&d) ){
											printf("%d Warning: return type mismatched\n", yylineno);
										}
									}
								}
								
								else {
									char* A = $2.str;
									char* B = class_symb[class_size-1].func_list[currentFuncIndex].type;
									
									if(strcmp(A, B)){
										int a = !strcmp(A, "int") || !strcmp(A, "float") || !strcmp(A, "bool");
										int b = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool");
										
										int c = !strcmp(A, "bool");
										int d = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool") || !strcmp(B, "char") || !strcmp(B, "string");
										
										if(!(a&&b  ||  c&&d) ){
											printf("%d Warning: return type mismatched\n", yylineno);
										}
									}
								}
								printTabs();
								fprintf(fIR, "return %s;", $2.text);
							}  
							{fprintf(fparse, " : RETURN STATEMENT");}
						| RETURN vect_stmt_body ';'
						{	returnStmtCount++;
							if(inClass == 0){
									char* A = $2.str;
									char* B = func_symb[currentFuncIndex].type;
									
									if(strcmp(A, B)){
										int a = !strcmp(A, "int") || !strcmp(A, "float") || !strcmp(A, "bool");
										int b = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool");
										
										int c = !strcmp(A, "bool");
										int d = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool") || !strcmp(B, "char") || !strcmp(B, "string");
										
										if(!(a&&b  ||  c&&d) ){
											printf("%d Warning: return type mismatched\n", yylineno);
										}
									}
								}
								
								else {
									char* A = $2.str;
									char* B = class_symb[class_size-1].func_list[currentFuncIndex].type;
									
									if(strcmp(A, B)){
										int a = !strcmp(A, "int") || !strcmp(A, "float") || !strcmp(A, "bool");
										int b = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool");
										
										int c = !strcmp(A, "bool");
										int d = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool") || !strcmp(B, "char") || !strcmp(B, "string");
										
										if(!(a&&b  ||  c&&d) ){
											printf("%d Warning: return type mismatched\n", yylineno);
										}
									}
								}
								
								printTabs();
								fprintf(fIR, "return %s;", $2.text);
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
								
								printTabs();
								fprintf(fIR, "return NULL;");
							}
							{fprintf(fparse, " : RETURN STATEMENT");}
						;
				
				
						

loop_stmt				: LOOP loop_type {fprintf(fparse, " : LOOP");}
						; 

loop_type				: for_loop
						| while_loop
						;
				
for_loop				: FOR '(' {printTabs(); fprintf(fIR, "for(");} for_in ')'{fprintf(fIR, ") ");} function_body
						;


for_in					: expr_stmt logical_op ';' {fprintf(fIR, "%s; ", $2.text);} for_expr 
						;
						

for_expr				: unary_op {fprintf(fIR, "%s ", $1.text);}
						| EXPR LHS '=' for_RHS {
							if(strcmp($2.type, $4.str)){
								int a = !strcmp($2.type, "int") || !strcmp($2.type, "float") || !strcmp($2.type, "bool");
								int b = !strcmp($4.str, "int") || !strcmp($4.str, "float") || !strcmp($4.str, "bool");
							
								if(!(a && b)){
									printf("%d Error: Expression statement, type mismatch\n", yylineno);
									exit(1);
								}
								
								fprintf(fIR, "%s = %s", $2.text, $4.text);
							}
						}
						;
						
						
for_RHS					: arith_op {$$.str = $1.str; $$.text = $1.text; }
						| func_calls {$$.str = $1.str; $$.text = $1.text; }
						| impr {$$.str = $1.str; $$.text = $1.text; }
						| graph_impr {$$.str = $1.str; $$.text = $1.text; }
						| vect_stmt_body {$$.str = $1.str; $$.text = $1.text; }
						| matrix_impr {$$.str = $1.str; $$.text = $1.text; }
						;

while_loop				: WHILE '('RHS')' {
							int a = !strcmp($3.str, "int") || 
									!strcmp($3.str, "float") || 
									!strcmp($3.str, "bool") ||
									!strcmp($3.str, "string") ||
									!strcmp($3.str, "char")
									;
							if(!a) {
								printf("%d Error : Invalid conditional argument\n", yylineno);
							}
							printTabs();
							fprintf(fIR, "while(%s) ", $3.text);
						} function_body
						;
						
						
expr_stmt				: EXPR LHS '=' RHS ';' {
							if(strcmp($2.type, $4.str)){
								int a = !strcmp($2.type, "int") || !strcmp($2.type, "float") || !strcmp($2.type, "bool");
								int b = !strcmp($4.str, "int") || !strcmp($4.str, "float") || !strcmp($4.str, "bool");
							
								if(!(a && b)){
									printf("%d Error: Expression statement, type mismatch\n", yylineno);
									exit(1);
								}
							}
							printTabs();
							fprintf(fIR, "%s = %s;", $2.text, $4.text);
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
						| EXPR LHS '=' extra_consts ';'
							{
								int dimAval, dimBval;
								dimAval = $2.dimA;
								dimBval = $2.dimB;
								char* element_type;
								element_type = $2.eleType;
								/*int ind = var_search($2.name);
								
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
								}*/
								 

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
									// printTabs();
									// fprintf(fIR, "%s = %s;", $2.text, $4.text);
								}
								else if(strcmp("matrix", $2.type)==0)
								{
									
									if(dimAval != -1 && dummy_size!=dimAval) 
									{
										printf("%d ERROR: Number of rows mismatch\n", yylineno);
										printf("dummy_size: %d, dimAval: %d\n", dummy_size, dimAval); 
										exit(1);
									}
									for(int i=0; i<dummy_size; i++)
									{
										if(dimBval != -1 && newArr[i]!=dimBval)
										{
											printf("%d ERROR: Number of columns mismatch\n", yylineno);
											exit(1);
										}
									}
									dummy_size=0;
									printTabs();
									fprintf(fIR, "%s.vals = %s;", $2.text, $4.text);
								}
								else if(strcmp($2.type, "array") == 0)
								{
									if(strcmp(element_type, $4.str) && strcmp($4.str, "any")!=0)
									{
										printf("%d ERROR: Element-type mismatch in array\n", yylineno);
										exit(1);
									}
									if(dimAval != -1 && dummy_size!=dimAval)
									{
										printf("%d ERROR: Array length is not matching\n", yylineno);
										exit(1);
									}
									
									dummy_size=0;
									printTabs();
									fprintf(fIR, "%s = %s;", $2.text, $4.text);
								}
								
								else if(strcmp($2.type, $4.str)){
									printf("%d Error: Expression statement type mismatch %s != %s\n", yylineno, $2.type, $4.str);
									exit(1);
								}
								
								else{
									printTabs();
									fprintf(fIR, "%s = %s;", $2.text, $4.text);
								}
								
								
							}
							{fprintf(fparse, " : EXPRESSION STATEMENT");}

						| EXPR LHS '=' graph_impr ';' {
							if(strcmp($2.type, $4.str)){
								int a = !strcmp($2.type, "int") || !strcmp($2.type, "float") || !strcmp($2.type, "bool");
								int b = !strcmp($4.str, "int") || !strcmp($4.str, "float") || !strcmp($4.str, "bool");
							
								if(!(a && b)){
									printf("%d Error: Expression statement, type mismatch\n", yylineno);
									exit(1);
								}
							}
							printTabs();
							fprintf(fIR, "%s = %s;\n", $2.text, $4.text);
							
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
						| EXPR LHS '=' matrix_impr ';' {
							if(strcmp($2.type, $4.str)){
								printf("%d Error: Expression statement, type mismatch\n", yylineno);
								exit(1);
							}
							printTabs();
							fprintf(fIR, "%s = %s;\n", $2.text, $4.text);
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
						| EXPR LHS '=' vect_stmt_body ';' {
							if(strcmp($2.type, $4.str)) {
								printf("%d Error: Expression statement, type mismatch\n", yylineno);
								exit(1);
							}
							fprintf(fparse, " : EXPRESSION STATEMENT");
							printTabs();
							fprintf(fIR, "%s = %s;", $2.text, $4.text);
						}
						;
						
						
LHS						: myId {
							classIndex = -1;
							int i = var_search($1.str);
							int j, l;
							if(inClass) j = class_declr_search($1.str, class_size-1);
							else j = -1;
							int k = func_search($1.str);
							if(inClass) l = class_func_search($1.str, class_size-1);
							else l = -1;
							
							if(i<0 && j<0 && k<0 && l<0){
								printf("%d Error: Accessing undeclared identifier/function %s\n", yylineno, $1.str);
							}
							
							// class declare variable (class attirbute)
							if(j>=0) {
								$$.name = $1.str;
								$$.dimA = class_symb[class_size-1].declr_list[j].dim_A;
								$$.dimB = class_symb[class_size-1].declr_list[j].dim_B;
								$$.eleType = class_symb[class_size-1].declr_list[j].ele_type;
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
								$$.name = $1.str;
								$$.dimA = var_symb[i].dim_A;
								$$.dimB = var_symb[i].dim_B;
								$$.eleType = var_symb[i].ele_type;
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
								$$.name = $1.str;
								$$.type = class_symb[class_size-1].func_list[l].type;
								classIndex = class_size-1;
								funcIndex = l;
								// printf("%s : %s\n", $$.name, $$.type);
							}
							
							// normal funciton
							else if(k >= 0){
								$$.name = $1.str;
								$$.type = func_symb[k].type;
								funcIndex = k;
								// printf("%s : %s\n", $$.name, $$.type);
							}
							
							// printf("%d:: LHS.name - %s; LHS.type - %s\n", yylineno, $$.name, $$.type);
							
							$$.text = $1.text;
							LeftName = $1.text;
							
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
									
									int j = class_declr_search($3.str, i);
									int k = class_func_search($3.str, i);
									if(j < 0 && k < 0){
										printf("%d Error: Accessing undefined function/attribute %s of class %s\n", yylineno,$3.str, $1.type);
										// printClassNode(class_symb[i]);
										exit(1);
									}
									
									if(j >= 0){
										$$.name = $3.str;
										$$.type = class_symb[i].declr_list[j].type;
										$$.dimA = class_symb[i].declr_list[j].dim_A;
										$$.dimB = class_symb[i].declr_list[j].dim_B;
										$$.eleType = class_symb[i].declr_list[j].ele_type;
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
										$$.name = $3.str;
										$$.type = "func"; // can be ignored
									}
								}
							}
							
							else {
								// item defined in struct, now check its attributes
								int j = struct_declr_search($3.str, i);
								if(j < 0){
								
									// item is not attribute of this struct
									printf("%d Error: Accessing undefined attribute of struct %s\n", yylineno, $1.name);
									exit(1);
								}
								
								else{
									$$.name = $3.str;
									$$.dimA = struct_symb[i].list[j].dim_A;
									$$.dimB = struct_symb[i].list[j].dim_B;
									$$.eleType = struct_symb[i].list[j].ele_type;
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
							
							char* myText = (char*)malloc(strlen($1.text)+strlen($3.text)+2);
							strcpy(myText, $1.text);
							strcat(myText, ".");
							strcat(myText, $3.text);
							$$.text = myText;
							LeftName = $$.text;
						}
						;
						
						
myId					: id {$$.str=$1.str; $$.text = $1.text;}
						| id '[' RHS ']'{
							int a = !strcmp($3.str, "int") || !strcmp($3.str, "float");
							if(!a){
								printf("%d Error: invalid array index\n", yylineno);
								exit(1);
							}
							$$.str = $1.str;
							
							char* myText = (char*)malloc(strlen($1.text)+strlen($3.text)+3);
							strcpy(myText, $1.text);
							strcat(myText, "[");
							strcat(myText, $3.text);
							strcat(myText, "]");
							$$.text = myText;
						}
						;




declr_stmt				: DECLR declr_body ';' {fprintf(fparse, " : DECLARATION STATEMENT"); fprintf(fIR, ";");}

declr_body				: DATATYPE id_list
							{
								if(currentFuncIndex!=-1) // inside class and inside function
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
								else if(inClass==1) // inside class outside function
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
								else // independent function
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
								printTabs();
								fprintf(fIR, "%s %s", $1, $2.text);
								
							}
						| GRAPH graph_and_array_list
							{
								if(currentFuncIndex!=-1) // inside class and inside function
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
									for(int i=0; i<strlen($2.text); i++){
										if($2.text[i] == '[') $2.text[i] = '(';
										
										if($2.text[i] == ']') $2.text[i] = ')';
									}
								}
								else if(inClass==1) // inside class outside function
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
									printTabs();
									for(int i=0; i<strlen($2.text); i++){
										if($2.text[i] == '[') $2.text[i] = '{';
									
										if($2.text[i] == ']') $2.text[i] = '}';
									}
								}
								
								
								
								else // in struct
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
									for(int i=0; i<strlen($2.text); i++){
									if($2.text[i] == '[') $2.text[i] = '{';
									
									if($2.text[i] == ']') $2.text[i] = '}';
								}
								}
								arr_size=0;
								
								printTabs();
								fprintf(fIR, "graph %s", $2.text);
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
										var_insert(1, level, arr[i], $1, $3.str, -1, -1);
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
										add_class_declrs(arr[i], $1, 1, level, $3.str, -1, -1);
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
										add_struct_declrs(arr[i], $1, 1, level, $3.str, -1, -1);
									}
								}
								arr_size=0;
								printTabs();
								fprintf(fIR, "vector<%s> %s", $3.text, $5.text);
								
							}
						| MATRIX matrix_list 
							{
								if(currentFuncIndex!=-1) // inside class and inside function
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
								else if(inClass==1) // inside class and outside function
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
									
									
									for(int i=0; i<strlen($2.text); i++){
										if($2.text[i] == '(') $2.text[i] = '{';
										if($2.text[i] == ')') $2.text[i] = '}';
									}
								}
								else // in struct
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
									for(int i=0; i<strlen($2.text); i++){
										if($2.text[i] == '(') $2.text[i] = '{';
										if($2.text[i] == ')') $2.text[i] = '}';
									}
								}
								arr_size=0;
								printTabs();
								fprintf(fIR, "matrix %s", $2.text);
							}
						| DATATYPE  graph_and_array_list
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
								printTabs();
								fprintf(fIR, "%s %s", $1, $2.text);
								
								
								
							}
						| id id_list
							{
								if(class_search($1.str)!=-1 || struct_search($1.str)!=-1)
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
											var_insert(1, level, arr[i], $1.str, "", -1, -1);
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
											add_class_declrs(arr[i], $1.str, 1, level, "", -1, -1);
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
											add_struct_declrs(arr[i], $1.str, 1, level, "", -1, -1);
										}
									}
									arr_size =0;
									printTabs();
									{
										int a = class_search($1.str);
										int b = struct_search($1.str);
										if(a > b) fprintf(fIR, "class %s ", $1.text);
										else fprintf(fIR, "struct %s ", $1.text);
									}
									
									fprintf(fIR, "%s", $2.text);
								}
								else
								{
									arr_size=0;
									printf("%d ERROR: No struct or class with that name is defined\n", yylineno);
									exit(1);
								}
							}
						;

graph_and_array_list	:  graph_and_array_list ',' id '[' INT_CONST ']'
							{
								arr[arr_size] = $3.str;
								dimA[arr_size] = atoi($5);
								if(dimA[arr_size]<=0)
								{
									printf("%d ERROR: Dimension(s) has to be greater than 0\n", yylineno);
									exit(1);
								}
								arr_size++;
								
								char* myText = (char*)malloc(strlen($1.text)+strlen($3.text)+strlen($5)+5);
								strcpy(myText, $1.text);
								strcat(myText, ", ");
								strcat(myText, $3.text);
								strcat(myText, "[");
								strcat(myText, $5);
								strcat(myText, "]");
								
								//strcpy($$.text, myText);
								//free(myText);
								$$.text = myText;
							}
						| id '[' INT_CONST ']'
							{
								arr[arr_size] = $1.str;
								dimA[arr_size] = atoi($3);
								if(dimA[arr_size]<=0)
								{
									printf("%d ERROR: Dimension(s) has to be greater than 0\n", yylineno);
									exit(1);
								}
								arr_size++;
								
								char* myText = (char*)malloc(strlen($1.text)+strlen($3)+3);
								strcpy(myText, $1.text);
								strcat(myText, "[");
								strcat(myText, $3);
								strcat(myText, "]");
								
								//strcpy($$.text, myText);
								//free(myText);
								$$.text = myText;
							}
						;

matrix_list				: matrix_list ',' id '[' INT_CONST ']' '[' INT_CONST ']'
							{
								arr[arr_size] = $3.str;
								dimA[arr_size] = atoi($5);
								dimB[arr_size] = atoi($8);
								if(dimA[arr_size]<=0 || dimB[arr_size]<=0)
								{
									printf("%d ERROR: No of rows or columns has to be positive\n", yylineno);
									exit(1);
								}
								arr_size++;
								
								char* myText = (char*)malloc(strlen($1.text)+strlen($3.text)+strlen($5)+strlen($8)+7);
								strcpy(myText, $1.text);
								strcat(myText, ", ");
								strcat(myText, $3.text);
								strcat(myText, "(");
								strcat(myText, $5);
								strcat(myText, ", ");
								strcat(myText, $8);
								strcat(myText, ")");
								//strcpy($$.text, myText);
								//free(myText);
								$$.text = myText;
							}
							
						| matrix_list ',' id '[' LHS ']' '[' LHS ']'
							{
								arr[arr_size] = $3.str;
								
								arr_size++;
								
								char* myText = (char*)malloc(strlen($1.text)+strlen($3.text)+strlen($5.text)+strlen($8.text)+7);
								strcpy(myText, $1.text);
								strcat(myText, ", ");
								strcat(myText, $3.text);
								strcat(myText, "(");
								strcat(myText, $5.text);
								strcat(myText, ", ");
								strcat(myText, $8.text);
								strcat(myText, ")");
								//strcpy($$.text, myText);
								//free(myText);
								$$.text = myText;
							}
						
							
						| id '[' INT_CONST ']' '[' INT_CONST ']'
							{
								arr[arr_size] = $1.str;
								dimA[arr_size] = atoi($3);
								dimB[arr_size] = atoi($6);
								if(dimA[arr_size]<=0 || dimB[arr_size]<=0)
								{
									printf("%d ERROR: No of rows or columns has to be positive\n", yylineno);
									exit(1);
								}
								arr_size++;
								
								char* myText = (char*)malloc(strlen($1.text)+strlen($3)+strlen($6)+5);
								strcpy(myText, $1.text);
								strcat(myText, "(");
								strcat(myText, $3);
								strcat(myText, ", ");
								strcat(myText, $6);
								strcat(myText, ")");
								
								$$.text = myText;
							}
						| id '[' LHS ']' '[' LHS ']'
							{
								arr[arr_size] = $1.str;
								
								arr_size++;
								
								char* myText = (char*)malloc(strlen($1.text)+strlen($3.text)+strlen($6.text)+5);
								strcpy(myText, $1.text);
								strcat(myText, "(");
								strcat(myText, $3.text);
								strcat(myText, ", ");
								strcat(myText, $6.text);
								strcat(myText, ")");
								
								$$.text = myText;
							}
						;

id_list					: id_list ',' id
							{
								arr[arr_size] = $3.str;
								arr_size++;
								
								char* myText = (char*)malloc(strlen($1.text)+strlen($3.text)+2);
								strcpy(myText, $1.text);
								strcat(myText, ", ");
								strcat(myText, $3.text);
								//strcpy($$.text, myText);
								//free(myText);
								$$.text = myText;
							}
						| id
							{
								arr[arr_size] = $1.str;
								arr_size++;
								$$.text = $1.text;
							}
						;

ifcond_stmt				: IF '(' RHS ')' {
							int a = !strcmp($3.str, "int") || 
									!strcmp($3.str, "float") || 
									!strcmp($3.str, "bool") ||
									!strcmp($3.str, "string") ||
									!strcmp($3.str, "char")
									;
							if(!a) {
								printf("%d Error : Invalid conditional argument\n", yylineno);
							}
							printTabs();
							fprintf(fIR, "if(%s)", $3.text);
							fprintf(fparse, " : CONDITIONAL STATEMENT");
						} if_body
						;
						
						
if_body					: function_body ELSE {fprintf(fIR, "else ");}function_body
						| function_body
						;

switch_stmt				: SWITCH '(' RHS ')' {
							int a = !strcmp($3.str, "int") || 
									!strcmp($3.str, "float") || 
									!strcmp($3.str, "bool") ||
									!strcmp($3.str, "string") ||
									!strcmp($3.str, "char")
									;
							if(!a) {
								printf("%d Error : Invalid conditional argument\n", yylineno);
							}
							printTabs();
							fprintf(fIR, "switch (%s)", $3.text);
							fprintf(fparse, " : CONDITIONAL STATEMENT");
						} switch_body
						;
												

switch_body				: '{' {switch_insert(level); level++; fprintf(fIR, "{\n");} cases DEFAULT ':' {printTabs(); fprintf(fIR, "default:\n");} function_body '}' { var_delete(level); level--; switch_delete(); printTabs(); fprintf(fIR, "}\n");}
						;

cases					: cases CASE INT_CONST  {add_case(level-1, $3); printTabs(); fprintf(fIR, "case %s:\n", $3); } ':' function_body 
						| CASE INT_CONST  {add_case(level-1, $2); printTabs(); fprintf(fIR, "case %s:\n", $2); } ':' function_body
						;

						
						
RHS						: constants {$$.str=$1.str; $$.text = $1.text;}
						| arith_op {$$.str=$1.str; $$.text = $1.text;}
						| logical_op {$$.str=$1.str; $$.text = $1.text;}
						| func_calls {$$.str=$1.str; $$.text = $1.text;}
						| impr {$$.str = $1.str; $$.text = $1.text;}
						;						

						
constants				: INT_CONST {$$.str="int"; $$.text = $1;}
						| FLOAT_CONST {$$.str="float"; $$.text = $1;}
						| CHAR_CONST {$$.str="char"; $$.text = $1;}
						| STR_CONST {$$.str="string"; $$.text = $1;}
						| BOOL_CONST {$$.str = "bool"; $$.text = $1;}
						| LHS {$$.str = $1.type; $$.text = $1.text;}
						;
						
						
extra_consts			: array_const{$$.str = $1.str; $$.text = $1.text;}
						| graph_const{$$.str="graph"; $$.text = $1.text;}
						| vect_const{
							char* myType = (char*)malloc(strlen($1.str)+2);
							strcpy(myType, "*");
							strcat(myType, $1.str);
							$$.str = myType;
							 $$.text = $1.text;
						}
						| matrix_const{$$.str="matrix"; $$.text = $1.text;}
						| '{' '}'{$$.str="1"; $$.text = "{}";}
						;

array_const				: '[' val_list ']'
							{
								
								$$.str = $2.text;
								
								char* myText = (char*)malloc(strlen($2.text)+3);
								strcpy(myText, "{");
								strcat(myText, $2.text);
								strcat(myText, "}");
								
								$$.text = myText;
							}
						| '[' ']'
							{
								$$.str = "any";
								$$.text = "{}";
							}
						;
						
val_list				: int_list
							{ $$.str = "int"; $$.text = $1.text;}
						| float_list
							{ $$.str  = "float"; $$.text = $1.text;}
						| char_list
							{ $$.str = "char"; $$.text = $1.text;}
						| bool_list
							{ $$.str = "bool"; $$.text = $1.text;}
						| str_list
							{ $$.str = "string"; $$.text = $1.text;}
						;
resultant				: LHS{$$.str = $1.type; $$.text = $1.text;}
						| matrix_impr {$$.str = $1.str;}
						| graph_impr {$$.str = $1.str;}
						| vect_stmt_body {$$.str = $1.str; $$.text = $1.text;}
						| impr {$$.str = $1.str; $$.text = $1.text;}
						| func_calls{$$.str = $1.str; $$.text = $1.text;}
						;				
						
						
impr					: resultant '.' LENGTH '(' ')'{
							//printf("%d::Initial resultant type: %s\n",yylineno, $1);
							if($1.str[0] != '*'){
								printf("%d Error: invalid type for 'at'\n", yylineno);
								exit(1);
							} else {
								$$.str = "int";
								
								
								char* myText = (char*)malloc(strlen($1.text)+8);
								strcpy(myText, $1.text);
								strcat(myText, ".size()");
								strcpy($$.text, myText);
								free(myText);;
								
							}
						}
						| resultant '.' AT '(' remove_body ')'{
							//printf("%d::Initial resultant type: %s\n",yylineno, $1);
							if($1.str[0] != '*'){
								printf("%d Error: invalid type for 'at'\n", yylineno);
								exit(1);
							}
							else {
								if (!(!strcmp("int", $5.str) || !strcmp("float", $5.str) || !strcmp("bool", $5.str))){
									printf("%d ERROR: appending the wrong dtype\n", yylineno);
									exit(1);
								}
								else{
									char* myType = (char*)malloc(strlen($1.str)+1);
									strncpy(myType, $1.str + 1, strlen($1.str));
									myType[strlen($1.str)] = '\0';
									strcpy($$.str, myType);
									char* myText = (char*)malloc(strlen($1.text) + strlen($5.text) + 3);
									strcpy(myText, $1.text);
									strcat(myText, "[");
									strcat(myText, $5.text);
									strcat(myText, "]");
									strcpy($$.text, myText);
									
									free(myType);
									free(myText);
								}
							} 
							
							// printf("%d::resultant - %s, index - %s, returning - %s\n", yylineno, $1, $5, $$);
						}
						| resultant '.' TRACE '(' ')' {
							//printf("%d::Initial resultant type: %s\n",yylineno, $1);
							if(strcmp("matrix", $1.str)){
								printf("%d Error: invalid type for trace\n", yylineno);
								exit(1);
							}else{
								$$.str = "int";
								char* myText = (char*)malloc(strlen($1.text)+strlen("trace()"));
								strcpy(myText, "trace(");
								strcat(myText, $1.text);
								strcat(myText, ")");
								$$.text = myText;
							}
						}
						| resultant '.' STRLEN '(' ')'
							{
								$$.str = "int";
								if(strcmp($1.str, "string"))
								{
									printf("%d ERROR: Method defined for string datatype only\n", yylineno);
									exit(1);
								}
								
								char* myText = (char*)malloc(strlen(".size()") + strlen($1.text));
								strcpy(myText, $1.text);
								strcpy(myText, ".size()");
								
								strcpy($$.text, myText);
								free(myText);
							}
						| STRCMP '(' RHS ',' RHS ')' 
							{
								$$.str = "bool";
								if(strcmp($3.str, "string") || strcmp($5.str, "string"))
								{
									printf("%d ERROR: Arguments have to be strings\n", yylineno);
									exit(1);
								}
								
								
								char* myText = (char*)malloc(strlen("strcmpr(, )") + strlen($3.text) + strlen($5.text));
								strcpy(myText, "strcmpr(");
								strcat(myText, $3.text);
								strcat(myText, ", ");
								strcat(myText, $5.text);
								strcat(myText, ")");
								
								$$.text = myText;
								
							}
						| resultant '.' STRCUT '(' remove_body ',' remove_body ')'
							{
								$$.str = "string";
								if(strcmp($1.str, "string"))
								{
									printf("%d ERROR: Method defined for string datatype only\n", yylineno);
									exit(1);
								}
								if(strcmp($5.str, "int") || strcmp($7.str, "int"))
								{
									printf("%d ERROR: Arguments have to be intergers\n", yylineno);
									exit(1);
								}
								
								char* myText = (char*)malloc(strlen($1.text) + strlen(".substr(, )") + 2*strlen($5.text) + strlen($7.text) + 2);
								strcpy(myText, $1.text);
								strcat(myText, ".substr(");
								strcat(myText, $5.text);
								strcat(myText, ", (");
								strcat(myText, $7.text);
								strcat(myText, "-");
								strcat(myText, $5.text);
								strcat(myText, ")+1)");
								
								$$.text = myText;
							}
						| STRJOIN '(' RHS ',' RHS ')'
							{
								$$.str =  "string";
								if(strcmp($3.str, "string") || strcmp($5.str, "string"))
								{
									printf("%d ERROR: Arguments have to be strings\n", yylineno);
									exit(1);
								}
								
								char* myText = (char*)malloc( strlen($3.text) + strlen($5.text) + 4);
								strcpy(myText, "(");
								strcat(myText, $3.text);
								strcat(myText, "+");
								strcat(myText, $5.text);
								strcat(myText, ")");
								
								$$.text = myText;
								
							}
						;
						
graph_impr				: resultant '.' TRAVERSAL '(' remove_body ')'
							{
								$$.str = "*int";
								if(strcmp($1.str,"graph"))
								{
									printf("%d ERROR: Traversals are defined only for graph datatype\n", yylineno);
									exit(1);
								}
								if(strcmp($5.str, "int"))
								{
									printf("%d ERROR: Argument has to be an integer\n", yylineno);
									exit(1);
								}
								
								char* myText = (char*)malloc(strlen($1.text)+strlen("bfs.()")+strlen($5.text)+1);
								strcpy(myText, $1.text);
								strcat(myText, ".");
								strcat(myText, $3);
								strcat(myText, "(");
								strcat(myText, $5.text);
								strcat(myText, ")");
								$$.text = myText;
							}
						| resultant '.' GRTOMATX '(' ')'
							{
								$$.str = "matrix";
								if(strcmp($1.str,"graph"))
								{
									printf("%d ERROR: Method applicable only for graph datatype\n", yylineno);
									exit(1);
								}
							}
						| resultant '.' SHPATH '(' remove_body ',' remove_body ')'
							{
								$$.str = "*int";
								if(strcmp($1.str,"graph"))
								{
									printf("%d ERROR: Method applicable only for graph datatype\n", yylineno);
									exit(1);
								}
								if(strcmp($5.str,"int") || strcmp($7.str, "int"))
								{
									printf("%d ERROR: Arguments should be integers\n", yylineno);
									exit(1);
								}
								char* myText = (char*)malloc(strlen($1.text)+strlen("shortest_path()")+3);
								strcpy(myText, "shortest_path(");
								strcat(myText, $1.text);
								strcat(myText, ",");
								strcat(myText, $5.text);
								strcat(myText, ",");
								strcat(myText, $7.text);
								strcat(myText, ")");
								$$.text = myText;
							}
						| resultant '.' SHPATH_VAL '(' remove_body ',' remove_body ')' 
							{
								$$.str = "int";
								if(strcmp($1.str,"graph"))
								{
									printf("%d ERROR: Method applicable only for graph datatype\n", yylineno);
									exit(1);
								}
								if(strcmp($5.str,"int") || strcmp($7.str, "int"))
								{
									printf("%d ERROR: Arguments should be integers\n", yylineno);
									exit(1);
								}
								char* myText = (char*)malloc(strlen($1.text)+strlen("shortest_path_value()")+3);
								strcpy(myText, "shortest_path_value(");
								strcat(myText, $1.text);
								strcat(myText, ",");
								strcat(myText, $5.text);
								strcat(myText, ",");
								strcat(myText, $7.text);
								strcat(myText, ")");
								$$.text = myText;
							}
						| resultant '.' ADJNODE '(' remove_body ')'
							{
								$$.str = "*int";
								if(strcmp($1.str,"graph"))
								{
									printf("%d ERROR: Adjacent Nodes are defined only for graph datatype\n", yylineno);
									exit(1);
								}
								if(strcmp($5.str, "int"))
								{
									printf("%d ERROR: Argument has to be an integer\n", yylineno);
									exit(1);
								}
								
								char* myText = (char*)malloc(strlen($1.text)+strlen("adjNodes.()")+strlen($5.text)+1);
								strcpy(myText, $1.text);
								strcat(myText, ".");
								strcat(myText, $3);
								strcat(myText, "(");
								strcat(myText, $5.text);
								strcat(myText, ")");
								$$.text = myText;
							}
						;
						
						
matrix_impr				: MATXOP '(' matr_body ',' matr_body ')'
							{
								if(strcmp($3.str,"matrix") || strcmp($5.str,"matrix"))
								{
									printf("%d, ERROR : argument is not a matrix\n",yylineno);
									exit(1);
								}
								$$.str = "matrix";
								char* myText = (char*)malloc(128);
							
								strcpy(myText, $1);
								strcat(myText, "(");
								strcat(myText, $3.text);
								strcat(myText, ", ");
								strcat(myText, $5.text);
								strcat(myText, ")");
								$$.text = myText;
							}
						| resultant '.' TRANSPOSE '(' ')' 
							{
								$$.str = "matrix";
								if(strcmp($1.str, "matrix"))
								{
									printf("%d ERROR: Method defined for matrix datatype only\n", yylineno);
									exit(1);
								}
								
								char* myText = (char*)malloc(strlen($1.text)+strlen("transpose()"));
								strcpy(myText, "transpose(");
								strcat(myText, $1.text);
								strcat(myText, ")");
								$$.text = myText;
							}
						| resultant '.' MAXTOGR '(' ')' 
							{
								$$.str = "graph";
								if(strcmp($1.str, "matrix"))
								{
									printf("%d ERROR: Method defined for matrix datatype only\n", yylineno);
									exit(1);
								}
							}
							
						| resultant '.' GETVAL '(' remove_body ',' remove_body ')' {
							if(strcmp($1.str, "matrix")){
								printf("%d Error: Only matrix can call getVal function\n", yylineno);
								exit(1);
							}
							
							int a = !(strcmp($5.str, "int"));
							int b = !(strcmp($7.str, "int"));
							
							if(!(a && b)){
								printf("%d Error: invalid arguments in getVal function\n", yylineno);
								exit(1);
							}
							
							char* myText = (char*)malloc(strlen($1.text)+strlen(".getValue(, )")+strlen($5.text)+strlen($7.text)+1);
							strcpy(myText, $1.text);
							strcat(myText, ".getValue(");
							strcat(myText, $5.text);
							strcat(myText, ", ");
							strcat(myText, $7.text);
							strcat(myText, ")");
							
							$$.str = "int";
							$$.text = myText;
						}
						;
						
matr_body				: RHS {$$.str = $1.str;}
						| matrix_impr {$$.str = $1.str;}
						;
						
graph_const				: '{' graph_type1 '}' {
								printTabs();
								fprintf(fIR, "%s.setFlag(0);\n", LeftName);
								char* myText = (char*)malloc(strlen($2.text)+3);
								strcpy(myText, "{");
								strcat(myText, $2.text);
								strcat(myText, "}");
								$$.text = myText;
							} 
						| '{' graph_type2 '}' {
								printTabs();
								fprintf(fIR, "%s.setFlag(1);\n", LeftName);
								char* myText = (char*)malloc(strlen($2.text)+3);
								strcpy(myText, "{");
								strcat(myText, $2.text);
								strcat(myText, "}");
								$$.text = myText;
							}
						;

graph_type1				: graph_type1 INT_CONST ':' int_list ';'
							{
								
								newArr[dummy_size] = atoi($2);
								dummy_size++;
								int size;
								int* intArray = splitStringToIntArray($4.text, &size);
								
								if (intArray != NULL) {
       								for (int i = 0; i < size; ++i) {
       									printTabs();
          							 	fprintf(fIR, "%s.addEdge(%s, %d);\n", LeftName, $2, intArray[i]);
        							}

       								free(intArray); // Don't forget to free the allocated memory
    							} else {
        							printf("Memory allocation failed.\n");
							    }

								char* myText = (char*)malloc(strlen($1.text)+strlen(": ; ")+strlen($2)+strlen($4.text)+1);
								strcpy(myText, $1.text);
								strcat(myText, " ");
								strcat(myText, $2);
								strcat(myText, ": ");
								strcat(myText, $4.text);
								strcat(myText, ";");

								$$.text = myText;
								
							}
						| INT_CONST ':' int_list ';'
							{
								newArr[dummy_size] = atoi($1);
								dummy_size++;
								int size;
								int* intArray = splitStringToIntArray($3.text, &size);
								
								if (intArray != NULL) {
       								for (int i = 0; i < size; ++i) {
       									printTabs();
          							 	fprintf(fIR, "%s.addEdge(%s, %d);\n", LeftName, $1, intArray[i]);
        							}

       								free(intArray); // Don't forget to free the allocated memory
    							} else {
        							printf("Memory allocation failed.\n");
							    }


								char* myText = (char*)malloc(strlen($1)+strlen(": ; ")+strlen($3.text)+1);
								strcpy(myText, $1);
								strcat(myText, ": ");
								strcat(myText, $3.text);
								strcat(myText, "; ");

								$$.text = myText;
							}
						;

graph_type2				: graph_type2 INT_CONST ':' weight_list ';'
							{
								newArr[dummy_size] = atoi($2);
								dummy_size++;
								size_t count;
								const char* delimiter = ",";
   								char** result = splitString($4.text, delimiter, &count);

    							// Print the result
    							for (size_t i = 0; i < count; i=i+2) {
    								printTabs();
       								fprintf(fIR, "%s.addWeightedEdge(%s, %s, %s);\n", LeftName, $2, result[i], result[i+1]);
    							}

    							// Free the allocated memory
    							freeStringArray(result, count);

								char* myText = (char*)malloc(strlen($1.text)+strlen(": ; ")+strlen($2)+strlen($4.text)+1);
								strcpy(myText, $1.text);
								strcat(myText, " ");
								strcat(myText, $2);
								strcat(myText, ": ");
								strcat(myText, $4.text);
								strcat(myText, ";");

								$$.text = myText;
							}
						| INT_CONST ':' weight_list ';'
							{
								newArr[dummy_size] = atoi($1);
								dummy_size++;
								size_t count;
								const char* delimiter = ",";
   								char** result = splitString($3.text, delimiter, &count);

    							// Print the result
    							for (size_t i = 0; i < count; i=i+2) {
    								printTabs();
       								fprintf(fIR, "%s.addWeightedEdge(%s, %s, %s);\n", LeftName, $1, result[i], result[i+1]);
    							}

    							// Free the allocated memory
    							freeStringArray(result, count);

								char* myText = (char*)malloc(strlen($1)+strlen(": ; ")+strlen($3.text)+1);
								strcpy(myText, $1);
								strcat(myText, ": ");
								strcat(myText, $3.text);
								strcat(myText, "; ");

								$$.text = myText;
							}
						;

int_list				: int_list ',' INT_CONST
							{
								newArr[dummy_size] = atoi($3);
								dummy_size++;
							}
							{
								$$.str = "int";
								char* myText = (char*)malloc(strlen($1.text)+strlen($3)+3);
								strcpy(myText, $1.text);
								strcat(myText, ",");
								strcat(myText, $3);
								$$.text = myText;
							}
						| INT_CONST
							{
								newArr[dummy_size] = atoi($1);
								dummy_size++;
							}
							{
								$$.str = "int";
								$$.text = $1;
							}
						;

float_list				: float_list ',' FLOAT_CONST 
							{
								$$.str = "float";
								dummy_size++;
								char* myText = (char*)malloc(strlen($1.text)+strlen($3)+3);
								strcpy(myText, $1.text);
								strcat(myText, ", ");
								strcat(myText, $3);
								$$.text = myText;
							}
						| FLOAT_CONST
							{
								$$.str = "float";
								dummy_size++;
								$$.text = $1;
							}
						;

char_list				: char_list ',' CHAR_CONST
							{
								$$.str = "char";
								dummy_size;
								char* myText = (char*)malloc(strlen($1.text)+strlen($3)+3);
								strcpy(myText, $1.text);
								strcat(myText, ", ");
								strcat(myText, $3);
								$$.text = myText;
							}
						| CHAR_CONST
							{
								$$.str = "char";
								dummy_size++;
								$$.text = $1;
							}
						;

bool_list				: bool_list ',' BOOL_CONST
							{
								$$.str = "bool";
								dummy_size;
								char* myText = (char*)malloc(strlen($1.text)+strlen($3)+3);
								strcpy(myText, $1.text);
								strcat(myText, ", ");
								strcat(myText, $3);
								$$.text = myText;
							}
						| BOOL_CONST
							{
								$$.str = "bool";
								dummy_size;
								$$.text = $1;
							}
						;

str_list				: str_list ',' STR_CONST
							{
								$$.str = "string";
								dummy_size;
								char* myText = (char*)malloc(strlen($1.text)+strlen($3)+3);
								strcpy(myText, $1.text);
								strcat(myText, ", ");
								strcat(myText, $3);
								$$.text = myText;
							}
						| STR_CONST
							{
								$$.str = "string";
								dummy_size++;
								$$.text = $1;
							}
						;

weight_list				: weight_list ',' '(' INT_CONST ',' INT_CONST ')'
							{
								newArr[dummy_size] = atoi($4);
								dummy_size++;
								
								char* myText = (char*)malloc(strlen($1.text)+strlen($4)+strlen($6)+5);
								strcpy(myText, $1.text);
								strcat(myText, ",");
								strcat(myText, $4);
								strcat(myText, ",");
								strcat(myText, $6);
								$$.text = myText;
							}
						| '(' INT_CONST ',' INT_CONST ')'
							{
								newArr[dummy_size] = atoi($2);
								dummy_size++;
								char* myText = (char*)malloc(strlen($2)+strlen($4)+3);
								strcpy(myText, $2);
								strcat(myText, ",");
								strcat(myText, $4);
								$$.text = myText;
							}
						| weight_list ',' '(' INT_CONST ',' FLOAT_CONST ')'
							{
								newArr[dummy_size] = atoi($4);
								dummy_size++;
								char* myText = (char*)malloc(strlen($1.text)+strlen($4)+strlen($6)+5);
								strcpy(myText, $1.text);
								strcat(myText, ",");
								strcat(myText, $4);
								strcat(myText, ",");
								strcat(myText, $6);
								$$.text = myText;
							}
						| '(' INT_CONST ',' FLOAT_CONST ')'
							{
								newArr[dummy_size] = atoi($2);
								dummy_size++;
								char* myText = (char*)malloc(strlen($2)+strlen($4)+3);
								strcpy(myText, $2);
								strcat(myText, ",");
								strcat(myText, $4);
								$$.text = myText;
							}
						;
						
vect_const				: '{' vect_list '}' {
							$$.str = $2.str;
							char* myText = (char*)malloc(strlen($2.text)+3);
							strcpy(myText, "{");
							strcat(myText, $2.text);
							strcat(myText, "}");
							$$.text = myText;
						}
						;

vect_list				: vect_list ',' vect_item {
							$$.str = $1.str;
							if(strcmp($3.str, $1.str)){
								int a = !strcmp($3.str, "int") || !strcmp($3.str, "float") || !strcmp($3.str, "bool");
								int b = !strcmp($1.str, "int") || !strcmp($1.str, "float") || !strcmp($1.str, "bool");
							
								if(!(a && b)){
									printf("%d Error: vector element type mis-matched\n\n", yylineno);
									exit(1);
								}
							}
							
							char* myText = (char*)malloc(strlen($1.text)+strlen($3.text)+3);
							strcpy(myText, $1.text);
							strcat(myText, ", ");
							strcat(myText, $3.text);
							$$.text = myText;
						}
						| vect_item {
							$$.str = $1.str;
							$$.text = $1.text;
						}
						;
						
vect_item				: constants {$$.str = $1.str; $$.text = $1.text;}
						| extra_consts {$$.str = $1.str; $$.text = $1.text;}
						;
						
matrix_const			: '[' mat_list ']' {
							char* myText = (char*)malloc(strlen($2.text)+3);
							strcpy(myText, "{");
							strcat(myText, $2.text);
							strcat(myText, "}");
							$$.text = myText;
						}
						;

int_float_list			: int_float_list ',' INT_CONST
							{
								$$.cols = $1.cols+1;
								char* myText = (char*)malloc(strlen($1.text)+strlen($3)+2);
								strcpy(myText, $1.text);
								strcat(myText, ",");
								strcat(myText, $3);
								$$.text = myText;
							}
						| int_float_list ',' FLOAT_CONST
							{
								$$.cols = $1.cols+1;
								char* myText = (char*)malloc(strlen($1.text)+strlen($3)+2);
								strcpy(myText, $1.text);
								strcat(myText, ",");
								strcat(myText, $3);
								$$.text = myText;
							}
						| INT_CONST
							{
								$$.cols=1;
								$$.text = $1;
							}
						| FLOAT_CONST
							{
								$$.cols=1;
								$$.text = $1;
							}
						;

mat_list				: mat_list '[' int_float_list ']' ';'
							{
								newArr[dummy_size]=$3.cols;
								dummy_size++;
								
								char* myText = (char*)malloc(strlen($1.text)+strlen($3.text)+4);
								strcpy(myText, $1.text);
								strcat(myText, ",{");
								strcat(myText, $3.text);
								strcat(myText, "}");
								$$.text = myText;
							}
						| '[' int_float_list ']' ';'
							{
								newArr[dummy_size]=$2.cols;
								dummy_size++;
								
								char* myText = (char*)malloc(strlen($2.text)+3);
								strcpy(myText, "{");
								strcat(myText, $2.text);
								strcat(myText, "}");
								$$.text = myText;
								
							}
							
						;
						
arith_op				: binary_op
						| unary_op
						;
						
binary_op				: ARITHOP '(' RHS ',' RHS ')' {
							if(!strcmp($3.str, "int") || !strcmp($3.str, "bool")|| !strcmp($3.str, "float")){
								if(!strcmp($5.str, "int") || !strcmp($5.str, "bool") || !strcmp($5.str, "float")){
									if(!strcmp($5.str, "float") || !strcmp($3.str, "float")) $$.str = "float";
									else $$.str = "int";
								}
								else{
									printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
									exit(1);
								}
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
								exit(1);
							}
							
							if(!strcmp($1, "exp")) {
								char* myText = (char*)malloc(strlen($3.text)+strlen($5.text)+7);
								strcpy(myText, "pow(");
								strcat(myText, $3.text);
								strcat(myText, ",");
								strcat(myText, $5.text);
								strcat(myText, ")");
								$$.text = myText;
							}
							
							else{
								char* symb = (char*)malloc(2);
								if(!strcmp($1, "add")) symb = "+";
								else if(!strcmp($1, "sub")) symb = "-";
								else if(!strcmp($1, "mul")) symb = "*";
								else if(!strcmp($1, "div")) symb = "/";
								char* myText = (char*)malloc(strlen($3.text) + strlen($5.text) + 4);
								strcpy(myText, "(");
								strcat(myText, $3.text);
								strcat(myText, symb);
								strcat(myText, $5.text);
								strcat(myText, ")");
								$$.text = myText;
							
							}
							
							
						}
						;
						
unary_op				: UNARYOP '(' RHS ')' {
							if(!strcmp($3.str, "int") || !strcmp($3.str, "bool")|| !strcmp($3.str, "float")){
								$$.str = "int";
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
								exit(1);
							}
							
							char* symb = (char*)malloc(3);
							if(!strcmp($1, "incr")) symb = "++";
							else if(!strcmp($1, "decr")) symb = "--";
							
							char* myText = (char*)malloc(strlen($3.text)+strlen(symb)+1);
							strcpy(myText, $3.text);
							strcat(myText, symb);
							$$.text = myText;
						}
						;
						
logical_op				: '(' RHS LOGOP RHS ')' {
							if(!strcmp($2.str, "int") || !strcmp($2.str, "bool")|| !strcmp($2.str, "float")){
								if(!strcmp($4.str, "int") || !strcmp($4.str, "bool") || !strcmp($4.str, "float")){
									if(!strcmp($2.str, "float") || !strcmp($4.str, "float")) $$.str = "float";
									else $$.str = "int";
								}
								else{
									printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
									exit(1);
								}
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
								exit(1);
							}
							
							char* symb = (char*)malloc(3);
							if(!strcmp($3, "or")) symb = "||";
							else if(!strcmp($3, "and")) symb = "&&";
							else if(!strcmp($3, "lt")) symb = "<";
							else if(!strcmp($3, "lte")) symb = "<=";
							else if(!strcmp($3, "gt")) symb = ">";
							else if(!strcmp($3, "get")) symb = ">=";
							else if(!strcmp($3, "eq")) symb = "=";
							else if(!strcmp($3, "neq")) symb = "!=";
							
							char* myText = (char*)malloc(strlen($2.text)+strlen($4.text)+strlen(symb)+3);
							strcpy(myText, "(");
							strcat(myText, $2.text);
							strcat(myText, symb);
							strcat(myText, $4.text);
							strcat(myText, ")");
							$$.text = myText;
						}
						| NOT '(' RHS ')' {
							if(!strcmp($3.str, "int") || !strcmp($3.str, "bool")|| !strcmp($3.str, "float")){
								$$.str = "int";
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
								exit(1);
							}
							
							char* myText = (char*)malloc(strlen($3.text)+4);
							strcpy(myText, "!(");
							strcat(myText, $3.text);
							strcat(myText, ")");
							$$.text = myText;
						}
						;

						
call_stmt				: func_calls ';' {fprintf(fparse, " : CALL STATEMENT"); classIndex = -1; printTabs(); fprintf(fIR, "%s;", $1.text); }
						;
						
						
						
func_calls				: call_head arguments {
							$$.str = $1.str;
							
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
							
							char* myText = (char*)malloc(strlen($1.text) + strlen($2.text) + 1);
							strcpy(myText, $1.text);
							strcat(myText, $2.text);
							$$.text = myText;
							// strcpy($$.text, myText);
							// free(myText);
						}
						;
						
						
call_head				: CALL LHS  {
							callClassIndex = classIndex;
							callFuncIndex = funcIndex;
							if(callClassIndex == -1){
								$$.str = func_symb[callFuncIndex].type;
							}
							else{
								$$.str = class_symb[callClassIndex].func_list[callFuncIndex].type;
							}
							myIndex = 0;
							
							$$.text = $2.text;
						}
						;
						
arguments				: '(' arg_list ')' {
							char* myText = (char*)malloc(strlen($2.text) + 3);
							strcpy(myText, "(");
							strcat(myText, $2.text);
							strcat(myText, ")");
							$$.text = myText;
							// strcpy($$.text, myText);
							// free(myText);
						}
						| '(' ')' {$$.text = "()";}
						;
						
arg_list				: arg_list ',' RHS {
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
								
								if(strcmp(myType, $3.str)){
									// type mismatched. Now check if it is ignorable or not
									int a = !strcmp(myType, "int") || !strcmp(myType, "float") || !strcmp(myType, "bool");
									int b = !strcmp($3.str, "int") || !strcmp($3.str, "float") || !strcmp($3.str, "bool");
									
									if(!(a && b)){
										printf("%d Error: for argument-%d expected argument type: %s, given argument type %s\n", yylineno, myIndex, myType, $3.str);
										free(myType);
										exit(1);
									}
									
									else myIndex++;
								}
								
								else myIndex++;
								free(myType);
							}
							char* myText = (char*)malloc(strlen($1.text) + strlen($3.text) + 3);
							strcpy(myText, $1.text);
							strcat(myText, ", ");
							strcat(myText, $3.text);
							$$.text = myText;
							// strcpy($$.text, myText);
							// free(myText);
						}
						| RHS {

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
								if(strcmp(myType, $1.str)){
									// type mismatched. Now check if it is ignorable or not
									int a = !strcmp(myType, "int") || !strcmp(myType, "float") || !strcmp(myType, "bool");
									int b = !strcmp($1.str, "int") || !strcmp($1.str, "float") || !strcmp($1.str, "bool");
									
									if(!(a && b)){
										printf("%d Error: for argument-%d expected argument type: %s, given argument type %s\n", yylineno, myIndex+1, myType, $1.str);
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
							
							$$.text = $1.text;
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
 	fIR = fopen("IR.cpp", "w");
 	fprintf(fIR, "#include <bits/stdc++.h>\n#include \"improvisations.h\"\nusing namespace std;\n\n");
 	

 	yyparse();
 	
 	int valid=0;
 	for (int i=0; i<func_size; i++){
 		if(!strcmp(func_symb[i].name, "main")) valid=1;
 	}
 	if(valid==0){
 		printf("ERROR: 'main' function function is not declared\n");
 		exit(1);
 	}

	fclose(fparse);
 	fclose(ft);
 	fclose(fp);
 }




