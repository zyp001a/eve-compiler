//#include "3rd.h"
#include "HashStr2Int.h"
#include <stdio.h>
static void iter_print(const char *key, const int value)
{
  printf("key %s: %d\n", key, value);
}

main(){
	sihash *h;
	h = sihash_new(128);
	sihash_put(h, "aa", 1);
	sihash_put(h, "aa", 2);
	sihash_incr(h,"bb");
	sihash_incr(h,"bb");
	sihash_incr(h,"bb");
	printf("%d\n", sihash_get(h,"aa"));
	printf("%d\n", sihash_get(h,"bb"));
	sihash_enum(h, &iter_print);
	
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
