%{
 
/*
 * EvalLexer.l file
 * To generate the lexical analyzer run: "flex EvalLexer.l"
 */
#include <stdio.h> 
} 
%}
 
%option outfile="EvalLexer.c" header-file="EvalLexer.h"
%option warn nodefault
 
%option reentrant noyywrap never-interactive nounistd


DIGIT         [0-9]
LETTER        [a-zA-Z_]

%%

${LETTER}({LETTER}|{DIGIT})*      { yylval->strval = estrdup(yytext); return(IDENTIFIER); }

.     { ECHO; }

%%

int yyerror(const char *msg) {
    fprintf(stderr,"Error:%s\n", msg); return 0;
}
void EvalLexerFromString()
    yyscan_t scanner;
                           YY_BUFFER_STATE buf;
     
                           yylex_init( &scanner );
                           yytext[yyleng-1] = ' ';
     
                           buf = yy_scan_string( yytext + 5, scanner );
                           yylex( scanner );
     
                           yy_delete_buffer(buf,scanner);
                           yylex_destroy( scanner );
