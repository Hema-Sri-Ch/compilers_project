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
%}

%union{
	int ival;
	float fval;
	char* str;
	struct{
		char* Val;
		char* type;
	} stmtStruct;
}

%type<stmtStruct> RHS declr_stmt arith_op

%token <str> newid
%token <str> INT_CONST
%token <str> FLOAT_CONST
%token <str> CHAR_CONST
%token <str> STR_CONST
%token <str> BOOL_CONST
%token ARROW
%token PUNC
%token <str> DATATYPE
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
						
						
model					: stmt
						;
						
stmt					: declr_stmt
						| expr_stmt
						;
						
declr_stmt				: DECLR DATATYPE newid ';' {$$.Val=$3; $$.type=$2; var_insert(1, $3, $2, 1, -1);}
						;
						
expr_stmt				: EXPR newid '=' RHS ';' {
								printf("%s = { %s, %s}\n", $2, $4.Val, $4.type); 
								int index=var_search($2); 
								if(strcmp(var_symb[index].type, $4.type)){
								 	printf("error\n"); exit(1);
								 }
							}
						;
						
RHS						: newid {$$.Val=$1; int index=var_search($1); if(index<0) exit(0); else $$.type=var_symb[index].type;}
						| INT_CONST {$$.Val=$1; $$.type="int";}
						| FLOAT_CONST {$$.Val=$1; $$.type="float";}
						| CHAR_CONST {$$.Val=$1; $$.type="char";}
						| STR_CONST {$$.Val=$1; $$.type="string";}
						| BOOL_CONST {$$.Val=$1; $$.type="bool";}
						| arith_op {$$.type=$1.type;}
						;
						
arith_op				: ARITHOP '(' RHS ',' RHS ')' {
								if(strcmp($3.type, "int") == 0 || strcmp($3.type, "float")==0 || strcmp($3.type, "bool")==0){
									if(strcmp($5.type, "int") == 0 || strcmp($5.type, "float")==0 || strcmp($5.type, "bool")==0){
										if(strcmp($3.type, "float")==0 || strcmp($5.type, "float")==0) $$.type="float";
										else $$.type="int";
									}
									else{
										printf("Invalid operand type\n");
										exit(0);
									}
								}
								else{
									printf("Invalid operand type\n");
									exit(0);
								}
							}
						| UNARYOP '(' RHS ')' {
								if(strcmp($3.type, "int")==0 || strcmp($3.type, "float")==0 || strcmp($3.type, "bool")==0){
									if(strcmp($3.type, "float")==0) $$.type="float";
									else $$.type="int";
								}
								else{
									printf("Invalid operand type\n");
									exit(0);
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




