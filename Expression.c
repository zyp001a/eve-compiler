#include "Hierachy.h"

struct Action{
	char Code[4096];
};
typedef struct Action Action;
struct Role{
  char Name[256];
  Action Function;
  IndexArray Subordinates //Fields;
  IndexArray Superiors;
  IndexArray Parents;
  IndexArray Children;
};
typedef struct Role Role;
void Role_Create(Role *v, char *name){
	strcpy(v->Name, name);
	IndexArray_Create(&v->Subordinates);
	IndexArray_Create(&v->Superiors);
	IndexArray_Create(&v->Parents);
	IndexArray_Create(&v->Children);
}
void Role_SetCode(Role *v, char *code){
	strcpy(v->Function.Code, code);
}
void Role_ParseCode(Role *v){
	if(v->Function.Code[0] == 'c'){
		
//		strcpy(v->Function.Code, str_replace((char*)v->Function.Code, "c{{", ""));
//   strcpy(v->Function.Code, str_replace((char*)v->Function.Code, "}}", ""));
		printf("%s\n", v->Function.Code);
	}
	else{
		fprintf(stderr, "scancode: %s", v->Function.Code);
//		strcpy(v->Function.Code, str_replace((char*)v->Function.Code, "{{", ""));
//		strcpy(v->Function.Code, str_replace((char*)v->Function.Code, "}}", ""));

		scancode(v->Function.Code);
	}
	
}
// You must free the result if result is non-NULL.
struct RoleArray{
	int Length;
  Role *Values;
};
typedef struct RoleArray RoleArray;
Role* null_role;
void RoleArray_Create(RoleArray * ia){
  ia->Length = 0;
  ia->Values = malloc(sizeof(Role));
}
int RoleArray_Add(RoleArray * ia, char *name){
	int p = ia->Length++;
  ia->Values = realloc(ia->Values,
											ia->Length * sizeof(Role));
	Role_Create(&ia->Values[p], name);
	return p;
}

int RoleArray_Search(RoleArray * ia, char *name){
  int i;
  Role *v;
  for(i=0;i<ia->Length;i++){
    v = ia->Values + i;
    if(!strcmp(v->Name, name)){
      return i;
      break;
    }
  }
  return -1;
}


struct Sociaty{
	RoleArray Members;
};
typedef struct Sociaty Sociaty;
Sociaty ns;
void Sociaty_Create(){
	RoleArray_Create(&ns.Members);
	RoleArray_Add(&ns.Members, "eve");
}
void Sociaty_AddRole(char *name){
	RoleArray_Add(&ns.Members, name);
}
Role* Sociaty_SearchRole(char *name){
	int i = RoleArray_Search(&ns.Members, name);
	return ns.Members.Values + i;
}

int Sociaty_SearchPCRelation(int pi, int ci){
//	printf("search %d,%d\n",pi,ci);
	Role *parent, *child;
	int i, rtn;
	rtn = 0;
	rtn = Sociaty_SearchPRelation(pi, ci, rtn);
//	printf("prtn %d\n", rtn);
	if(rtn) return rtn;
	rtn = 0;
	rtn = Sociaty_SearchCRelation(pi, ci, rtn);
//	printf("crtn %d\n", rtn);
	return rtn;	
}

int Sociaty_SearchPRelation(int pi, int ci, int rtn){
	Role *child;
  int i;
	int subrtn, subi;
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
int Sociaty_SearchCRelation(int pi, int ci, int rtn){
	Role *child;
  int i;
	int subrtn, subi;
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

void Sociaty_AddPCRelation(char *parent_name, char *child_name){
	Role *parent, *child;
	int pi,ci;
	pi = RoleArray_Search(&ns.Members, parent_name);
	if(pi == -1) pi = RoleArray_Add(&ns.Members, parent_name);

	ci = RoleArray_Search(&ns.Members, child_name);
	if(ci == -1) ci = RoleArray_Add(&ns.Members, child_name);

	int rtn = Sociaty_SearchPCRelation(pi, ci);
	if(rtn){
		fprintf(stderr, "%s cannot be the parent of %s: %d\n", 
						parent_name, child_name, rtn);
		return;
	}

	parent = ns.Members.Values + pi;
	child = ns.Members.Values + ci;

	IndexArray_Add(&parent->Children, ci);
	IndexArray_Add(&child->Parents, pi);
	if(pi !=0 && parent->Parents.Length == 0){
//not eve and no parent
//  must be eve's child
		Sociaty_AddPCRelation("eve", parent_name);
	}
		
}
 
void Sociaty_AddSSRelation(char *superior_name, char *subordinate_name){
	Role *parent, *child;
	int pi,ci;
	pi = RoleArray_Search(&ns.Members, superior_name);
	if(pi == -1) pi = RoleArray_Add(&ns.Members, superior_name);

	ci = RoleArray_Search(&ns.Members, subordinate_name);
	if(ci == -1) ci = RoleArray_Add(&ns.Members, subordinate_name);

	parent = ns.Members.Values + pi;
	child = ns.Members.Values + ci;

	IndexArray_Add(&parent->Subordinates, ci);
	IndexArray_Add(&child->Superiors, pi);
  if(pi !=0 && parent->Superiors.Length == 0){
//not eve and no parent
//  must be eve's child
    Sociaty_AddSSRelation("eve", superior_name);
	}

} 
void Sociaty_WriteIndexArray(IndexArray *a){
	int i;
	printf("%d", a->Length);
	for(i=0; i<a->Length; i++){
		printf("\t%s", (ns.Members.Values + a->Values[i])->Name);
	}
	printf("\n");
}
void Sociaty_Write(){
	int i,j;
	Role *v;
	for(i=0;i<ns.Members.Length;i++){
		v = ns.Members.Values + i;
		printf("%d\t%s\n", i, v->Name);
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
