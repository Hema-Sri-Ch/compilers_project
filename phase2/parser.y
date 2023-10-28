%{
/*

--> Remove the undeclared variables in the grammer rule of 'statement' while testing your code. Those variables will be declared by your teammates soon. (line no: 109)

--> Give understandable names to the variables while writting grammar so that others can understand your code

--> compile it with 
		
  		yacc -d parser.y

--> Then compile your lexer with 

		lex lexer.l
  		gcc lex.yy.c y.tab.c

--> write your testcase in 'inp' file

--> test it with command

		./a.out <inp
		
--> This will automatically read from the file 'inp'
*/

	#include<stdio.h>
	#include <string.h>
	#include <stdlib.h>
	extern int yylineno;
	extern FILE* yyin, *yyout;
    FILE* fparse;
	int yylex(void);
	int yyerror(const char *s);
%}

%token tokenA
%token id
%token INT_CONST
%token FLOAT_CONST
%token CHAR_CONST
%token STR_CONST
%token BOOL_CONST
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
%token EXP
%token UNARYOP
%token DECLR
%token EXPR
%token CALL
%token FUNC
%token LOOP
%token null


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
						
class					: tokenA
						;
						
struct					: id
						;
						
function				: function_head function_body
						;
						
function_head			: FUNC dtype id '(' ')' {fprintf(fparse, " : FUNCTION HEAD");}
						| FUNC dtype id '(' param_list ')' {fprintf(fparse, " : FUNCTION HEAD");}
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
						;
						
expr_stmt				: EXPR id '=' RHS ';' {fprintf(fparse, " : EXPRESSION STATEMENT");}
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

ifcond_stmt				: IF '(' cond_res ')' {fprintf(fparse, " : CONDITIONAL STATEMENT");} if_body
						;

if_body					: '{' statements '}' ELSE '{' statements '}'
						| '{' statements '}'
						;

switch_stmt				: SWITCH '(' cond_res ')' {fprintf(fparse, " : CONDITIONAL STATEMENT");} switch_body
						;

switch_body				: '{' cases DEFAULT ':' '{' statements '}' '}'
						;

cases					: CASE INT_CONST ':' '{' statements '}' cases
						| CASE INT_CONST ':' '{' statements '}'
						;

cond_res				: INT_CONST
						| logical_op
						;
						
RHS						: constants
						| arith_op
						| logical_op
						| func_calls
						;
						
constants				: INT_CONST
						| FLOAT_CONST
						| CHAR_CONST
						| STR_CONST
						| BOOL_CONST
						| array_const
						| graph_const
						| matrix_const
						| vect_const
						| id
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
						;
						
vect_const				: '{' vect_list '}'
						;

vect_list				: INT_CONST ',' vect_list
						| CHAR_CONST ',' vect_list
						| FLOAT_CONST ',' vect_list
						| BOOL_CONST ',' vect_list
						| STR_CONST ',' vect_list
						| id ',' vect_list
						| vect_const ',' vect_list
						| '{' '}' ',' vect_list
						| INT_CONST
						| CHAR_CONST
						| FLOAT_CONST
						| BOOL_CONST
						| STR_CONST
						| id
						| vect_const
						| '{' '}'
						;
						
matrix_const			: '-'
						;
						
arith_op				: binary_op
						| unary_op
						;
						
binary_op				: ARITHOP '(' RHS ',' RHS ')'
						;
						
unary_op				: UNARYOP '(' RHS ')'
						;
						
logical_op				: '(' RHS LOGOP RHS ')'
						;
						
call_stmt				: func_calls ';' {fprintf(fparse, " : CALL STATEMENT");}
						;
						
func_calls				: CALL id '(' arg_list ')'
						| CALL id '(' ')'
						| CALL id '.' id '(' arg_list ')'
						| CALL id '.' id '(' ')'
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




