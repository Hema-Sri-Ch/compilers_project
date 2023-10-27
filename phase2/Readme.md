--> Remove the undeclared variables in the grammer rule of 'statement' while testing your code. Those variables will be declared by your teammates soon.

--> Give understandable names to the variables while writting grammar so that others can understand your code

--> compile it with 
		
  		yacc -d parser.y

--> Then compile your lexer with 

		lex lexer.l
  		gcc lex.yy.c y.tab.c -w

--> write your testcase in 'inp' file

--> test it with command

		./a.out
		
--> This will automatically read from the file 'inp'
