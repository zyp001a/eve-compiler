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
Expression* Expression_Create(Index i1, Index i2, OperationType op);


//
#endif
