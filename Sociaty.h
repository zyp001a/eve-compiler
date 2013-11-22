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
char* Sociaty_GetValue(Index i);
Index Sociaty_GetRoleByName(char *name);

int Sociaty_SearchPCRelation(Index pi, Index ci);
int Sociaty_SearchPRelation(Index pi, Index ci, int rtn);
int Sociaty_SearchCRelation(Index pi, Index ci, int rtn);
void Sociaty_AddPCRelation(Index pi, Index ci);
void Sociaty_AddSSRelation(Index pi, Index ci);
void Sociaty_WriteMembers();
//void Sociaty_EvalExpression(Expression *);
void Sociaty_PutChar(char);
void Sociaty_PutString(char*);
void Sociaty_SetOut(char *);


#endif
