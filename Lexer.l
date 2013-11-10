%{
 
/*
 * Lexer.l file
 * To generate the lexical analyzer run: "flex Lexer.l"
 */
#include <stdio.h> 
#include "Expression.h"
#include "Parser.h"
#include "Common.h"
 
%}
 
%option outfile="Lexer.c" header-file="Lexer.h"
%option warn nodefault
 
%option reentrant noyywrap never-interactive nounistd
%option bison-bridge

DIGIT         [0-9]
LETTER        [a-zA-Z_]
HEX           [a-fA-F0-9]
EXP           [Ee][+-]?{DIGIT}+
FLOAT_SUFFIX  (f|F|l|L)
INT_SUFFIX    (u|U|l|L)* 


%%
{LETTER}({LETTER}|{DIGIT})*      { estrdup((char*)yylval, yytext); return(IDENTIFIER); }

0[xX]{HEX}+{INT_SUFFIX}?         { estrdup((char*)yylval, yytext); return(CONSTANT); }
0{DIGIT}+{INT_SUFFIX}?           { estrdup((char*)yylval, yytext); return(CONSTANT); }
{DIGIT}+{INT_SUFFIX}?            { estrdup((char*)yylval, yytext); return(CONSTANT); }
{DIGIT}+{EXP}{FLOAT_SUFFIX}?     { estrdup((char*)yylval, yytext); return(CONSTANT); }
{DIGIT}*"."{DIGIT}+({EXP})?{FLOAT_SUFFIX}? { estrdup((char*)yylval, yytext); return(CONSTANT); }
{DIGIT}+"."{DIGIT}*({EXP})?{FLOAT_SUFFIX}? { estrdup((char*)yylval, yytext); return(CONSTANT); }
L?\'(\\.|[^\\\'])+\'             { estrdup((char*)yylval, yytext); return(CONSTANT); }
L?\"(\\.|[^\\\"])*\"             { estrdup((char*)yylval, yytext); return(CONSTANT); }

[;\n]      { return(END_OF_STATEMENT); }

":"        { return(':');}
"."        { return('.');}
","        { return(',');}
"{"        { return('{');}
"}"        { return('}');}
"("        { return('(');}
")"        { return(')');}
"="        { return('=');}

.     {  }

%%

int yyerror(const char *msg) {
    fprintf(stderr,"Error:%s\n",msg); return 0;
}
