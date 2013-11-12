%{
 
/*
 * Lexer.l file
 * To generate the lexical analyzer run: "flex Lexer.l"
 */
#include <stdio.h> 
//#include "Expression.h"
#include "Parser.h"
#include "Common.h"
void p(int a){
#ifdef EDEBUG
printf("%d\n", a);
#endif
} 
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

{LETTER}({LETTER}|{DIGIT})*      { p(1); yylval->strval = estrdup(yytext); return(IDENTIFIER); }
0[xX]{HEX}+{INT_SUFFIX}?         { p(2); yylval->strval = estrdup(yytext); return(CONSTANT); }
0{DIGIT}+{INT_SUFFIX}?           { p(3); yylval->strval = estrdup(yytext); return(CONSTANT); }
{DIGIT}+{INT_SUFFIX}?            { p(4); yylval->strval = estrdup(yytext); return(CONSTANT); }
{DIGIT}+{EXP}{FLOAT_SUFFIX}?     { p(5); yylval->strval = estrdup(yytext); return(CONSTANT); }
{DIGIT}*"."{DIGIT}+({EXP})?{FLOAT_SUFFIX}? { p(6); yylval->strval = estrdup(yytext); return(CONSTANT); }
{DIGIT}+"."{DIGIT}*({EXP})?{FLOAT_SUFFIX}? { p(7); yylval->strval = estrdup(yytext); return(CONSTANT); }
L?\'(\\.|[^\\'])+\'             { p(8); yylval->strval = estrdup(yytext); return(CONSTANT); }
L?\"(\\.|[^\\"])*\"             { p(9); yylval->strval = estrdup(yytext); return(CONSTANT); }

L?\`(\\.|[^\\`])*\`             { p(10); yylval->strval = estrdup(yytext); return(CONSTANT); }

[;\n]+      { p(11); return(END_OF_STATEMENT); }
[ \t\v\r]  { }
<<EOF>>    { p(12); static int once = 0; return (once = !once) ? END_OF_FILE : 0; }


":"        { p(13);  return(':');}
"."        { p(13);  return('.');}
","        { p(13);  return(',');}
"{"        { p(13);  return('{');}
"}"        { p(13);  return('}');}
"["        { p(13);  return('[');}
"]"        { p(13);  return(']');}
"("        { p(13);  return('(');}
")"        { p(13);  return(')');}
"="        { p(13);  return('=');}


.     { printf("unmatched text: %d\n",yytext); }

%%

int yyerror(const char *msg) {
    fprintf(stderr,"Error:%s\n", msg); return 0;
}
