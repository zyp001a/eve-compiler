#ifndef _ROLE
#define _ROLE
#include "Common.h"
/*
typedef enum Lang{
  awk,
	bash,
	c,
	m4,
	matlab,
	perl,
	python,
	r,

	stdout
} Lang;
*/

typedef struct Role{
  char* _Name;
  char* _Value;
	char _Flag;
	Index _Index;
  IndexArray Subordinates; //Fields
  IndexArray Superiors;
  IndexArray Parents;
  IndexArray Children;
} Role;

typedef struct RoleArray{
	Index Length;
  Role *Values;
} RoleArray;
void Role_Create(Role *v, char *name);
void Role_Set(Role *v, char *value);
void RoleArray_Create(RoleArray *a);
Index RoleArray_Add(RoleArray *a, Role *r);
Index RoleArray_AddNew(RoleArray *a, char *name);
Index RoleArray_SearchByName(RoleArray *a, char *name);
Role* CreateRole(char *name);


#endif
