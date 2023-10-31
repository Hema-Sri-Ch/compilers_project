--> compile it with 
		
  		yacc -d parser.y

--> Then compile your lexer with 

		lex lexer.l
  		gcc lex.yy.c y.tab.c -w

--> write your input in 'input.txt' file

--> test it with command

		./a.out

--> To simplify all the execution steps, the commands are written in a bash file 'run.sh'. Executing this file will automatically performs above steps. Here is the execution command

		bash run.sh
