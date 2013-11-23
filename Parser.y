%{
 
/*
 * Parser.y file
 * To generate the parser run: "bison Parser.y"
 */


#include "Sociaty.h"
#include "Role.h"
#include "Eval.h"
#include "Parser.h"
#include "Lexer.h"

int yyparse(yyscan_t scanner);
int yyerror(yyscan_t scanner, const char *msg){
		printf("yyerror, %s\n",msg);
	}

#define YACCDEBUG
#ifdef YACCDEBUG
#define yd_print(s) \
  {\
    fprintf(stderr, "--->Match %s\n", s);\
  }
#else
#define yd_print(s) 
#endif

 
%}
 
%code requires {
#include "Common.h"  
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
	typedef void* yyscan_t;
#endif
void ParseExpressionFromFile(char *fpath);
void ParseExpressionFromFp(FILE *fp);
void ParseExpressionFromString(char *str);
yyscan_t current_scanner;
}
 
%output  "Parser.c"
%defines "Parser.h"
 
%define api.pure
%lex-param   { yyscan_t scanner }
%parse-param { yyscan_t scanner }
 
%union {
	int numval;
	IndexArray iaval;
	char *strval;
}
  

%token <strval> IDENTIFIER 
%token <strval> CONSTANT 
%token <strval> BLOCK
%token FOR WHILE IF IFELSE NOT ADD INVOKE PRINT
%token END_OF_STATEMENT 
%token SETFLAG SETARGS

%type <strval> role_as_const
%type <numval> const_as_role
%type <numval> eval_expression
%type <numval> role
%type <numval> member
%type <numval> argument
%type <iaval> argument_list


%start translation_unit

%%
translation_unit
: statement { 
  yd_print("statement");
}
| translation_unit statement { 
	yd_print("translation_unit statement");
}
;
statement
: END_OF_STATEMENT 
| expression END_OF_STATEMENT
;
expression
: control_expression
| internal_function
| assignment_expression
| inherent_expression
| eval_expression
{
	char *rtn;
	rtn = Eval($1);
	yd_print(rtn);
	ParseExpressionFromString(rtn);
}
;
control_expression
: FOR role role BLOCK
{
	yd_print("FOR");
	int i;
	for(i=0; i< Sociaty_GetRole($3)->Elements.Length; i++){
		Sociaty_GetRole($2)->_Value = 
			Sociaty_GetRole(Sociaty_GetRole($3)->Elements.Values[i])->_Value;
		estraddeol(&$4);
		ParseExpressionFromString($4);
	}
}
| WHILE role BLOCK
{
	yd_print("WHILE");
  while(!estrisnull(Sociaty_GetRole($2)->_Value)){
		estraddeol(&$3);
    ParseExpressionFromString($3);
  }
}
| WHILE NOT role BLOCK
{
	yd_print("WHILE NOT");
	while(estrisnull(Sociaty_GetRole($3)->_Value)){
    estraddeol(&$4);
    ParseExpressionFromString($4);
  }

}
| IF role BLOCK
{
	yd_print("IF");
	if(!estrisnull(Sociaty_GetRole($2)->_Value)){
		estraddeol(&$3);
		ParseExpressionFromString($3);
	}
}
| IF NOT role BLOCK
{
	yd_print("IF NOT");
	if(estrisnull(Sociaty_GetRole($3)->_Value)){
    estraddeol(&$4);
    ParseExpressionFromString($4);
  }
}
| IFELSE role BLOCK BLOCK
{
	yd_print("IF ELSE");
  if(!estrisnull(Sociaty_GetRole($2)->_Value)){
		estraddeol(&$3);
    ParseExpressionFromString($3);
  }
	else{
		estraddeol(&$4);
		ParseExpressionFromString($4);
	}
}
;
internal_function
: PRINT argument_list 
{
	yd_print("PRINT");
	int i;
	for(i=0; i<$2.Length; i++){
		Sociaty_PutString(Sociaty_GetRole($2.Values[i])->_Value);
	}
	IndexArray_DisposeSub(&$2);
}
| ADD role const_as_role
{
	yd_print("ADD");
	IndexArray_Add(&Sociaty_GetRole($2)->Elements,
								 $3);
}
| INVOKE role role_as_const
{
  yd_print("INVOKE");
	char *rtn;
	rtn = EvalString($2, $3);
  yd_print(rtn);
	ParseExpressionFromString(rtn);
}
| SETFLAG role role
{
	//TODO Argument Parsing
  yd_print("SETFLAG");
	Sociaty_GetRole($2)->_Flag = Sociaty_GetRole($3)->_Flag;
}
| SETFLAG role CONSTANT
{
	//TODO Argument Parsing
  yd_print("SETFLAG");
	Sociaty_GetRole($2)->_Flag = GetFlag($3);
}
| SETARGS role argument_list
{
	//TODO Argument Parsing
} 
;
assignment_expression
: role '=' '[' argument_list ']'
{
	yd_print("ASSIGN ARRAY");
	IndexArray_PassByValue(&Sociaty_GetRole($1)->Elements, &$4);
	IndexArray_DisposeSub(&$4);
}
| role '=' role_as_const
{ 
	yd_print("ASSIGN VALUE");
	if(Sociaty_GetRole($1)->_Value != NULL) free(Sociaty_GetRole($1)->_Value);
	Sociaty_GetRole($1)->_Value = estrdup($3);
}
| role '+' '=' role_as_const
{
	yd_print("CONCAT VALUE");
  estradd(&Sociaty_GetRole($1)->_Value, $4);
}
| role '=' '&' role
{
	yd_print("ASSIGN REF");
	if(Sociaty_GetRole($1)->_Value != NULL) free(Sociaty_GetRole($1)->_Value);
	Sociaty_GetRole($1)->_Value =
		Sociaty_GetRole($4)->_Value;
}
;
inherent_expression
: role ':' role
{
	yd_print("INHERENT");
  if(Sociaty_SearchPCRelation($1, $3) != 0){
    eerror("cannot inherent");
    exit(1);
  }
  Sociaty_AddPCRelation($3, $1);
}
;
eval_expression
: role {
	yd_print("EVAL");
	$$ = $1; 
}
| role '(' ')' {  
	yd_print("EVAL");
	$$ = $1; 
}
| role argument_list
{
	IndexArray_PassBySymbol(&Sociaty_GetRole($1)->Args, &$2);
	$$ = $1;
}
| role '(' argument_list ')'
{
  IndexArray_PassBySymbol(&Sociaty_GetRole($1)->Args, &$3);
	$$ = $1;
}
;
role_as_const
: role {
	$$ = Sociaty_GetRole($1)->_Value;
}
| CONSTANT {
	$$ = $1;
}
;
const_as_role
: role {
	$$ = $1;
}
| CONSTANT {
	$$ = Sociaty_AddConstRole($1);
}
;
role
: member
{
  $$ = $1;
}
| IDENTIFIER
{
	$$ = Sociaty_AddNewRole($1);	
}
/*
| role '[' CONSTANT ']'
{
	$$ = Sociaty_GetRole($1)->Elements.Values[atoi($3)];	
}
*/
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
	$$ = ci;
}
| member '.' IDENTIFIER
{
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
;

argument
: const_as_role {	$$ = $1; }
;
argument_list
: argument 
{ 
	IndexArray_Create(&$$); 
	IndexArray_Add(&$$, $1); 
}
| argument_list ',' argument { 
	$$ = $1; 
	IndexArray_Add(&$$, $3); 
}
;

%%

	//void ParseExpressionFromString(Expression *expr, char *str){
void ParseExpressionFromFp(FILE *fp){
	char *content;
	content = ereadfile(fp);
	estraddeol(&content);
	ParseExpressionFromString(content);
//	free(fpath);
}
void ParseExpressionFromFile(char *fpath){
  char *content;
  FILE *ifp;
  if(fpath[0]){
    if((ifp=fopen(fpath,"r")) != NULL){
			ParseExpressionFromFp(ifp);
		}
		else{
			eerror("file not exist");
			exit(1);
		}
  }
  else{
    eerror("file not exist");
    exit(1);
  }
	fclose(ifp);
//  free(fpath);
}

void ParseExpressionFromString(char *str){
//	printf("\nParseExpressionFromString\n=====\n%s\n=====\n\n", str);
  yyscan_t scanner;
	current_scanner = scanner;
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
//	free(str);

}
