//#include "3rd.h"
#include "str2int.h"
#include <stdio.h>
static void iter_print(const char *key, const int value)
{
  printf("key %s: %d\n", key, value);
}

main(){
	StrIntMap *h;
	h = sim_new(128);
	sim_put(h, "aa", 1);
	sim_put(h, "aa", 2);
	sim_incr(h,"bb");
	sim_incr(h,"bb");
	sim_incr(h,"bb");
	printf("%d\n", sim_get(h,"aa"));
	printf("%d\n", sim_get(h,"bb"));
	sim_enum(h, &iter_print);
	
/*
	Hash h;
	Hash_Init(&h);
	Hash_Add(&h, "111", "AAA");
	Hash_Add(&h, "112", "AAB");
	Hash_AddInt(&h, "113", 1);
	char *a;

	Hash_GetValue(&h, "111", &a);
	printf("%s\n",a);

	Hash_GetValue(&h, "112", &a);
	long b;
	printf("%s\n",a);
	Hash_GetValueInt(&h, "113", &b);
  printf("%ld\n",b);
*/
	
}
