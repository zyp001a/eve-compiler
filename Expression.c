#include "Expression.h"


Expression* Expression_Create(Index i1, Index i2, OperationType op){
	Expression *expr;
	expr = malloc(sizeof(Expression));
	expr->Role1 = i1;
	expr->Role2 = i2;
	expr->Operation = op;
	return expr;
}

/*															 
void ExpressionArray_Create(ExpressionArray *a){
	a->Length = 0;
	a->Values = (Expression*)malloc(sizeof(Expression));
}

Index ExpressionArray_Add(ExpressionArray *a, Expression *e){
	Index p = a->Length++;
  a->Values = (Expression*)realloc(a->Values,
                      a->Length * sizeof(Expression));
	a->Values[p] = *e;
}
*/
/*
Index ExpressionArray_AddNew(ExpressionArray *a, 
														Role *role1, Role *role2, OperationType op){
	
  Index p = a->Length++;
  a->Values = realloc(a->Values,
                      a->Length * sizeof(Expression));
  Expression_Create(&a->Values[p], role1, role2, op);
  return p;
}
*/


