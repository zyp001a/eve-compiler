#ifndef _EROLE
#define _EROLE
#include "Common.h"
//#include "RoleHash.h"
#define MAX_HASH_KEY_SIZE 64
#define RoleHash_Init(prh) RoleHash_InitCapacity(prh, 32)
#define RoleHash_HInit(prh) RoleHash_InitCapacity(prh, 128)


typedef struct Role Role;
typedef struct RoleArray RoleArray;
typedef struct RoleHash RoleHash;
typedef struct Pair Pair;
typedef struct Bucket Bucket;

struct Role{
  char* _Name;

//	Index _Index;
  char* _Value;
	Role* _Target;
	RoleArray *_Elements; 
	RoleHash *Subs;

	int Index;
	char Depth;
	char* Key;
	Role* Sup;

	RoleArray *Prts;
	char _Flag;

//	IndexArray Args; //Arguments
};

struct RoleArray{
	Index Length;
	Index Size;
  Role **Values;
};
struct RoleHash{
	unsigned int count;
  Bucket *buckets;
};

struct Pair {
	char key[MAX_HASH_KEY_SIZE];
	Role *value;
};
struct Bucket {
  unsigned int count;
  Pair *pairs;
};




Role* Role_New();
void Role_Set(Role *r, Role *t);

void Role_SetValue(Role *r, char *value);
void Role_SetTarget(Role *r, Role* t);
//void Role_SetElements(Role* r, RoleArray *ra);

Role* Role_GetSup(Role *r, char level);

void Role_AddSub(Role* r, char* key, Role* t);
void Role_AddPrt(Role* r, Role* t);
void Role_AddElements(Role* r, Role* t);

void Role_Free(Role *);
void Role_Print(Role *r);
void RoleArray_Init(RoleArray **a);
void RoleArray_Print(RoleArray *a);
RoleArray* RoleArray_New();
RoleArray* RoleArray_NewStringArray(StringArray *a);
Index RoleArray_Add(RoleArray *a, Role *r);
void RoleArray_Free(RoleArray *a);
Index RoleArray_Search(RoleArray *a, Role *r);
/*
void Role_Create(Role *v, char *name);
//void Role_AddElements(Role *v, Index *i);
void Role_Set(Role *v, char *value);

void RoleArray_Init(RoleArray *a);
Index RoleArray_Add(RoleArray *a, Role *r);
Index RoleArray_AddNew(RoleArray *a, char *name);
Index RoleArray_SearchByName(RoleArray *a, char *name);
void RoleArray_PassbySymbol(RoleArray *a, RoleArray *b);
//Role* CreateRole(char *name);
*/





static Pair *get_pair(Bucket *bucket, const char *key);
static unsigned long hash(const char *str);


void RoleHash_InitCapacity(RoleHash **map, unsigned int capacity);
Role* RoleHash_Get(const RoleHash *map, const char *key);
Role* RoleHash_GetOrPut(const RoleHash *map, const char *key);
void RoleHash_Put(const RoleHash *map, const char *key, const Role* value);
void RoleHash_Free(RoleHash *);
void RoleHash_Print(const RoleHash *map);
void RoleHash_PrintTree(const RoleHash *map);



#endif
