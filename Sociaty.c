#include "Sociaty.h"


extern Sociaty ns;
extern char *eve;
extern char *const_name;
extern int const_count;
extern FILE* out;


void Sociaty_Create(){
	RoleArray_Create(&ns.Members);
	RoleArray_AddNew(&ns.Members, eve);
	Hash_Create(&ns.UsedFiles);
}

void Sociaty_AddUsedFile(char *f){
	Hash_Add(&ns.UsedFiles, f);
}
Index Sociaty_SearchUsedFile(char *f){
  return Hash_Search(&ns.UsedFiles, f);
}


Index Sociaty_AddRole(Role *r){
	return RoleArray_Add(&ns.Members, r);
}

Index Sociaty_AddNewRole(char *name){
	Index i;
	i = Sociaty_SearchRole(name);
	if(i == -1){
		i = RoleArray_AddNew(&ns.Members, name);
		Sociaty_AddPCRelation(0, i);
	}
	return i;
}

Index Sociaty_AddChildRole(Index pi, char *name){
	Index i = RoleArray_AddNew(&ns.Members, name);
	Sociaty_AddPCRelation(pi, i);
  return i;
}

Index Sociaty_AddConstRole(char *str){
	char *name;
	char const_suffix[11];
	Index i;
	const_count ++;
	sprintf(const_suffix, "%d", const_count);
	strcpy(name, const_name);
	strcat(name, const_suffix);
  i = RoleArray_AddNew(&ns.Members, name);
	Sociaty_GetRole(i)->_Value
		= estrdup(str);
  Sociaty_AddPCRelation(0, i);
  return i;
}


/*
Index Sociaty_AddNewExpression(char *str){
	Expression e;
	//Expression_CreateByString(&e, str);
//  return ExpressionArray_Add(&ns.Actions, &e);
}
*/



Index Sociaty_SearchRole(char *name){
	return RoleArray_SearchByName(&ns.Members, name);
}
Role *Sociaty_GetRole(Index i){
	return ns.Members.Values + i;
}
char* Sociaty_GetValue(Index i){
	int ci = i;
	char *s;
//	while (Sociaty_GetRole(i)->Parents
  return s;
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
		printf("Subordinates: ");
		Sociaty_WriteIndexArray(&v->Subordinates);
		printf("Superiors: ");
		Sociaty_WriteIndexArray(&v->Superiors);
		printf("Parents: ");
		Sociaty_WriteIndexArray(&v->Parents);
		printf("Children: ");
		Sociaty_WriteIndexArray(&v->Children);
	printf("=====================\n");
	}

}
void Sociaty_PutChar(char c){
	fprintf(out, "%c", c);
}
void Sociaty_SetOut(char *str){
	if(estrisnull(str)){
		if(out != stdout && out != NULL) fclose(out);
		out = stdout;
	}
	else{
		out = fopen(str, "w");
	}
}
/*
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
*/

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
