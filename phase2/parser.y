%{
	#include<stdio.h>
	#include <string.h>
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
%token FUNC
%token LOOP
%token null


%start program_unit

%%
program_unit			: tokenA
 						;
%%


int yyerror(const char *msg)
{
	extern int yylineno;
	printf("Parsing Failed\nLine Number: %d %s\n",yylineno,msg);
	fprintf(yyout, " : invalid statement");
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




