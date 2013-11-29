#include "radix-tree.h"
#include "uthash.h"
#include "strmap.h"
#include <stdio.h>

struct my_struct {
	char key[20];     
  char value[20];
  UT_hash_handle hh; /* makes this structure hashable */
};


static void iter(const char *key, const char *value, const void *obj)
{
	printf("key: %s value: %s\n", key, value);
}

main(){

	struct radix_tree_root root;
	char **result;
	INIT_RADIX_TREE(&root);
	int d = 11;
	radix_tree_insert(&root, 0, &d);
	char *a;
	a = radix_tree_lookup(&root, 0);
	printf("%d\n",*a);


	struct my_struct *users = NULL;
	struct my_struct s;
	struct my_struct *ps1;
	ps1 = &s;
	strcpy(ps1->key, "aaa");
	strcpy(ps1->value, "bbb");

	HASH_ADD_STR( users, key, ps1 );
	struct my_struct *ps;
	HASH_FIND_STR( users, "aaa", ps );  
	
	printf("%s\n",ps->value);


	StrMap *sm;
	char buf[255];
	int resultc;
	sm = sm_new(10);
	if (sm == NULL) {
    /* Handle allocation failure... */
	}
	/* Insert a couple of string associations */
	sm_put(sm, "application name", "Test Application");
	sm_put(sm, "application version", "1.0.0");
	/* Retrieve a value */
	resultc = sm_get(sm, "application name", buf, sizeof(buf));
	if (resultc == 0) {
    /* Handle value not found... */
	}
	printf("value: %s\n", buf);
	sm_enum(sm, iter, NULL);
/* When done, destroy the StrMap object */
	sm_delete(sm);

}
