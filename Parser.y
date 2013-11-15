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
	extern void p(int);
	extern FILE *out;
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
void ParseExpressionFromFile(char *fpath);
void ParseExpressionFromFile(char *str);
void ParseExpressionFromString(char *str);

 }
 
%output  "Parser.c"
%defines "Parser.h"
 
%define api.pure
%lex-param   { yyscan_t scanner }
%parse-param { yyscan_t scanner }
 
%union {
	int numval;

//	IntTuple2 num2val;
	char *strval;
}
  

%token <strval> IDENTIFIER 
%token <strval> CONSTANT 
%token USE SETFLAG SETOUT
%token <charval> TOKEN_PRINT
%token END_OF_STATEMENT END_OF_FILE
%token NULL_TOKEN


%type <numval> eval
%type <numval> role
%type <numval> member

%start translation_unit

%%
translation_unit
: statement
| translation_unit statement
| translation_unit END_OF_FILE
| END_OF_FILE
;
statement
: expression END_OF_STATEMENT  {p(101);}
| expression END_OF_FILE
| END_OF_STATEMENT
| NULL_TOKEN
;

expression
: SETFLAG role role
{
  p(201);
	Sociaty_GetRole($2)->_Flag = Sociaty_GetRole($3)->_Flag;
}
| SETFLAG role CONSTANT
{
  p(202);
	Sociaty_GetRole($2)->_Flag = GetFlag($3);
}
| SETOUT role 
{
  p(203);
	Sociaty_SetOut(Sociaty_GetRole($2)->_Value);
}
| SETOUT CONSTANT
{
  p(204);
	Sociaty_SetOut($2);
}
| USE role
{
  p(205);
	char *fpath = estrdup(GetPath(Sociaty_GetRole($2)->_Value));
	ParseExpressionFromFile(fpath);
}
| USE CONSTANT
{
  p(206);
	char *fpath = estrdup(GetPath($2));
	ParseExpressionFromFile(fpath);
}
| role '=' CONSTANT 
{ 
  p(207);
	Sociaty_GetRole($1)->_Value = strdup($3);
}
| role '=' role
{
  p(208);
  Sociaty_GetRole($1)->_Value =
    estrdup(Sociaty_GetRole($3)->_Value);
}
| role ':' role
{
  p(209);
  if(Sociaty_SearchPCRelation($1, $3) != 0){
    eerror("cannot inherent");
    exit(1);
  }
  Sociaty_AddPCRelation($3, $1);
}
| eval
{
  p(210);
	char *rtn;
	rtn = Eval($1);
#ifdef EDEBUG
	printf("%s\n", rtn);
#endif
	ParseExpressionFromString(rtn);
//	Eval(Sociaty_GetValue());
//	$$ = Expression_Create($1, NULL, Eval); 
}
;

eval
: role         {   p(301);$$ = $1; }
| role '(' ')' {  p(302); $$ = $1; }
| role argument_list
| role '(' argument_list ')'
;

role
: member
{
  p(401);
  $$ = $1;
}
| IDENTIFIER
{
  p(402);
	$$ = Sociaty_AddNewRole($1);	
}

;

member
: IDENTIFIER '.' IDENTIFIER
{
  p(501);
	int pi, ci;
	char *m;
  pi = Sociaty_AddNewRole($1);
	m = (char *)malloc(strlen($1) + strlen($3) + 3);
	sprintf(m, "%s.%s", $1, $3);
	ci = Sociaty_AddNewRole(m);
	Sociaty_AddSSRelation(pi, ci);
	$$ = ci;
}
| member '.' IDENTIFIER 
{
  p(502);
	int pi, ci;
	char *m;
	char *n;
	n = Sociaty_GetRole($1)->_Name;
	m = (char *)malloc(strlen(n) + strlen($3) + 3);
	sprintf(m, "%s.%s", n, $3);
	ci = Sociaty_AddNewRole(m);
	Sociaty_AddSSRelation($1, ci);
	$$ = ci;
}
| member '[' argument ']'
{
}
;
argument
: role
| CONSTANT
;
argument_list
: argument
| argument_list ',' argument
;

%%

	//void ParseExpressionFromString(Expression *expr, char *str){
void ParseExpressionFromFile(char *fpath){
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
