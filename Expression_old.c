/*
 * Expression.c
 * Implementation of functions used to build the syntax tree.
 */
 
#include "Expression.h"
 
#include <stdlib.h>
 
/**
 * @brief Allocates space for expression
 * @return The expression or NULL if not enough memory
 */
static Expression *allocateExpression()
{
	Expression *b = (Expression *)malloc(sizeof *b);
 
	if (b == NULL)
		return NULL;
 
	b->type = eVALUE;
	b->value = 0;
 
	b->left = NULL;
	b->right = NULL;
 
	return b;
}
 
Expression *createNumber(int value)
{
	Expression *b = allocateExpression();
 
	if (b == NULL)
		return NULL;
 
	b->type = eVALUE;
	b->value = value;
 
	return b;
}
 
Expression *createOperation(EOperationType type, Expression *left, Expression *right)
{
	Expression *b = allocateExpression();
 
	if (b == NULL)
		return NULL;
 
	b->type = type;
	b->left = left;
	b->right = right;
 
	return b;
}
 
void deleteExpression(Expression *b)
{
	if (b == NULL)
		return;
 
	deleteExpression(b->left);
	deleteExpression(b->right);
 
	free(b);
}
