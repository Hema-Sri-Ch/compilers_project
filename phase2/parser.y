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
	extern int yylineno;
	// extern FILE* yyin, *yyout;
    // FILE* fparse;
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
						
function_head			: FUNC dtype id '(' ')' {printf("\n\n FUNCTION HEAD \n\n");}
						;
						
dtype					: DATATYPE
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
						;
						
expr_stmt				: EXPR id '=' RHS ';' {printf("\n\n EXPRESSION STATEMENT \n\n");}
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
						;
						

array_const				: '{' val_list '}'
						| '{' '}'
						;
						
val_list				: val ',' val_list
						| val
						;
						
val						: INT_CONST
						| FLOAT_CONST
						| CHAR_CONST
						| BOOL_CONST
						| STR_CONST
						;
						
graph_const				: '*'
						;
						
vect_const				: '+'
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
						
call_stmt				: func_calls ';' {printf("\n\n CALL STATEMENT \n\n");}
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


int main(){
	yyparse();
	return 0;
}


int yyerror(const char *msg)
{
	extern int yylineno;
	printf("Parsing Failed\nLine Number: %d %s\n",yylineno,msg);
	printf( " : invalid statement");
	return 0;
	// fprintf(fparse, " : invalid statement");
	// exit(0);
}

// main() {
// 	    FILE* fp = fopen(input.txt, "r");
//      yyin = fp;
//      fparse = fopen(parsed.txt, "w");
//  	FILE* ft = fopen(tokens.txt, "w");
//  	yyout = ft;
//
//  	yyparse();
//  
//  	fclose(fparse);
//  	fclose(ft);
//  	fclose(fp);
// }




