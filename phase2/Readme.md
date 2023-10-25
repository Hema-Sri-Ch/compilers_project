--> Define token names from line 8 in 'parser.y'
--> compile it with 'yacc -d parser.y'
--> Then compile your lexer with 
		lex lexer.l
		gcc lex.yy.c
--> write your testcase in 'inp' file
--> test it with command
		./a.out <inp
		
--> This will automatically read from the file 'inp'
