//#include "radix-tree.h"
//#include "uthash.h"
#include <stdio.h>
#include "hash.h"
struct my_struct {
	char key[20];     
  char value[20];
  UT_hash_handle hh; /* makes this structure hashable */
};

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


}
