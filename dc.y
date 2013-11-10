/*http://www.lysator.liu.se/c/ANSI-C-grammar-y.html*/
%{
	
#include <stdio.h>
#include <string.h>
//#include "symbtable.h"
#include "symhierachy.h"
int yylex(void);
extern int column;
void yyerror(char *);
void scancode(char *);
#define YYPARSE_PARAM scanner
#define YYLEX_PARAM   scanner
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif
%}


%token CONSTANT IDENTIFIER CODEBLOCK
%token END_OF_STATEMENT
%union {
	int numval;
	char *strval;
}
%locations
%pure_parser

%type <strval> IDENTIFIER
%type <strval> CONSTANT
%type <strval> CODEBLOCK
%type <strval> END_OF_STATEMENT
%type <strval> member
%type <strval> name
%type <strval> translation_unit
%type <strval> statement
%type <strval> declaration
%type <strval> expression
%type <strval> argument_list
%type <strval> argument



%start translation_unit
%%

translation_unit
: statement 
| translation_unit statement 
;
statement
: declaration END_OF_STATEMENT 
{ 
	fprintf(stderr, "%s\n", $1);
}
| expression END_OF_STATEMENT
{ 
	fprintf(stderr, "%s\n", $1);
}
| END_OF_STATEMENT
;
declaration
: name ':' name  
{
	Sociaty_AddPCRelation($3,$1);
	sprintf($$, "%s:%s",$1,$3);
}
;

name 
: IDENTIFIER 
| member 
;
expression
: name 					             
{
	Sociaty_AddSSRelation("eve", $1); 
	Role_ParseCode(Sociaty_SearchRole($1));
	sprintf($$, "%s()",$1);
}		
| name '(' ')'               
{
	Sociaty_AddSSRelation("eve", $1);
	Role_ParseCode(Sociaty_SearchRole($1));
	sprintf($$, "%s.%s()",$1);
}
| name argument_list         
{
	Sociaty_AddSSRelation("eve", $1);
	sprintf($$, "%s(%s)",$1,$2);
}
| name '(' argument_list ')' 
{
	Sociaty_AddSSRelation("eve", $1);
	sprintf($$, "%s(%s)",$1,$3);
}
| name '=' CONSTANT
{
	Sociaty_AddSSRelation("eve", $1);
  Role_SetCode(Sociaty_SearchRole($1), $3);
  sprintf($$, "%s = %s",$1,$3);
}
| name '=' member

{
  Sociaty_AddSSRelation("eve", $1);
  Role_SetCode(Sociaty_SearchRole($1), $3);
  sprintf($$, "%s = %s",$1,$3);
}
| name '=' CODEBLOCK
{
	Sociaty_AddSSRelation("eve", $1);
	Role_SetCode(Sociaty_SearchRole($1), $3);
	sprintf($$, "%s = %s",$1,$3);
}
| name '=' '(' argument_list ')' CODEBLOCK
{
	Sociaty_AddSSRelation("eve", $1);
	sprintf($$, "%s = (%s)%s",$4,$6);
}
;
member
: IDENTIFIER '.' IDENTIFIER 
{
	Sociaty_AddSSRelation($1,$3);
	sprintf($$, "%s.%s",$1,$3);
}
| member '.' IDENTIFIER
{
	Sociaty_AddSSRelation($1,$3);
	sprintf($$, "%s.%s",$1,$3);
}
;
argument_list
  : argument 
  | argument_list ',' argument {sprintf($$, "%s.%s",$1,$3);}
	;
argument
	: member
	| CONSTANT
	| CODEBLOCK
	;
%%

void yyerror(char *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

int main(void) {
	yyscan_t scanner;
	yylex_init(&scanner);
	Sociaty_Create();
	printf("#include <stdio.h>\nmain(){\n");
  yyparse(scanner);
	yylex_destroy(scanner);
	printf("}\n");
//	Sociaty_Write();
//	write_symtable();
  return 0;
}
