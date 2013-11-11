#include "Sociaty.h"


Sociaty ns;
char *eve = "Eve";
FILE *out = stdout;


void Sociaty_Create(){
	RoleArray_Create(&ns.Members);
	RoleArray_AddNew(&ns.Members, eve);
}
Index Sociaty_AddNewRole(char *name){
	return RoleArray_AddNew(&ns.Members, name);
}
Index Sociaty_AddNewExpression(char *str){
	Expression e;
	//Expression_CreateByString(&e, str);
  return ExpressionArray_Add(&ns.Actions, &e);
}
void Sociaty_Output(char *str){
	fprintf(out, "%s\n", str);
}
Index Sociaty_SearchRole(char *name){
	return RoleArray_SearchByName(&ns.Members, name);
}
Role *Sociaty_GetRole(Index i){
	return ns.Members.Values + i;
}
Index Sociaty_GetRoleByName(char *name){
	Index i = Sociaty_SearchRole(name);
  if(i == -1) i = Sociaty_AddNewRole(name);
	return i;
}

int Sociaty_SearchPCRelation(Index pi, Index ci){
//	printf("search %d,%d\n",pi,ci);
	Role *parent, *child;
	int rtn;
	rtn = 0;
	rtn = Sociaty_SearchPRelation(pi, ci, rtn);
//	printf("prtn %d\n", rtn);
	if(rtn) return rtn;
	rtn = 0;
	rtn = Sociaty_SearchCRelation(pi, ci, rtn);
//	printf("crtn %d\n", rtn);
	return rtn;	
}

int Sociaty_SearchPRelation(Index pi, Index ci, int rtn){
	Role *child;
  Index i, subi;
	int subrtn;
	rtn ++;
  child = ns.Members.Values + ci;
  for(i=0; i<child->Parents.Length; i++){
		subi = child->Parents.Values[i];
    if(pi == subi)
			return rtn;
    subrtn = Sociaty_SearchPRelation(pi, subi, rtn);
		if(subrtn){
			return subrtn;
		}
  }
	return 0;
}

int Sociaty_SearchCRelation(Index pi, Index ci, int rtn){
	Role *child;
  Index i, subi;
	int subrtn;
	rtn --;
  child = ns.Members.Values + ci;
  for(i=0; i<child->Children.Length; i++){
		subi = child->Children.Values[i];
    if(pi == subi)
			return rtn;
    subrtn = Sociaty_SearchCRelation(pi, subi, rtn);
		if(subrtn){
			return subrtn;
		}
  }
	return 0;
}


void Sociaty_AddPCRelation(Index pi, Index ci){
	IndexArray_Add(&Sociaty_GetRole(pi)->Children, ci);
	IndexArray_Add(&Sociaty_GetRole(ci)->Parents, pi);
}
 
void Sociaty_AddSSRelation(Index pi, Index ci){
	IndexArray_Add(&Sociaty_GetRole(pi)->Subordinates, ci);
	IndexArray_Add(&Sociaty_GetRole(ci)->Superiors, pi);
}

void Sociaty_WriteIndexArray(IndexArray *a){
	Index i;
	printf("%d", a->Length);
	for(i=0; i<a->Length; i++){
		printf("\t%s", (ns.Members.Values + a->Values[i])->_Name);
	}
	printf("\n");
}
void Sociaty_WriteMembers(){
	Index i;
	Role *v;
	for(i=0;i<ns.Members.Length;i++){
		v = ns.Members.Values + i;
		printf("Index:    %d\n", i);
		printf("Name:     %s\n", v->_Name);
		printf("Value:    %s\n", v->_Value);
		printf("RawValue: %s\n", v->_RawValue);
		printf("Subordinates: ");
		Sociaty_WriteIndexArray(&v->Subordinates);
		printf("Superiors: ");
		Sociaty_WriteIndexArray(&v->Superiors);
		printf("Parents: ");
		Sociaty_WriteIndexArray(&v->Parents);
		printf("Children: ");
		Sociaty_WriteIndexArray(&v->Children);
	}
}

void Sociaty_EvalExpression(Expression *expr){
	switch (expr->Operation){
	case Value:
		Sociaty_Output(Sociaty_GetRole(expr->Role1)->_Value);
		return;
	case Set:
		Sociaty_GetRole(expr->Role1)->_Value = 
			estrdup(Sociaty_GetRole(expr->Role2)->_Value);
		return;
	case Gen:
		Sociaty_AddPCRelation(expr->Role1, 
													expr->Role2);
		return;		
  case Hire:
    Sociaty_AddSSRelation(expr->Role1, 
													expr->Role2);
    return;
	case Include:
		//Include
	case Eval:
		//Evaluate
		return;
	default:
		eerror("Expression_Eval: unknown operation");
	}
}

/*
main(){
	Sociaty_Create();
	printf("Sociaty Created\n");
	Sociaty_AddSSRelation("a","b");
	Sociaty_AddPCRelation("c","b");
	Sociaty_AddPCRelation("a","c");

	Sociaty_SearchPCRelation(2,1);
	Sociaty_Write();
}
*/
