# Makefile

FILES   = Lexer.c Common.c Expression.c Parser.c Role.c Evaluate.c Sociaty.c main.c
CC      = g++
CFLAGS  = -g -ansi

test:           $(FILES)
	              $(CC) $(CFLAGS) $(FILES) -o test

Lexer.c:        Lexer.l 
	              flex Lexer.l

Parser.c:       Parser.y Lexer.c
	              bison Parser.y

clean:
	 			        rm -f *.o *~ Lexer.c Lexer.h Parser.c Parser.h test
