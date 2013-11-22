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
<INITIAL>"Run"               { BEGIN(RUN); return(STATEMENT); }
<RUN>\n                         { BEGIN(0); return(STATEMENT); }
<RUN>.                       { return(STATEMENT); }
*/
//extern yyscan_t current_scanner
%}

 
%option outfile="Lexer.c" header-file="Lexer.h"
%option warn nodefault yylineno 
 
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

<INITIAL>"_Print\n"              { p(80); BEGIN(PRINT); return(STATEMENT); }
<PRINT>"_EndPrint"               { p(81); BEGIN(0); yytext[yyleng-9] = '\0'; printf("%s\n", yytext);return(STATEMENT);}


<INITIAL>"_Write\n"              { p(82); BEGIN(WRITE); return(STATEMENT); }
<WRITE>"_EndWrite"               { p(83); BEGIN(0); return(STATEMENT);}

<PRINT,WRITE>(.|\n)             { p(84); 
//Sociaty_PutChar(yytext[0]);  
yymore(); return(STATEMENT);
}
"_Run".+                       { p(85); system(yytext+4);  return(STATEMENT); }
">".+          { p(85); system(yytext+1);  return(STATEMENT); }
"~".+          { p(85); Sociaty_PutString(yytext+1);  return(STATEMENT); }
"#".+          { p(85);  return(STATEMENT); }
\^(\\.|[^\\\^])*\^             { p(10); char *str =  estrcent(yytext); Sociaty_PutString(str); free(str); return(STATEMENT); }
"{" {
char c,c1;
char buf[MAX_BLOCK_SIZE];
int i=1;
int j=0;
while (1){
  c =input(yyscanner);
  if(c=='{') i++; 
  else if(c=='}') i--;
	if(i==0){
    buf[j] = '\n';
    buf[j+1] = '\0';
    yylval->strval = estrdup(buf);
    return(BLOCK);
  }
  buf[j] = c;
  j++;
}

}
"//.+"         {}
"/*"                          {	char c, c1;
//printf("%d\n",yylineno);
printf("%s\n", yyg->yy_c_buf_p);
loop:
while ((c =input(yyscanner)) != '*' && c != 0){}
if ((c1 = input(yyscanner)) != '/' && c != 0){
  unput(c1);
	goto loop;
}
if(c!=0) {};
}
"_SetArgs"                       { p(85);return SETARGS; }
"_SetFlag"                       { p(85);return SETFLAG; }
"_SetOut"                        { p(85); return SETOUT; }

"For"                            { p(85);return FOR; }
"If"                             { p(85);return IF; }
"IfElse"                         { p(85);return IFELSE; }
"Add"                            { p(85);return ADD; }
"Use"				                     { p(85);return USE; }


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

"\\\n"     { /*skip*/}
[;\n]      { p(11); return(END_OF_STATEMENT); }
[ \t\v\r]  { p(99);}



":"        { p(13);  return(':');}
"."        { p(14);  return('.');}
","        { p(15);  return(',');}

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

/*
int yyerror(const char *msg) {
    fprintf(stderr,"Error:%s\n", msg); return 0;
}
*/
