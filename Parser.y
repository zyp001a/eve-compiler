%{
 
/*
 * Parser.y file
 * To generate the parser run: "bison Parser.y"
 */

#include "Common.h" 
#include "Expression.h"
#include "Parser.h"
#include "Lexer.h"

/*
int yyparse(Expression **expression, yyscan_t scanner);
int yyerror(Expression **expression, yyscan_t scanner, const char *msg) {
	// Add error handling routine as needed
}
*/
	int yyparse(yyscan_t scanner);
	int yyerror(yyscan_t scanner, const char *msg){}



 
%}
 
%code requires {
 
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
	typedef void* yyscan_t;
#endif

void ParseExpressionFromString(char *str);
 }
 
%output  "Parser.c"
%defines "Parser.h"
 
%define api.pure
%lex-param   { yyscan_t scanner }
%parse-param { yyscan_t scanner }
 
%union {
	char *strval;
	Expression *expression;
}
 
 

%token <strval> IDENTIFIER CONSTANT BLOCK 
%token END_OF_STATEMENT

%type <expression> expr
%type <strval> name
%type <strval> role
%type <strval> member

%start translation_unit

%%
translation_unit
: statement
| translation_unit END_OF_STATEMENT statement
| translation_unit END_OF_STATEMENT 
;

statement
: expr { /**expression = $1;*/ }
;

expr
: name ':' name { printf("p--%s:%s\n",$1,$3); Expression_CreateGen($$, $1, $3); }
| name          { Expression_CreateEval($$, $1); }
| name '(' ')'  { Expression_CreateEval($$, $1); }
| name '=' name { Expression_CreateSet($$, $1, $3); }

;

name
: role 
;

role
: IDENTIFIER { strcpy($$, $1); printf("pi-%s\n",$1);}
| member { strcpy($$, $1); printf("pm-%s\n",$1);}
| CONSTANT { strcpy($$, $1); printf("pc-%s\n",$1);}
| BLOCK { strcpy($$, $1); printf("pb-%s\n",$1);}
;

member
: IDENTIFIER '.' IDENTIFIER {printf("p-m-%s.%s\n", $1, $3); sprintf($$, "%s.%s", $1, $3);}
| member '.' IDENTIFIER {printf("p-m-%s.%s\n", $1, $3); sprintf($$, "%s.%s", $1, $3);}
;
%%

	//void ParseExpressionFromString(Expression *expr, char *str){
void ParseExpressionFromString(char *str){
  yyscan_t scanner;
  YY_BUFFER_STATE state;
	if (yylex_init(&scanner)) {
    // couldn't initialize
		eerror("yylex_init failed");
    return;
  }
	state = yy_scan_string(str, scanner);
//	if (yyparse(&expr, scanner)) {
	if (yyparse(scanner)){
    // error parsing
		eerror("yyparse failed");
    exit(1);
  }
	yy_delete_buffer(state, scanner);
	yylex_destroy(scanner);

}
