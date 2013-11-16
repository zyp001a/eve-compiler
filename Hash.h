#include "Common.h"
typedef struct Hash{
	char **DataTable;
	int Length;
} Hash;
void Hash_Create(Hash*);
Index Hash_Add(Hash*, char *);
Index Hash_Search(Hash*, char *);
