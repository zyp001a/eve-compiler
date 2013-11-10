#include "Sociaty.h"

struct Sociaty{
	RoleArray Members;
};
typedef struct Sociaty Sociaty;

Sociaty ns;
char* eve = "Eve";
void Sociaty_Create(){
	RoleArray_Create(&ns.Members);
	RoleArray_Add(&ns.Members, eve);
}
Index Sociaty_AddRole(char *name){
	return RoleArray_Add(&ns.Members, name);
}
Index Sociaty_SearchRole(char *name){
	return RoleArray_Search(&ns.Members, name);
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

Index Sociaty_GetRole(char *name){
	Index i = Sociaty_SearchRole(name);
  if(i == -1) i = Sociaty_AddRole(name);
	return i;
}
void Sociaty_AddPCRelation(Index pi, Index ci){
	Role *parent, *child;

/*	int rtn = Sociaty_SearchPCRelation(pi, ci);
	if(rtn){
		fprintf(stderr, "%s cannot be the parent of %s: %d\n", 
						parent_name, child_name, rtn);
		return;
	}
*/
	parent = ns.Members.Values + pi;
	child = ns.Members.Values + ci;

	IndexArray_Add(&parent->Children, ci);
	IndexArray_Add(&child->Parents, pi);
/*
	if(pi !=0 && parent->Parents.Length == 0){
//not eve and no parent
//  must be eve's child
		Sociaty_AddPCRelation("eve", parent_name);
	}
*/		
}
 
void Sociaty_AddSSRelation(Index p1, Index ci){
	Role *parent, *child;

	parent = ns.Members.Values + pi;
	child = ns.Members.Values + ci;

	IndexArray_Add(&parent->Subordinates, ci);
	IndexArray_Add(&child->Superiors, pi);
}
 
void Sociaty_WriteIndexArray(IndexArray *a){
	Index i;
	printf("%d", a->Length);
	for(i=0; i<a->Length; i++){
		printf("\t%s", (ns.Members.Values + a->Values[i])->Name);
	}
	printf("\n");
}
void Sociaty_Write(){
	Index i;
	Role *v;
	for(i=0;i<ns.Members.Length;i++){
		v = ns.Members.Values + i;
		printf("Index:    %d\n", i);
		printf("Name:     %s\n", v->Name);
		printf("Value:    %s\n", v->Value);
		printf("RawValue: %s\n", v->RawValue);
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
