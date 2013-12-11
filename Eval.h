#ifndef _EEVAL
#define _EEVAL
#include "Common.h"
#include "Role.h"
#include "Sociaty.h"
#include "Platform.h"
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
	char is_read;
} Scanner;

typedef struct TokenParam{

	char **keys;
	char *issubs;
	int steplen;

	char *op;// %$$ &@@ & %
	int oplen; //op len
	char c; //'V' 'N' 'E' in &-E[0]
//	int index; // 0 in &-E[0]
	char argv[7][255];
	char argc;
} TokenParam;

char* Eval(Role *r);
char* EvalString(Role *r, char *str, char op);
char* UseFile(char *str);
char* GetPath(char *);
char* GetDefaultValue(Role *r);
char* GetNoDefaultValue(Role *r);
char* GetDymValue(Role *r); //for any name return a value
char DoReadParam(TokenParam *pp, Scanner *ps, Role *r);
char DoWriteParam(TokenParam *pp, Scanner *ps, Role *r);
char EvalParam(TokenParam *pp, Scanner *ps);
char ScanIdentifer(Scanner *ps);
void InterpretValue(Role *r, char *v, char **out_curr, char);


//Lang GetLang(char *);
char GetFlag(char *);
char *GetParentName(Role *r);
//Role* GetRole(char *name);



#endif
