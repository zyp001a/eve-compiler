/*
modified from the verison
  http://www.lysator.liu.se/c/ANSI-C-grammar-l.html

Author: setupX
*/

DIGIT         [0-9]
LETTER        [a-zA-Z_]
HEX           [a-fA-F0-9]
EXP           [Ee][+-]?{DIGIT}+
FLOAT_SUFFIX  (f|F|l|L)
INT_SUFFIX		(u|U|l|L)*

%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
void count();
%}

%%
"/*"			{ comment(); }


{LETTER}({LETTER}|{DIGIT})*      { count(); return(check_type()); }


0[xX]{HEX}+{INT_SUFFIX}?         { count(); return(CONSTANT); }
0{DIGIT}+{INT_SUFFIX}?		       { count(); return(CONSTANT); }
{DIGIT}+{INT_SUFFIX}?		         { count(); return(CONSTANT); }
{DIGIT}+{EXP}{FLOAT_SUFFIX}?	   { count(); return(CONSTANT); }
{DIGIT}*"."{DIGIT}+({EXP})?{FLOAT_SUFFIX}? { count(); return(CONSTANT); }
{DIGIT}+"."{DIGIT}*({EXP})?{FLOAT_SUFFIX}? { count(); return(CONSTANT); }
L?\'(\\.|[^\\\'])+\'	           { count(); return(CONSTANT); }
L?\"(\\.|[^\\\"])*\"	           { count(); return(CONSTANT); }
\{\{(\\.|[^\\\}\\\}])*\}\}		   { count(); return(CODEBLOCK); }

[;\n] { count(); return(END_OF_STATEMENT); }
<<EOF>>	  {yyterminate();  return(END_OF_STATEMENT); }
[ \t\v\f]		{ count(); }
":"        { count(); return(':');}
"."        { count(); return('.');}
","        { count(); return(',');}
"{"        { count(); return('{');}
"}"        { count(); return('}');}
"("        { count(); return('(');}
")"        { count(); return(')');}
"="        { count(); return('=');}

.			{ /* ignore bad characters */ }

%%

yywrap()
{
		return(1);
}


comment()
{
		char c, c1;

loop:
		while ((c = input()) != '*' && c != 0)
				putchar(c);
		
		if ((c1 = input()) != '/' && c != 0)
		{
				unput(c1);
				goto loop;
		}

		if (c != 0)
				putchar(c1);
}


int column = 0;
void count()
{

		int i;

		for (i = 0; yytext[i] != '\0'; i++)
				if (yytext[i] == '\n')
						column = 0;
				else if (yytext[i] == '\t')
						column += 8 - (column % 8);
				else
						column++;

    yylval.strval = strdup(yytext);

}



int check_type()
{
/*
* pseudo code --- this is what it should check
*
*	if (yytext == type_name)
*		return(TYPE_NAME);
*
*	return(IDENTIFIER);
*/

/*
*	it actually will only return IDENTIFIER
*/

		return(IDENTIFIER);
}
