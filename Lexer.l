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


{LETTER}({LETTER}|{DIGIT})*      { yylval->strval = estrdup(yytext); return(IDENTIFIER); }

0[xX]{HEX}+{INT_SUFFIX}?         { yylval->strval = estrdup(yytext); return(CONSTANT); }
0{DIGIT}+{INT_SUFFIX}?           { yylval->strval = estrdup(yytext); return(CONSTANT); }
{DIGIT}+{INT_SUFFIX}?            { yylval->strval = estrdup(yytext); return(CONSTANT); }
{DIGIT}+{EXP}{FLOAT_SUFFIX}?     { yylval->strval = estrdup(yytext); return(CONSTANT); }
{DIGIT}*"."{DIGIT}+({EXP})?{FLOAT_SUFFIX}? { yylval->strval = estrdup(yytext); return(CONSTANT); }
{DIGIT}+"."{DIGIT}*({EXP})?{FLOAT_SUFFIX}? { yylval->strval = estrdup(yytext); return(CONSTANT); }
L?\'(\\.|[^\\\'])+\'             { yylval->strval = estrdup(yytext); return(CONSTANT); }
L?\"(\\.|[^\\\"])*\"             { yylval->strval = estrdup(yytext); return(CONSTANT); }
\{\{(\\.|[^\\\}\\\}])*\}\}       { yylval->strval = estrdup(yytext); return(BLOCK); }
\[\[(\\.|[^\\\]\\\]])*\]\]       { printf("ll-%s\n",yytext); yylval->strval = estrdup(yytext); return(BLOCK); }

[;\n]+      { return(END_OF_STATEMENT); }
[ \t\v\r]  { }
<<EOF>>    { yyterminate(); }

":"        { return(':');}
"."        { return('.');}
","        { return(',');}
"{"        { return('{');}
"}"        { return('}');}
"["        { return('[');}
"]"        { return(']');}
"("        { return('(');}
")"        { return(')');}
"="        { return('=');}


.     { printf("unmatched text: %d\n",yytext); }

%%

int yyerror(const char *msg) {
    fprintf(stderr,"Error:%s\n",msg); return 0;
}
