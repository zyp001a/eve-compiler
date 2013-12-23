%{
 
/*
 * Parser.y file
 * To generate the parser run: "bison Parser.y"
 */


#include "Sociaty.h"
#include "Eval.h"
#include "Parser.h"
#include "Lexer.h"
#include "Reader.h"
int yyparse(yyscan_t scanner);

int yyerror(yyscan_t scanner, const char *msg){
//		printf("yyerror, %s\n",msg);
}


//#define YACCDEBUG
#ifdef YACCDEBUG
#define yd_print(s) \
  {\
    fprintf(ns.Err, "--->Match %s\n", s);\
  }
#else
#define yd_print(s) 
#endif
extern Sociaty ns;
extern char *evalstr;
extern char *evalargsstr; 
extern int *eval_time;
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
char ParseExpressionFromString(char *str, char istry);
void ParseExpressionFromStdin(char* starter);
void EvalRole(Role* r);
void SetRole(Role* r, RoleArray* ra);
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
%token USE LOAD ADD INVOKE PRINT PARSEFILE STOREFILE EXIT
%token <strval> PUTSTR
%token VALUE READFILE TARGET NULL_TOKEN
%token NOT ISFILE ISDIR

%token END_OF_STATEMENT 
%token SETFLAG 

%type <strval> role_as_const
%type <strval> const_or_int
 //%type <roleval> const_as_role
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
| EXIT END_OF_STATEMENT 
{
	YYABORT; //not used currently
}
| expression END_OF_STATEMENT
| expression PUTSTR
{
	Sociaty_PutString($2);
	free($2);
}
| PUTSTR 
{
	Sociaty_PutString($1);
	free($1);
}
;
expression
: control_expression
| internal_function
| assignment_expression
| inherent_expression
| eval_expression
;
control_expression
: FOR role BLOCK
{
	int i;
	Role *ri, *rt;
	char str[20];
	char *rtn;
	

	rtn = EvalString($2, $3, 1);
	free($3);		
	if(rtn != NULL){
		
		yd_print("FOR");
		rt = Sociaty_RoleEmploy($2, "_Iterator");
		ri = Sociaty_RoleEmploy($2, "_Index");
		for(i=0; i< $2->_Elements->Length; i++){
			Role_SetTarget(rt, $2->_Elements->Values[i]);
			sprintf(str, "%d", i);
			Role_SetValue(ri, estrdup(str));
////////////////
			ParseExpressionFromString(rtn,0);
		}
	}
///////////////
	free(rtn);

}
| IF boolean_expression BLOCK
{
	yd_print("IF");
	if($2){
		estraddeol(&$3);
		ParseExpressionFromString($3,0);
	}
	free($3);
}
| IF boolean_expression BLOCK ELSE else_expression
{
	yd_print("IF ELSE");
  if($2){
		estraddeol(&$3);
    ParseExpressionFromString($3,0);
  }
	else{
		estraddeol(&$5);
		ParseExpressionFromString($5,0);
	}
	free($3);
	free($5);
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
	else{
		$$ = estrdup("");
		free($3);
	}
}
| IF boolean_expression BLOCK ELSE else_expression
{
	if($2){
		$$ = $3;
		free($5);
	}
  else{
		$$ = $5;
		free($3);
	}
}
;
boolean_expression
: role_as_const 
{
	if(!estrisnull($1) && strcmp($1, "0"))
		$$ = 1;
	else
		$$ = 0;
	free($1);
}
| role_as_const '=' '=' role_as_const
{
	char b1,b2;
	b1 = estrisnull($1);
	b2 = estrisnull($4);
	if(b1 && b2) $$ = 1;
	else if(b1 || b2) $$ = 0;
	else if(!strcmp($1, $4)) $$ = 1;
	else $$ = 0;
	free($1);
	free($4);
}
| role_as_const NOT '=' role_as_const
{
	char b1,b2;
  b1 = estrisnull($1);
  b2 = estrisnull($4);
  if(b1 && b2) $$ = 0;
  else if(b1 || b2) $$ = 1;
  else if(!strcmp($1, $4)) $$ = 0;
  else $$ = 1;
  free($1);
  free($4);
}
| role_as_const '<' role_as_const
{
	$$ = (atoi($1) < atoi($3));
	free($1);
	free($3);
}
| role_as_const '>' role_as_const
{
	$$ = (atoi($1) >= atoi($3));
	free($1);
	free($3);

}
| role_as_const '<' '=' role_as_const
{
  $$ = (atoi($1) <= atoi($4));
	free($1);
	free($4);
}
| role_as_const '>' '=' role_as_const
{
  $$ = (atoi($1) >= atoi($4));
	free($1);
	free($4);

}
| NOT boolean_expression
{
	$$ = !$2;
}
| ISFILE role_as_const
{
	char *a = GetPath($2);
	$$ = eisfile(a);
	free($2);
	free(a);
}
| ISDIR role_as_const
{
	char *a = GetPath($2);
  $$ = eisdir(a);
	free(a);
	free($2);
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
  UseFile($2);
	free($2);
}
| LOAD role_as_const
{
	ParseExpressionFromFile($2);
	free($2);
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
	ParseExpressionFromString(rtn,0);
	free(rtn);
	free($3);
}
| PARSEFILE role
{
	yd_print("PARSEFILE");
	ParseFileAndSendToDatabase($2);
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
	Role_SetValue($1, $3);
	//not free, directly passed to value
}
| role '+' '=' role_as_const
{
	yd_print("CONCAT VALUE");
  estrcat(&$1->_Value, $4);
	free($4);
}
| role '+' '+'
{
	yd_print("INCR VALUE");
	int i = atoi($1->_Value) + 1;
	char a[8];
	sprintf(a, "%d", i);
	Role_SetValue($1, estrdup(a));
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

| role ':' role '(' argument_list ')'
{
	yd_print("INHERENT");
  Role_AddPrt($1, $3);
	SetRole($1, $5);
}

;
eval_expression
: role {
	yd_print("EVAL");
	EvalRole($1);
}
| role '(' ')' {  
	yd_print("EVAL");
	EvalRole($1);
}
| role argument_list
{
	yd_print("EVAL ARGS");
	SetRole($1,$2);
	EvalRole($1);
}
| role '(' argument_list ')'
{
	yd_print("EVAL ARGS");
	SetRole($1, $3);
	EvalRole($1);
}
;
role_as_const
: role {
//////////////////////////////////////////////////////
	char *v = GetDymValue($1);
	if(v == NULL) $$ = NULL;
	else $$ = EvalString($1, v, 0);
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
	yd_print("READFILE");
	char* fpath;
  FILE *fp;
	fpath=GetPath($2);
	free($2);
	if(fpath == NULL){
		$$ = NULL;
	}
	else{
		yd_print(fpath);
		fp = fopen(fpath, "r");
		$$ = ereadfile(fp);
		free(fpath);
	}
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
	free($1);
}
| ADDRESS
{
	$$ = (Role*)atol($1);
	free($1);
}

| TARGET role
{
	$$ = $2->_Target;
}

;

member
: IDENTIFIER '.' IDENTIFIER
{
	Role *r;
	r = Sociaty_RoleEmploy(ns.Curr, $1);
	$$ = Sociaty_RoleEmploy(r, $3);
	free($1);
	free($3);
}
| IDENTIFIER '[' INTEGER ']'
{
	Role *r;
  r = Sociaty_RoleEmploy(ns.Curr, $1);
	$$ = Sociaty_RoleExpend(r, atoi($3));
	free($1);
	free($3);
}
| member '.' IDENTIFIER
{
	$$ = Sociaty_RoleEmploy($1, $3);
	free($3);
}
| member '[' INTEGER ']'
{
	$$ = Sociaty_RoleExpend($1, atoi($3));
  free($3);
}
;

argument
: const_or_int 
{	
	$$ = Role_New();
	$$->_Flag = 1;
	$$->_Value = $1;
}
| role 
{
	$$ = $1;
}
| NULL_TOKEN {
	$$ = NULL;
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
| argument_list ','
{
	RoleArray_Add($1, NULL);
  $$ = $1;
}

;

%%

	//void ParseExpressionFromString(Expression *expr, char *str){
void ParseExpressionFromFp(FILE *fp){
	if(fp == NULL) return;
	char *content;
	content = ereadfile(fp);
	if(content != NULL){
		estraddeol(&content);
		ParseExpressionFromString(content, 0);
		free(content);
	}
	
//	free(fpath);
}
void ParseExpressionFromStdin(char* starter){
	char line[MAX_BLOCK_SIZE];
	int li,c;
	li = 0;
	while(c=getchar()){
		if(c == EOF){
//			printf("\n");
			break;
		}
		else if (c == '\n'){			
			line[li] = '\n';
			line[li+1] = '\0';
			if(ParseExpressionFromString(line,1)){
				printf("%s", starter);
				li = 0;
			}
			else{
				li ++;
			}
		}
		else{
			line[li++] = c;
		}
	}

}

void ParseExpressionFromFile(char *fpath){
  char *content;
  FILE *ifp;
  if(fpath[0]){
    if((ifp=fopen(fpath,"r")) != NULL){
			ParseExpressionFromFp(ifp);
			fclose(ifp);
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

//  free(fpath);
}

char ParseExpressionFromString(char *str, char istry){
//	printf("\nParseExpressionFromString\n=====\n%s\n=====\n\n", str);
  yyscan_t scanner;
//	current_scanner = scanner;
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
		if(!istry){
			eerror("yyparse failed");
			exit(1);
		}
		yy_delete_buffer(state, scanner);
		yylex_destroy(scanner);
		return 0;
  }
	yy_delete_buffer(state, scanner);
	yylex_destroy(scanner);
	return 1;
//	free(str);

}
void SetRole(Role* r, RoleArray* ra){
	char *rtn;
	Role *t;
	if(ra != NULL){
		t = Sociaty_RoleEmploy(r, "_Args");
		Sociaty_RoleSetElements(t, ra);
		rtn = Eval(r,evalargsstr);
		if(rtn != NULL){
			ParseExpressionFromString(rtn,0);
			free(rtn);
		}
	}
}
void EvalRole(Role* r){
	char *rtn;
	Role *t;
	fprintf(ns.Err, "\n%s\n", r->_Name);
	rtn = Eval(r, evalstr);
	if(rtn != NULL){
		yd_print(rtn);
		ParseExpressionFromString(rtn,0);
		free(rtn);
	}
}
