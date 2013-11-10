%{
 
/*
 * Parser.y file
 * To generate the parser run: "bison Parser.y"
 */

#include "Common.h" 
#include "Expression.h"
#include "Parser.h"
#include "Lexer.h"
 
int yyerror(Expression **expression, yyscan_t scanner, const char *msg) {
	// Add error handling routine as needed
}
 
%}
 
%code requires {
 
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
	typedef void* yyscan_t;
#endif
 
 }
 
%output  "Parser.c"
%defines "Parser.h"
 
%define api.pure
%lex-param   { yyscan_t scanner }
%parse-param { Expression **expression }
%parse-param { yyscan_t scanner }
 
%union {
	char *strval;
	Expression *expression;
}
 
%left ':'
%left '.'
 
%token CONSTANT IDENTIFIER 
%token END_OF_STATEMENT
%type <strval> CONSTANT
%type <strval> IDENTIFIER
%type <expression> expr
%type <strval> name
%type <strval> member

%start translation_unit

%%
translation_unit
: statement
| translation_unit statement
;

statement
: expr END_OF_STATEMENT { *expression = $1; }
| END_OF_STATEMENT
;

expr
: name ':' name { Expression_CreateGen($$, $1, $3); }
| name          { Expression_CreateEval($$, $1); }
| name '(' ')'  { Expression_CreateEval($$, $1); }
| name '=' name { Expression_CreateSet($$, $1, $3); }
;

name
: IDENTIFIER
| member
| CONSTANT
;
member
: IDENTIFIER '.' IDENTIFIER
| member '.' IDENTIFIER
;
%%
