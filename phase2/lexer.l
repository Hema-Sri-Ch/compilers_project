%option yylineno

%{

/*
	
	--> Define token names from line 8 in 'parser.y'
	--> compile it with 'yacc -d parser.y'
	--> Then compile your lexer with 
			lex lexer.l
			gcc lex.yy.c
	--> write your testcase in 'inp' file
	--> test it with command
			./a.out <inp
		
	--> This will automatically read from the file 'inp'
	
	--> remove the lines with your names, before testing

*/

	# include <stdio.h>
	# include <string.h>
	# include <stdlib.h>
	# include "y.tab.h"
	extern int yyleng;
%}

%%

"abc" {
	printf("%s\n", yytext);
	return tokenA;
}

# Sandya

# Akshay

# Hema

# Vennela

. {
	printf("%s\n", yytext);
}



%%

int yywrap(){}

int main(){
	yylex();
	return 0;
}
