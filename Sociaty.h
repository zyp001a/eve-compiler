#ifndef _SOCIATY
#define _SOCIATY

#include "Common.h"
#include "Role.h"
#include "Expression.h"

#define MAX_ROLE 1000000
typedef struct Sociaty{
	RoleArray Members;
	ExpressionArray Actions;
} Sociaty;


void Sociaty_Create();
Index Sociaty_AddNewRole(char *name);
Index Sociaty_AddNewExpression(char *str);
void Sociaty_Output(char *str);
Index Sociaty_SearchRole(char *name);
Role *Sociaty_GetRole(Index i);
Index Sociaty_GetRoleByName(char *name);

int Sociaty_SearchPCRelation(Index pi, Index ci);
int Sociaty_SearchPRelation(Index pi, Index ci, int rtn);
int Sociaty_SearchCRelation(Index pi, Index ci, int rtn);
void Sociaty_AddPCRelation(Index pi, Index ci);
void Sociaty_AddSSRelation(Index pi, Index ci);
void Sociaty_WriteMembers();
void Sociaty_EvalExpression(Expression *expr);

#endif
