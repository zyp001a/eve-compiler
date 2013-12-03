#ifndef _ACTION
#define _ACTION
#include "Common.h"
#include "Role.h"
#include "Sociaty.h"
/*
typedef enum OperationType{
	THIS,
	PARENT,
	SUPERIOR,
	SUPERIOR2,
	VALUE
} OperationType;
*/
typedef struct Scanner{
	Role *r; //role
//	Role *cr;
//	char *in_tmp; //tmp poiner
	char *in_curr; //input poiner 
	char **out_curr; //output pointer
} Scanner;

typedef struct TokenParam{
	Role *r; // invoke role
//	Role *cr; //current role
	char *title;//|title|
	int len; //title len
	char *op;// %$$ &@@ & %
	int oplen; //op len
	char c; //'V' 'N' 'E' in &-E[0]
	int index; // 0 in &-E[0]
} TokenParam;

char* Eval(Index i);
char* EvalString(Index i, char *str);

char* GetPath(char *);
//Lang GetLang(char *);
char GetFlag(char *);
char *GetParentName(Role *r);
char ExistValue(Role *r);
char *GetValue(Role *r);
char* GetValueDeep(char *name);

char* GetDymValue(char *name); //for any name return a value
//Role* GetRole(char *name);
char EvalParam(TokenParam *pp, Scanner *ps);
char ScanIdentifer(Scanner *ps);
void InterpretValue(Role *r, char *v, char **out_curr);


#endif
