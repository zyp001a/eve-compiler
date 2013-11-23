#ifndef _ACTION
#define _ACTION
#include "Common.h"
#include "Role.h"
#include "Sociaty.h"

typedef enum OperationType{
	THIS,
	PARENT,
	SUPERIOR,
	SUPERIOR2,
	VALUE
} OperationType;

typedef struct Scanner{
	Role *r; //role
	char *in_tmp; //tmp poiner
	char *in_curr; //input poiner 
	char **out_curr; //output pointer
} Scanner;

typedef struct TokenParam{
	Role *r;
	char *title;
	int len;
	int index;
} TokenParam;

char* Eval(Index i);
char* EvalString(Index i, char *str);
char* GetPath(char *);
//Lang GetLang(char *);
char GetFlag(char *);

char* GetTitleName(Role *r);

char* GetValue(TokenParam *);
char *GetValueRecursive(TokenParam *);
char* GetValueByName(TokenParam *);
char* GetValueFromSuperiors(TokenParam *);
char* GetValueFromParents(TokenParam *);
char* GetValueFromParents2(TokenParam *);

char* GetEvalValue(Role *r);
void InterpretValue(Index i, char *value, char **result);


#endif
