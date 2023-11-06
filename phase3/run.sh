yacc -d sample.y
lex lexer.l
gcc lex.yy.c y.tab.c
./a.out
