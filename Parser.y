%{
 
/*
 * Parser.y file
 * To generate the parser run: "bison Parser.y"
 */


//#include "Expression.h"
#include "Sociaty.h"
#include "Role.h"
#include "Eval.h"
#include "Parser.h"
#include "Lexer.h"

/*
int yyparse(Expression **expression, yyscan_t scanner);
int yyerror(Expression **expression, yyscan_t scanner, const char *msg) {
	// Add error handling routine as needed
}
*/
	int yyparse(yyscan_t scanner);
	int yyerror(yyscan_t scanner, const char *msg){
//		printf("yyerror, %s: '%s' in line %d\n", msg, yytext, yylineno);
		printf("yyerror, %s\n",msg);
	}




 
%}
 
%code requires {
#include "Common.h"  
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
	int numval;
	IntTuple2 num2val;
	char *strval;
}
 
 

%token <strval> IDENTIFIER 
%token <strval> CONSTANT 
%token USE
%token END_OF_STATEMENT END_OF_FILE


%type <num2val> eval
%type <num2val> role
%type <num2val> member

%start translation_unit

%%
translation_unit
: expr END_OF_STATEMENT
| translation_unit expr END_OF_STATEMENT
| END_OF_FILE
| translation_unit expr END_OF_FILE
| translation_unit END_OF_FILE
;
expr
: USE CONSTANT
{
	char *fpath = estrdup(GetPath($2));
	char *content;
	FILE *ifp;
	if(fpath[0]){
		ifp=fopen(fpath,"r");
		content = ereadfile(ifp);
		ParseExpressionFromString(content);
	}
	else{
		eerror("file not exist");
		exit(1);
	}
}
| role '=' CONSTANT 
{ 
	Sociaty_GetRole($1.Int1)->_Value = strdup($3);
}
| role '=' role
{
  Sociaty_GetRole($1.Int1)->_Value =
    estrdup(Sociaty_GetRole($3.Int1)->_Value);
}
| role ':' role
{
  if(Sociaty_SearchPCRelation($1.Int1, $3.Int1) != 0){
    eerror("cannot inherent");
    exit(1);
  }
  Sociaty_AddPCRelation($1.Int1, $3.Int1);
}
| eval
{
	Eval($1.Int1, $1.Int2);
//	Eval(Sociaty_GetValue());
//	$$ = Expression_Create($1, NULL, Eval); 
}
;

eval
: role         { $$ = $1; }
| role '(' ')' { $$ = $1; }
;

role
/*
: CONSTANT
{
#ifdef EDEBUG
	printf("get const: %s\n", $1);
#endif
  $$.Int1 = Sociaty_AddConstRole($1);
}
*/
: member
{
#ifdef EDEBUG
  printf("get member: %s\n", Sociaty_GetRole($1.Int1)->_Name);
#endif
  $$ = $1;
}
| IDENTIFIER
{
#ifdef EDEBUG
	printf("get id:    %s\n", $1);
#endif
	$$.Int1 = Sociaty_AddNewRole($1);	
}

;


member
: IDENTIFIER '.' IDENTIFIER
{
	int pi, ci;
	char *m;
  pi = Sociaty_AddNewRole($1);
	m = (char *)malloc(strlen($1) + strlen($3) + 3);
	sprintf(m, "%s.%s", $1, $3);
	ci = Sociaty_AddNewRole(m);
	Sociaty_AddSSRelation(pi, ci);
	$$.Int1 = ci;
	$$.Int2 = pi;
}
| member '.' IDENTIFIER 
{
	int pi, ci;
	char *m;
	char *n;
	n = Sociaty_GetRole($1.Int1)->_Name;
	m = (char *)malloc(strlen(n) + strlen($3) + 3);
	sprintf(m, "%s.%s", n, $3);
	ci = Sociaty_AddNewRole(m);
	Sociaty_AddSSRelation($1.Int1, ci);
	$$.Int1 = ci;
	$$.Int2 = pi;
}
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
