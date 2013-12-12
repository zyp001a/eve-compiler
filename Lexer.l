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
    fprintf(ns.Err, "LINE %d: %s, %s\n", yylineno, s1, s2);\
  }
#else
#define ld_print(s1, s2) 
#endif
extern Sociaty ns;
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
\'(\\.|[^\\'])*\' { 
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
\#{DIGIT}+\# {
  ld_print("Read address", yytext);
  yylval->strval = estrcent(yytext);
  return(ADDRESS);
}


"#".+ { 
  ld_print("Read comment1", yytext);
}

"//".+ { 
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

^"<<<".+ {
  char* fpath;
  char *content;	
  FILE *fp;
  fpath=GetPath(yytext+3);
  if(fpath == NULL){
    eerror("fail to read file");
    eerror(yytext+3);
    exit(1);
  }
  ld_print("Read file", fpath);
  fp = fopen(fpath, "r");
  content = ereadfile(fp);
  Sociaty_PutString(content);
}
^"<<".* {
  char *fpath;
	Sociaty_SetIn(yytext+2, "r");
}
^"<".* {
  char *fpath;
  fpath = UseFile(yytext+1);
  if(fpath != NULL)
		ParseExpressionFromFile(fpath);	
}
"use" {
  ld_print("TOKEN", yytext);
  return USE;
}
"load" {
  ld_print("TOKEN", yytext);
  return LOAD;
}



^">>".* {
  ld_print("Append to file", yytext);
  Sociaty_SetOut(yytext+2, "a");
}

^">".* {
  ld_print("Write to file", yytext);
  Sociaty_SetOut(yytext+1, "w");
}

\^(\\.|[^\\\^])*\^ { 
  ld_print("Print string", yytext);
  yylval->strval =  estrcent(yytext); 
//  Sociaty_PutString(str);
//  free(str); 
  return PUTSTR;
}
"print" {
  ld_print("TOKEN", "print");
  return PRINT;
}


"~".+ { 
  ld_print("Run command", yytext+1);
  system(yytext+1);
}
"system".+ { 
  ld_print("Run command", yytext+6);
  system(yytext+6);
}


"!" {
  ld_print("TOKEN", "not");
  return NOT;
}
"not" {
  ld_print("TOKEN", yytext);
  return NOT;
}
"isfile" {
  ld_print("TOKEN", yytext);
  return ISFILE;
}
"isdir" {
  ld_print("TOKEN", yytext);
  return ISDIR;
}


"getenv" {
   Sociaty_WriteMembers();
}


"for" { 
  ld_print("TOKEN", yytext);
  return FOR; 
}


"while" {
  ld_print("TOKEN", yytext);
  return WHILE;
}
"if" { 
  ld_print("TOKEN", yytext);
  return IF; 
}
"elsif" {
  ld_print("TOKEN", yytext);
  return ELSIF; 
}
"else" {
  ld_print("TOKEN", yytext);
  return ELSE; 
}


"add" {
  ld_print("TOKEN", "add");
  return ADD; 
}

"invoke" {
  ld_print("TOKEN", "invoke");
  return INVOKE; 
}

"value" {
	ld_print("TOKEN", "value");
  return VALUE;
}
"readfile" {
  ld_print("TOKEN", "readfile");
  return READFILE;
}
"parsefile" {
  ld_print("TOKEN", yytext);
  return PARSEFILE;
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
{DIGIT}+ { 
  ld_print("Read int", yytext);
  yylval->strval = estrdup(yytext); 
  return(INTEGER); 
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
"%" { return '%'; }
"$" { return '$'; }
"@" { return '@'; }
"[" { return '['; }
"]" { return ']'; }
")" { return ')'; }
"(" { return '('; }
">" { return '>'; }
"<" { return '<'; }
"|" { return '|'; }

"\\\n"     { }
[ \t\v\r]  { }



.     { 
  ld_print("Unmatched text", yytext); 
	fprintf(stderr, "Unmatched text %s\n", yytext); 
}

%%

/*
int yyerror(const char *msg) {
    fprintf(stderr,"Error:%s\n", msg); return 0;
}
*/
