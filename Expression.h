#ifndef _EXPRESSION
#define _EXPRESSION
#include "Common.h"
#include "Role.h"




/**
 * @brief The operation type
 */
typedef enum OperationType
{
	Value,
	Set,
  Eval,
  Gen,
	Hire,
	Include

} OperationType;
/**
 * @brief The expression structure
 */
typedef struct Expression
{
	OperationType Operation;
	Index Role1;
	Index Role2;
} Expression;
typedef struct ExpressionArray
{
	Index Length;
	Expression *Values;
} ExpressionArray;

void Expression_CreateGen(Expression *expr, char *name1, char *name2);
void Expression_CreateEval(Expression *expr, char *name);
void Expression_CreateSet(Expression *expr, char *name1, char *name2);
void ExpressionArray_Create(ExpressionArray *a);
Index ExpressionArray_Add(ExpressionArray *a, Expression *e);

//
#endif
