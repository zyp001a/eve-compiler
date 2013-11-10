#include "Expression.h"

/*
void Expression_Create(Expression *expr,
											 Role *role1, Role *role2, OperationType op){
	expr = malloc(sizeof(Expression));
	expr->Role1 = role1;
	expr->Role2 = role2;
	expr->Operation = op;
}
*/

void Expression_CreateGen(Expression *expr, char *name1, char *name2){

}
void Expression_CreateEval(Expression *expr, char *name){

}
void Expression_CreateSet(Expression *expr, char *name1, char *name2){

}
/*
void Expression_CreateByString(Expression *expr, char *str){
  yyscan_t scanner;
  YY_BUFFER_STATE state;
	if (yylex_init(&scanner)) {
    // couldn't initialize
		eerror("yylex_init failed");
    return;
  }
	state = yy_scan_string(str, scanner);
	if (yyparse(&expr, scanner)) {
    // error parsing
		eerror("yyparse failed");
    return NULL;
  }
	yy_delete_buffer(state, scanner);
	yylex_destroy(scanner);
}
*/
															 
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


