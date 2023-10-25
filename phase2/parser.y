%{
	#include<stdio.h>
	#include <string.h>
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
}

