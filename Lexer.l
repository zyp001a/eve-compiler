%{
 
/*
 * Lexer.l file
 * To generate the lexical analyzer run: "flex Lexer.l"
 */
#include <stdio.h> 
#include "Parser.h"
#include "Common.h"
#include "Sociaty.h"
#include "Eval.h"

#define LEXDEBUG
#ifdef LEXDEBUG
#define ld_print(s1, s2) \
  {\
    fprintf(stderr, "LINE %d: %s, %s\n", yylineno, s1, s2);\
  }
#else
#define ld_print(s1, s2) 
#endif

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



%%
\'(\\.|[^\\'])+\' { 
  ld_print("Read string1", yytext);
  yylval->strval = estrcent(yytext); 
  return(CONSTANT); 
}
\"(\\.|[^\\"])*\" { 
  ld_print("Read string2", yytext);
  yylval->strval = estrcent(yytext); 
  return(CONSTANT); 
}
\`(\\.|[^\\`])*\` { 
  ld_print("Read string3", yytext);
  yylval->strval = estrcent(yytext); 
  return(CONSTANT); 
}

"#".+ { 
  ld_print("Read comment1", yytext);
}

"//.+" { 
  ld_print("Read comment2", yytext);
}

"/*" {	
  ld_print("Read comment3", "");
  char c, c1;
loop:
  while ((c =input(yyscanner)) != '*' && c != 0){}
  if ((c1 = input(yyscanner)) != '/' && c != 0){
    unput(c1);
	  goto loop;
  }
  if(c!=0) {};
}

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
      ld_print("Read block", buf);
      return(BLOCK);
    }
    buf[j] = c;
    j++;
  }
}


"<".+ {
  char* fpath;
  fpath=GetPath(yytext+1);
  ld_print("Parse file", fpath);
	if(Sociaty_SearchUsedFile(fpath) == -1){
		Sociaty_AddUsedFile(fpath);
		ParseExpressionFromFile(fpath);
	}
}

">>"\S+ {
  ld_print("Append to file", yytext+2);
  Sociaty_SetOut(yytext+2, "a");
}

">"^>\S+ {
  ld_print("Write to file", yytext+1);
  Sociaty_SetOut(yytext+1, "w");
}

\^(\\.|[^\\\^])*\^ { 
  ld_print("Print string", yytext);
  char *str =  estrcent(yytext); 
  Sociaty_PutString(str);
  free(str); 

}


"~".+ { 
  ld_print("Run command", yytext+1);
  system(yytext+1);
}
"system".+ { 
  ld_print("Run command", yytext+6);
  system(yytext+6);
}

"**" {
  ld_print("TOKEN", "for");
  return FOR; 
}
"for" { 
  ld_print("TOKEN", yytext);
  return FOR; 
}

"--" {
  ld_print("TOKEN", "while");
  return WHILE;
}
"while" {
  ld_print("TOKEN", yytext);
  return WHILE;
}


"??" {
  ld_print("TOKEN", "if");
  return IF; 
}
"if" { 
  ld_print("TOKEN", yytext);
  return IF; 
}

"?:" {
  ld_print("TOKEN", "ifelse");
  return IFELSE;
}
"ifelse" {
  ld_print("TOKEN", yytext);
  return IFELSE; 
}

"!" {
  ld_print("TOKEN", "not");
  return NOT;
}
"not" {
  ld_print("TOKEN", yytext);
  return NOT;
}




"%%" {
  ld_print("TOKEN", "print");
  return PRINT;
}
"print" {
  ld_print("TOKEN", "print");
  return PRINT;
}

"+$" {
  ld_print("TOKEN", "add");
  return ADD;
}
"add" {
  ld_print("TOKEN", "add");
  return ADD; 
}

"&&" {
  ld_print("TOKEN", "invoke");
  return INVOKE; 
}
"invoke" {
  ld_print("TOKEN", "invoke");
  return INVOKE; 
}

"setargs" { 
  ld_print("TOKEN", yytext);
  return SETARGS; 
}
"setflag" { 
  ld_print("TOKEN", yytext);
  return SETFLAG; 
}



{LETTER}({LETTER}|{DIGIT})*  { 
  ld_print("Read identifier", yytext);
  yylval->strval = estrdup(yytext); 
  return(IDENTIFIER); 
}
0[xX]{HEX}+{INT_SUFFIX}?  { 
  ld_print("Read hex", yytext);
  yylval->strval = estrdup(yytext); 
  return(CONSTANT); 
}
0{DIGIT}+{INT_SUFFIX}? { 
  ld_print("Read oct", yytext);
  yylval->strval = estrdup(yytext); 
  return(CONSTANT); 
}
{DIGIT}+{INT_SUFFIX}? { 
  ld_print("Read int", yytext);
  yylval->strval = estrdup(yytext); 
  return(CONSTANT); 
}
{DIGIT}+{EXP}{FLOAT_SUFFIX}?  { 
  ld_print("Read float1", yytext);
  yylval->strval = estrdup(yytext); 
  return(CONSTANT); 
}
{DIGIT}*"."{DIGIT}+({EXP})?{FLOAT_SUFFIX}? { 
  ld_print("Read float2", yytext);
  yylval->strval = estrdup(yytext); 
  return(CONSTANT); 
}
{DIGIT}+"."{DIGIT}*({EXP})?{FLOAT_SUFFIX}? { 
  ld_print("Read float3", yytext);
  yylval->strval = estrdup(yytext); 
  return(CONSTANT); 
}



[;\n]   { 
  ld_print("TOKEN", "END_OF_STATEMENT");
  return(END_OF_STATEMENT); 
}

"+" { return '+'; }
":" { return ':'; }
"." { return '.'; } 
"," { return ','; }
"=" { return '='; }
"&" { return '&'; }
"[" { return '['; }
"]" { return ']'; }
")" { return ')'; }
"(" { return '('; }


"\\\n"     { }
[ \t\v\r]  { }



.     { ld_print("Unmatched text", yytext); }

%%

/*
int yyerror(const char *msg) {
    fprintf(stderr,"Error:%s\n", msg); return 0;
}
*/
