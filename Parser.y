%{
 
/*
 * Parser.y file
 * To generate the parser run: "bison Parser.y"
 */


#include "Sociaty.h"
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
    fprintf(ns.Err, "--->Match %s\n", s);\
  }
#else
#define yd_print(s) 
#endif
extern Sociaty ns;
 
%}
 
%code requires {
#include "Common.h"  
#include "Role.h"
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
	Role* roleval;
	int numval;
	RoleArray* rolearr;
	StringInt strint;
	char* strval;
}
  

%token <strval> IDENTIFIER 
%token <strval> CONSTANT 
%token <strval> INTEGER
%token <strval> BLOCK
%token <strval> ADDRESS
%token FOR WHILE IF ELSIF ELSE 
%token USE LOAD ADD INVOKE PRINT 
%token <strval> PUTSTR
%token VALUE READFILE
%token NOT ISFILE ISDIR

%token END_OF_STATEMENT 
%token SETFLAG SETARGS

%type <strval> role_as_const
%type <strval> const_or_int
 //%type <roleval> const_as_role
%type <roleval> eval_expression
%type <roleval> role
%type <roleval> member
%type <roleval> argument
%type <numval> boolean_expression
%type <strval> else_expression
%type <rolearr> argument_list


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
| expression PUTSTR
{
	Sociaty_PutString($2);
}
| PUTSTR 
{
	Sociaty_PutString($1);
}
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
	if(rtn != NULL){
		yd_print(rtn);
		ParseExpressionFromString(rtn);
	}
//	Sociaty_WriteMembers();
//	printf("clearargs%d\n", $1);
//	Sociaty_ClearArgs($1);
}
;
control_expression
: FOR role BLOCK
{
	yd_print("FOR");
	int i;
	Role *ri, *rt;
	char str[8];
	char *rtn;
	rt = Sociaty_RoleEmploy($2, "_Iterator");
	ri = Sociaty_RoleEmploy($2, "_Index");
	for(i=0; i< $2->_Elements->Length; i++){
    Role_SetTarget(rt, $2->_Elements->Values[i]);
		sprintf(str, "%d", i);
		Role_SetValue(ri, estrdup(str));
////////////////
		rtn = EvalString($2, $3, 1);
    ParseExpressionFromString(rtn);
///////////////
  }
}
| IF boolean_expression BLOCK
{
	yd_print("IF");
	if($2){
		estraddeol(&$3);
		ParseExpressionFromString($3);
	}
}
| IF boolean_expression BLOCK ELSE else_expression
{
	yd_print("IF ELSE");
  if($2){
		estraddeol(&$3);
    ParseExpressionFromString($3);
  }
	else{
		estraddeol(&$5);
		ParseExpressionFromString($5);
	}
}
;
else_expression
: BLOCK
{
	$$ = $1;
}
| IF boolean_expression BLOCK
{
	if($2) $$ = $3;
	else $$ = estrdup("");
}
| IF boolean_expression BLOCK ELSE else_expression
{
	if($2) $$ = $3;
  else $$ = $5;
}
;
boolean_expression
: role_as_const 
{
	if(!estrisnull($1) && strcmp($1, "0"))
		$$ = 1;
	else
		$$ = 0;
}
| role_as_const '=' '=' role_as_const
{
	if(!strcmp($1, $4)) $$ = 1;
	else $$ = 0;
}
| role_as_const NOT '=' role_as_const
{
	if(strcmp($1, $4)) $$ = 1;
	else $$ = 0;
}
| role_as_const '<' role_as_const
{
	$$ = (atoi($1) < atoi($3));
}
| role_as_const '>' role_as_const
{
	$$ = (atoi($1) >= atoi($3));
}
| role_as_const '<' '=' role_as_const
{
  $$ = (atoi($1) <= atoi($4));
}
| role_as_const '>' '=' role_as_const
{
  $$ = (atoi($1) >= atoi($4));
}
| NOT boolean_expression
{
//	printf("NOT %d", $2);
	$$ = !$2;
}
| ISFILE role_as_const
{
	$$ = eisfile($2);
}
| ISDIR role_as_const
{
  $$ = eisdir($2);
}
| '(' boolean_expression ')'
{
	$$ = $2;
}
| '(' boolean_expression '&' '&' boolean_expression ')'
{
	$$ = $2 && $5;
}
| '(' boolean_expression '|' '|' boolean_expression ')'
{
  $$ = $2 || $5;
}
;
internal_function
: USE role_as_const
{
	char *fpath;
  fpath = UseFile($2);
		if(fpath != NULL)
			ParseExpressionFromFile(fpath);
}
| LOAD role_as_const
{
	ParseExpressionFromFile($2);
}
/*
| PRINT argument_list 
{
	yd_print("PRINT");
	int i;
	for(i=0; i<$2.Length; i++){
		Sociaty_PutString($2.StrValues[i]);
	}
}
| ADD role const_as_role
{
	yd_print("ADD");
	IndexArray_Add(&Sociaty_GetRole($2)->Elements,
								 $3);
}
*/

| INVOKE role role_as_const
{
  yd_print("INVOKE");
	char *rtn;
	rtn = EvalString($2, $3, 1);
//  yd_print(rtn);
	ParseExpressionFromString(rtn);
}

/*
| SETFLAG role role
{
	//TODO 
  yd_print("SETFLAG");
	Sociaty_GetRole($2)->_Flag = Sociaty_GetRole($3)->_Flag;
}
| SETFLAG role const_or_int
{
	//TODO 
  yd_print("SETFLAG");
	Sociaty_GetRole($2)->_Flag = GetFlag($3);
}
| SETARGS role argument_list
{
	//TODO 
} 
*/
;
assignment_expression
: role '=' '[' argument_list ']'
{
	yd_print("ASSIGN ARRAY");
	Sociaty_RoleSetElements($1, $4);
}
| role '=' role_as_const
{ 
	yd_print("ASSIGN VALUE");
	$1->_Value = $3;
}
| role '+' '=' role_as_const
{
	yd_print("CONCAT VALUE");
  estrcat(&$1->_Value, $4);
}
| role '=' '&' role
{
	yd_print("ASSIGN REF");
	Role_SetTarget($1, $4);
}
;
inherent_expression
: role ':' role
{
	yd_print("INHERENT");
	Role_AddPrt($1, $3);
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

	yd_print("EVAL ARGS");
	Role *t = Sociaty_RoleEmploy($1, "_Args");
	Sociaty_RoleSetElements(t, $2);
	$$ = $1;
}
| role '(' argument_list ')'
{
	yd_print("EVAL ARGS");
  Role *t = Sociaty_RoleEmploy($1, "_Args");
	Sociaty_RoleSetElements(t, $3);
	$$ = $1;
}
;
role_as_const
: role {
//////////////////////////////////////////////////////
//  $$ = EvalString($1, GetDymValue(r), 0);
	$$ = Role_GetFinalValue($1);
////////////////
}
| const_or_int {
	$$ = $1;
}
/*
| VALUE role_as_const
{
	8yd_print("VALUE");
  char pi;
	pi = Sociaty_SearchRole($2);
//  yd_print(rtn);
  $$ = Sociaty_GetRole(pi)->_Value;
}
*/
| READFILE role_as_const
{
	char* fpath;
  FILE *fp;
  fpath=GetPath($2);
  if(fpath == NULL){
		$$ = "";
  }

  fp = fopen(fpath, "r");
  $$ = ereadfile(fp);
}
;
/*
const_as_role
: role {
	$$ = $1;
}
| const_or_int {
	$$ = Sociaty_AddConstRole($1);
}
;
*/
const_or_int
: CONSTANT { $$ = $1; }
| INTEGER {$$ = $1; }
;
role
: member
{
  $$ = $1;
}
| IDENTIFIER
{
	$$ = Sociaty_RoleEmploy(ns.Curr, $1);
}
| ADDRESS
{
	$$ = (Role*)atol($1);
}
;

member
: IDENTIFIER '.' IDENTIFIER
{
	Role *r;
	r = Sociaty_RoleEmploy(ns.Curr, $1);
	$$ = Sociaty_RoleEmploy(r, $3);
}
| IDENTIFIER '[' INTEGER ']'
{
	Role *r;
  r = Sociaty_RoleEmploy(ns.Curr, $1);
	$$ = Sociaty_RoleExpend(r, atoi($3));
}
| member '.' IDENTIFIER
{
	$$ = Sociaty_RoleEmploy($1, $3);
}
| member '[' INTEGER ']'
{
	$$ = Sociaty_RoleExpend($1, atoi($3));
}
;

argument
: const_or_int 
{	
	$$ = Role_New();
	$$->_Value = $1;
}
| role 
{
	$$ = $1;
}
;
argument_list
: argument 
{ 
	RoleArray_Init(&$$); 
	RoleArray_Add($$, $1);
}
| argument_list ',' argument { 
	RoleArray_Add($1, $3);
	$$ = $1;
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
