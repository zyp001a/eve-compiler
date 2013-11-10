/*
 * Expression.h
 * Definition of the structure used to build the syntax tree.
 */
#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__
 
/**
 * @brief The operation type
 */
typedef enum tagEOperationType
{
	eVALUE,
	eMULTIPLY,
    ePLUS
} EOperationType;
 
/**
 * @brief The expression structure
 */
typedef struct tagExpression
{
	EOperationType type;///< type of operation
 
	int value;///< valid only when type is eVALUE
	struct tagExpression *left; ///< left side of the tree
	struct tagExpression *right;///< right side of the tree
} Expression;
 
/**
 * @brief It creates an identifier
 * @param value The number value
 * @return The expression or NULL in case of no memory
 */
Expression *createNumber(int value);
 
/**
 * @brief It creates an operation
 * @param type The operation type
 * @param left The left operand
 * @param right The right operand
 * @return The expression or NULL in case of no memory
 */
Expression *createOperation(EOperationType type, Expression *left, Expression *right);
 
/**
 * @brief Deletes a expression
 * @param b The expression
 */
void deleteExpression(Expression *b);
 
#endif // __EXPRESSION_H__
