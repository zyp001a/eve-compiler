# Makefile

FILES   = Parser.o Lexer.o Common.o Role.o Sociaty.o Eval.o Hash.o Platform.o Database.o Reader.o eve.o
CC      = gcc
CFLAGS  = -g
EVEFILE = eve

QUICKRUN = er
CCOMPILER = ec
TESTFILE = et

main:           $(FILES)
								$(CC) $(FILES) -o ${EVEFILE}
test:           $(FILES)
								${CC} -c -DETEST eve.c -o eve.o
	              $(CC) $(FILES) -o ${TESTFILE}
test2:          $(FILES)
								${CC} -c -DETEST test.c -o eve.o
	              $(CC) $(FILES) -o test
install:				${OUTFILE} ${QUICKRUN}
								cp -rf Eve ~/lib/.
								cp ${OUTFILE} ~/bin/${EVEFILE}
								cp ${CCOMPILER} ~/bin/${CCOMPILER}
								cp ${QUICKRUN} ~/bin/${QUICKRUN}
install-biology:
								cp -rf ../Biology ~/lib/.
Lexer.c:        Lexer.l 
	              flex Lexer.l
Parser.c:       Parser.y Lexer.c
	              bison -rstates -t -v Parser.y
%.o:            %.c %.h
								${CC} -g -c $< -o $@
clean:
	 			        rm -f *.o *~ Lexer.c Lexer.h Parser.c Parser.h ${EVEFILE}
