%{
	#include<stdio.h>
	#include <string.h>
	int yylex(void);
	int yyerror(const char *s);
%}

%token tokenA
%token id

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

