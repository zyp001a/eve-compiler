#include "Role.h"



void Role_Create(Role *v, char *name){
	estrdup(v->_Name ,name);
	IndexArray_Create(&v->Subordinates);
	IndexArray_Create(&v->Superiors);
	IndexArray_Create(&v->Parents);
	IndexArray_Create(&v->Children);
}
void Role_Set(Role *v, char *value){
	estrdup(v->_Value ,value);
}

void RoleArray_Create(RoleArray *a){
  a->Length = 0;
  a->Values = (Role*)malloc(sizeof(Role));
}
Index RoleArray_AddNew(RoleArray *a, char *name){
	Index p = a->Length++;
  a->Values = (Role*)realloc(a->Values,
											a->Length * sizeof(Role));
	Role_Create(&a->Values[p], name);
	return p;
}

Index RoleArray_SearchByName(RoleArray *a, char *name){
  Index i;
  Role *v;
  for(i=0;i<a->Length;i++){
    v = a->Values + i;
    if(!strcmp(v->_Name, name)){
      return i;
      break;
    }
  }
  return -1;
}



