%option yylineno

%{
	# include <stdio.h>
	# include <string.h>
	# include <stdlib.h>
	# include "y.tab.h"
	extern FILE* fparse;
	// extern int yyleng;
%}

%%

!![^(!!)]*!! {
	fprintf(yyout, "comment: %s\n", yytext);
	fprintf(fparse, "%s", yytext);
}

"add_matx"|"sub_matx"|"mult_matx" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    yylval.str=strdup(yytext);
    return MATXOP;
}

"matxtograph" {
	fprintf(yyout, "Identifier: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    yylval.str=strdup(yytext);
    return MAXTOGR;
}

"graphtomatx" {
	fprintf(yyout, "Identifier: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    yylval.str=strdup(yytext);
    return GRTOMATX;
}

"shpathval" {
	fprintf(yyout, "Identifier: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    yylval.str=strdup(yytext);
    return SHPATHVAL;
}

"shpath" {
	fprintf(yyout, "Identifier: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    yylval.str=strdup(yytext);
    return SHPATH;
}

"append" {
	fprintf(yyout, "Identifier: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    yylval.str=strdup(yytext);
    return APPEND;
}

"remove" {
	fprintf(yyout, "Identifier: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    yylval.str=strdup(yytext);
    return REMOVE;
}

"length" {
	fprintf(yyout, "Identifier: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    yylval.str=strdup(yytext);
    return LENGTH;
}

"sort" {
	fprintf(yyout, "Identifier: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    yylval.str=strdup(yytext);
    return SORT;
}

"clear" {
	fprintf(yyout, "Identifier: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    yylval.str=strdup(yytext);
    return CLEAR;
}

"at" {
	fprintf(yyout, "Identifier: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    yylval.str=strdup(yytext);
    return AT;
}

"transpose" {
	fprintf(yyout, "Identifier: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    yylval.str=strdup(yytext);
    return TRANSPOSE;
}

"trace" {
	fprintf(yyout, "Identifier: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    yylval.str=strdup(yytext);
    return TRACE;
}

"dfs"|"bfs" {
	fprintf(yyout, "Identifier: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    return TRAVERSAL;
}

"strlen" {
	fprintf(yyout, "Identifier: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    yylval.str=strdup(yytext);
    return STRLEN;
}

"strcut" {
	fprintf(yyout, "Identifier: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    yylval.str=strdup(yytext);
    return STRCUT;
}

"strcmp" {
	fprintf(yyout, "Identifier: %s\n", yytext);
	fprintf(fparse, "%s", yytext);
	yylval.str=strdup(yytext);
	return STRCMP;
}

"strjoin" {
	fprintf(yyout, "Identifier: %s\n", yytext);
	fprintf(fparse, "%s", yytext);
	yylval.str=strdup(yytext);
	return STRJOIN;
}

"int"|"char"|"string"|"bool"|"float" {
	fprintf(yyout, "datatype: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("datatype: %s\n", yytext);
	yylval.str=strdup(yytext);
    return DATATYPE;
}

"void" {
    fprintf(yyout, "datatype: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("datatype: %s\n", yytext);
	yylval.str=strdup(yytext);
    return VOID;
}

"return" {
    fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
    return RETURN;
}

"if" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return IF;
}

"else" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return ELSE;
}

"continue" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return CONTINUE;
}

"break" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return BREAK;
}

"matrix" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
	yylval.str=strdup(yytext);
    return MATRIX;
}

"graph" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
	yylval.str=strdup(yytext);
    return GRAPH;
}

"vect" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
	yylval.str=strdup(yytext);
    return VECT;
}

"switch" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return SWITCH;
}

"case" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return CASE;
}

"default" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return DEFAULT;
}

"class" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return CLASS;
}

"struct" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return STRUCT;
}

"and"|"or"|"lt"|"gt"|"gte"|"eq"|"neq"|"lte" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return LOGOP;
}

"add"|"sub"|"mul"|"div"|"exp" {
	fprintf(yyout, "operator: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("operator: %s\n", yytext);
    return ARITHOP;
}

"not" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return NOT;
}

"incr"|"decr" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return UNARYOP;
}

"declr" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return DECLR;
}

"expr" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return EXPR;
}

"call" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return CALL;
}

"func" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return FUNC;
}

"loop" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return LOOP;
}

"for" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return FOR;
}

"while" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return WHILE;
}
"null" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
    fprintf(fparse, "%s", yytext);
	// printf("reserved keyword: %s\n", yytext);
    return null;
}

"goto" {
	fprintf(yyout, "reserved keyword: %s\n", yytext);
	fprintf(fparse, "%s", yytext);
	return GOTO;
}

\'[^']\' {
    fprintf(yyout, "constant: %s\n", yytext);
	fprintf(fparse, "%s", yytext);
	yylval.str=strdup(yytext);
    return CHAR_CONST;
}

\"[^"]*\" {
    fprintf(yyout, "constant: %s\n", yytext);
	fprintf(fparse, "%s", yytext);
	yylval.str=strdup(yytext);
    return STR_CONST;
}

-?[0-9]+ {
    fprintf(yyout, "constant: %s\n", yytext);
	fprintf(fparse, "%s", yytext);
	yylval.str=strdup(yytext);
    return INT_CONST;
}

"true"|"false" {
    fprintf(yyout, "constant: %s\n", yytext);
	fprintf(fparse, "%s", yytext);
	yylval.str=strdup(yytext);
    return BOOL_CONST;
}

"->" {
	fprintf(yyout, "Special symbols: %s\n", yytext);
	fprintf(fparse, "%s", yytext);
    return ARROW;
}

-?[0-9]+[.][0-9]+ {
    fprintf(yyout, "constant: %s\n", yytext);
	fprintf(fparse, "%s", yytext);
	yylval.str=strdup(yytext);
    return FLOAT_CONST;
}


[a-zA-Z_][a-zA-Z0-9_]* {
	fprintf(yyout, "Identifier : %s\n", yytext);
	fprintf(fparse, "%s", yytext);
	yylval.str = strdup(yytext);
	return newid;
}

[;:,\'\".] {
	fprintf(yyout, "Punctuation : %s\n", yytext);
	fprintf(fparse, "%s", yytext);
	return yytext[0];
}

[\n\t ] {
	fprintf(fparse, "%s", yytext);
    // Ignore newline characters for now.
}

[\[\](){}=<>] {
	fprintf(yyout, "Special symbols:	%s\n", yytext);
	fprintf(fparse, "%s", yytext);
	return yytext[0];
}

. {
	// printf("EXTRA:	%s\n", yytext);
	fprintf(yyout, "invalid statement in lexer");
    exit(1);
}



%%

int yywrap()
{
	return 1;
}

/*
int main(){
	while(yylex());
	return 0;
}
*/
