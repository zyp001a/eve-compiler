%{
 
/*
 * Lexer.l file
 * To generate the lexical analyzer run: "flex Lexer.l"
 */
#include <stdio.h> 
//#include "Expression.h"
#include "Parser.h"
#include "Common.h"
#include "Sociaty.h"
void p(int a){
#ifdef EDEBUG
printf("%d\n", a);
#endif
/*<<EOF>>    { p(12); static int once = 0; return (once = !once) ? END_OF_FILE : 0; }*/
}
/*
<INITIAL>"Run"               { BEGIN(RUN); return(NULL_TOKEN); }
<RUN>\n                         { BEGIN(0); return(NULL_TOKEN); }
<RUN>.                       { return(NULL_TOKEN); }
*/

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

%x PRINT
%x WRITE


%%

<INITIAL>"_Print\n"              { p(80); BEGIN(PRINT); return(NULL_TOKEN); }
<PRINT>"_EndPrint"               { p(81); BEGIN(0); return(NULL_TOKEN);}


<INITIAL>"_Write\n"              { p(82); BEGIN(WRITE); return(NULL_TOKEN); }
<WRITE>"_EndWrite"               { p(83); BEGIN(0); return(NULL_TOKEN);}

<PRINT,WRITE>(.|\n)             { p(84); Sociaty_PutChar(yytext[0]); return(NULL_TOKEN);}

"_Run".+                       { p(85); system(yytext+4);  return(NULL_TOKEN); }


"_SetArgs"                       { return SETARGS; }
"_SetFlag"                       { return SETFLAG; }
"_SetOut"                        { return SETOUT; }

"For"                            { return FOR; }
"If"                             { return IF; }
"Add"                            { return ADD; }
"Use"				                     { return USE; }


{LETTER}({LETTER}|{DIGIT})*      { p(1); yylval->strval = estrdup(yytext); return(IDENTIFIER); }
0[xX]{HEX}+{INT_SUFFIX}?         { p(2); yylval->strval = estrdup(yytext); return(CONSTANT); }
0{DIGIT}+{INT_SUFFIX}?           { p(3); yylval->strval = estrdup(yytext); return(CONSTANT); }
{DIGIT}+{INT_SUFFIX}?            { p(4); yylval->strval = estrdup(yytext); return(CONSTANT); }
{DIGIT}+{EXP}{FLOAT_SUFFIX}?     { p(5); yylval->strval = estrdup(yytext); return(CONSTANT); }
{DIGIT}*"."{DIGIT}+({EXP})?{FLOAT_SUFFIX}? { p(6); yylval->strval = estrdup(yytext); return(CONSTANT); }
{DIGIT}+"."{DIGIT}*({EXP})?{FLOAT_SUFFIX}? { p(7); yylval->strval = estrdup(yytext); return(CONSTANT); }
\'(\\.|[^\\'])+\'             { p(8); yylval->strval = estrcent(yytext); return(CONSTANT); }
\"(\\.|[^\\"])*\"             { p(9); yylval->strval = estrcent(yytext); return(CONSTANT); }

\`(\\.|[^\\`])*\`             { p(10); yylval->strval = estrcent(yytext); return(CONSTANT); }

[;\n]      { p(11); return(END_OF_STATEMENT); }
[ \t\v\r]  { }



":"        { p(13);  return(':');}
"."        { p(14);  return('.');}
","        { p(15);  return(',');}
"{"        { p(16);  return('{');}
"}"        { p(17);  return('}');}
"["        { p(18);  return('[');}
"]"        { p(19);  return(']');}
"("        { p(20);  return('(');}
")"        { p(21);  return(')');}
"="        { p(22);  return('=');}
"+"	       { p(22);  return('+');}
"-"	       { p(22);  return('-');}
"*"	       { p(22);  return('*');}
"/"	       { p(22);  return('/');}
"%"	       { p(22);  return('%');}
"^"	       { p(22);  return('^');}
"&"        { p(22);  return('&');}
"@"        { p(22);  return('@');}
"$"        { p(22);  return('$');}

.     { printf("unmatched text: %d\n",yytext); }

%%


int yyerror(const char *msg) {
    fprintf(stderr,"Error:%s\n", msg); return 0;
}
