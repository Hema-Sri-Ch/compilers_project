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

\'[^']\' {
    printf("CHAR_CONST: %s\n", yytext);
    return CHAR_CONST;
}

\"[^"]*\" {
    printf("STR_CONST: %s\n", yytext);
    return STR_CONST;
}

[0-9]+ {
    printf("INT_CONST: %s\n", yytext);
    return INT_CONST;
}

"true"|"false" {
    printf("BOOL_CONST: %s\n", yytext);
    return BOOL_CONST;
}

[0-9]+[.][0-9]+ {
    printf("FLOAT_CONST: %s\n", yytext);
    return FLOAT_CONST;
}


[a-zA-Z_][a-zA-Z0-9_]* {
	printf("Identifier : %s\n", yytext);
	return ID;
}
[;:,\'\".] {
	printf("Punctuation : %s\n", yytext);
	return PUNC;
}

\n {
    // Ignore newline characters for now.
}

. {
	printf("%s\n", yytext);
}



%%

int yywrap(){}

int main(){
	while(yylex());
	return 0;
}
