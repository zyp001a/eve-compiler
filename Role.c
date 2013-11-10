#include "Role.h"


struct Role{
  char* Name;
  char* Value;
	char* RawValue;
  IndexArray Subordinates; //Fields
  IndexArray Superiors;
  IndexArray Parents;
  IndexArray Children;
};
typedef struct Role Role;
void Role_Create(Role *v, char *name){
	v->Name = estrdup(name);
	IndexArray_Create(&v->Subordinates);
	IndexArray_Create(&v->Superiors);
	IndexArray_Create(&v->Parents);
	IndexArray_Create(&v->Children);
}
void Role_Set(Role *v, char *value){
	v->Value = estrdup(value);
}

struct RoleArray{
	Index Length;
  Role *Values;
};
typedef struct RoleArray RoleArray;
void RoleArray_Create(RoleArray * ia){
  ia->Length = 0;
  ia->Values = malloc(sizeof(Role));
}
Index RoleArray_Add(RoleArray * ia, char *name){
	Index p = ia->Length++;
  ia->Values = realloc(ia->Values,
											ia->Length * sizeof(Role));
	Role_Create(&ia->Values[p], name);
	return p;
}

Index RoleArray_Search(RoleArray * ia, char *name){
  Index i;
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



