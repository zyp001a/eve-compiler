#ifndef _SOCIATY
#define _SOCIATY

#include "Common.h"
#include "Role.h"
#include "Hash.h"
//#include "Expression.h"

#define MAX_ROLE 1000000
typedef struct Sociaty{
	RoleArray Members;
	Hash UsedFiles;
	FILE *Out;
	FILE *Err;
	char OutFile[MAX_FILE_NAME];
	char ProgramFile[MAX_FILE_NAME];
	int Step;
} Sociaty;

void Sociaty_Create();
void Sociaty_AddUsedFile(char *f);
Index Sociaty_SearchUsedFile(char *f);
Index Sociaty_AddRole(Role *r);
Index Sociaty_AddNewRole(char *name);
Index Sociaty_AddChildRole(Index pi, char *name);
Index Sociaty_AddConstRole(char *str);
//Index Sociaty_AddNewExpression(char *str);
Index Sociaty_SearchRole(char *name);
Role* Sociaty_GetRole(Index i);
Role* Sociaty_GetFinalRole(Index i);
char* Sociaty_GetValue(Index i);
void Sociaty_RoleAssignArrayByStringArray(Index pi, int len, char **a);
void Sociaty_RoleAssignArray(Index i, StringIntArray *a);
Index Sociaty_RoleAddSubordinate(Index i, char *str);
Index Sociaty_RoleAddElement(Index i, char *str);
Index Sociaty_GetRoleByName(char *name);
void Sociaty_ClearArgs(Index pi);
int Sociaty_SearchPCRelation(Index pi, Index ci);
int Sociaty_SearchPRelation(Index pi, Index ci, int rtn);
int Sociaty_SearchCRelation(Index pi, Index ci, int rtn);
void Sociaty_AddPCRelation(Index pi, Index ci); //parent child
void Sociaty_AddSSRelation(Index pi, Index ci); //superior subordinate
void Sociaty_AddSERelation(Index pi, Index ci); //set element
void Sociaty_WriteMembers();
//void Sociaty_EvalExpression(Expression *);

void Sociaty_PutString(char*);
void Sociaty_SetOut(char *, char *);



void Sociaty_PutChar(char);

#endif
