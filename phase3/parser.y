%{
	#include<stdio.h>
	#include <string.h>
	#include <stdlib.h>
	extern int yylineno;
	extern FILE* yyin, *yyout;
    FILE* fparse;
	int yylex(void);
	int yyerror(const char *s);
%}

%token newid
%token INT_CONST
%token FLOAT_CONST
%token CHAR_CONST
%token STR_CONST
%token BOOL_CONST
%token ARROW
%token PUNC
%token DATATYPE
%token VOID
%token RETURN
%token IF
%token ELSE
%token CONTINUE
%token BREAK
%token MATRIX
%token GRAPH
%token VECT
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
%token APPEND
%token REMOVE
%token LENGTH
%token SORT
%token CLEAR
%token AT
%token TRANSPOSE
%token TRACE
%token TRAVERSAL
%token STRLEN
%token STRCUT
%token STRCMP
%token STRJOIN
%token MATXOP
%token MAXTOGR
%token GRTOMATX
%token SHPATH
%token SHPATHVAL
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
						
class					: CLASS id '{' class_items '}' ';' {fprintf(fparse, " : CLASS DEFINITION");}
						;

id						: newid
						| APPEND
						| REMOVE
						| LENGTH
						| SORT
						| CLEAR
						| AT
						| TRANSPOSE
						| TRACE
						| TRAVERSAL
						| STRLEN
						| STRCUT
						| STRJOIN
						| STRCMP
						| MAXTOGR
						| GRTOMATX
						| SHPATH
						| SHPATHVAL
						;
						
class_items				: class_item class_items
						| class_item
						;
						
class_item				: declr_stmt
						| function
						;
						
struct					: STRUCT id '{' struct_items '}' ';' {fprintf(fparse, " : STRUCT DEFINITION");}
						;
						
struct_items			: declr_stmt struct_items
						| declr_stmt
						;
						
function				: function_head function_body
						;
						
function_head			: FUNC fdtype id '(' ')' {fprintf(fparse, " : FUNCTION HEAD");}
						| FUNC fdtype id '(' param_list ')' {fprintf(fparse, " : FUNCTION HEAD");}
						;
						
fdtype					: dtype
						| VOID
						;
						
param_list				: dtype id ',' param_list
						| dtype id
						;
						
dtype					: DATATYPE
						| MATRIX
						| GRAPH
						| VECT '<' dtype '>'
						| id
						;
						
function_body			: '{' statements '}'
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
						
expr_stmt				: EXPR LHS '=' RHS ';' {fprintf(fparse, " : EXPRESSION STATEMENT");}
						| EXPR LHS '=' extra_consts ';' {fprintf(fparse, " : EXPRESSION STATEMENT");}
						| EXPR LHS '=' graph_impr ';' {fprintf(fparse, " : EXPRESSION STATEMENT");}
						| EXPR LHS '=' matrix_impr ';' {fprintf(fparse, " : EXPRESSION STATEMENT");}
						| EXPR LHS '=' vect_stmt_body ';' {fprintf(fparse, " : EXPRESSION STATEMENT");}
						;
						
LHS						: id
						| id ARROW LHS
						;

declr_stmt				: DECLR declr_body ';' {fprintf(fparse, " : DECLARATION STATEMENT");}

declr_body				: DATATYPE id_list
						| GRAPH graph_and_array_list
						| VECT '<' dtype '>' id_list
						| MATRIX matrix_list 
						| DATATYPE graph_and_array_list
						| STRUCT id id_list
						| CLASS id id_list
						;

graph_and_array_list	: id '[' INT_CONST ']' ',' graph_and_array_list
						| id '[' INT_CONST ']'
						;

matrix_list				: id '[' INT_CONST ']' '[' INT_CONST ']' ',' matrix_list
						| id '[' INT_CONST ']' '[' INT_CONST ']'
						;

id_list					: id ',' id_list
						| id
						;

ifcond_stmt				: IF '(' RHS ')' {fprintf(fparse, " : CONDITIONAL STATEMENT");} if_body
						;

if_body					: function_body ELSE function_body
						| function_body
						;

switch_stmt				: SWITCH '(' RHS ')' {fprintf(fparse, " : CONDITIONAL STATEMENT");} switch_body
						;

switch_body				: '{' cases DEFAULT ':' function_body '}'
						;

cases					: CASE INT_CONST ':' function_body cases
						| CASE INT_CONST ':' function_body
						;

						
RHS						: constants
						| arith_op
						| logical_op
						| func_calls
						| impr
						;						

						
constants				: INT_CONST
						| FLOAT_CONST
						| CHAR_CONST
						| STR_CONST
						| BOOL_CONST
						| LHS
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
						| resultant '.' SHPATHVAL '(' remove_body ',' remove_body ')'
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
						
binary_op				: ARITHOP '(' RHS ',' RHS ')'
						;
						
unary_op				: UNARYOP '(' RHS ')'
						;
						
logical_op				: '(' RHS LOGOP RHS ')'
						| NOT '(' RHS ')'
						;
						
call_stmt				: func_calls ';' {fprintf(fparse, " : CALL STATEMENT");}
						;
						
func_calls				: CALL LHS '(' arg_list ')'
						| CALL LHS '(' ')'
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
 	FILE* fp = fopen("input.txt", "r");
    yyin = fp;
    fparse = fopen("parsed.txt", "w");
 	FILE* ft = fopen("tokens.txt", "w");
 	yyout = ft;

 	yyparse();

	fclose(fparse);
 	fclose(ft);
 	fclose(fp);
 }




