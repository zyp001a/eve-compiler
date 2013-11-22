# Makefile

FILES   = Parser.o Lexer.o Common.o Role.o Sociaty.o Eval.o Hash.o main.o
CC      = gcc
CFLAGS  = -g

test:           $(FILES)
	              $(CC) $(FILES) -o test

Lexer.c:        Lexer.l 
	              flex Lexer.l

Parser.c:       Parser.y Lexer.c
	              bison -rstates -t -v Parser.y
%.o:            %.c
								${CC} -c $< -o $@
clean:
	 			        rm -f *.o *~ Lexer.c Lexer.h Parser.c Parser.h test
