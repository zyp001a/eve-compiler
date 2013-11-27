//#include "3rd.h"
#include <stdio.h>

main(){
/*
	HashII *h;
	HashII_Init(&h);
	HashII_Add(&h, 1, 2);
//	int a = HashII_SearchValue(&h, 1);
	HashII *e;
	int k=1;
	HASH_FIND_INT(h, &k, e);
	printf("%d\n", e->value);
*/
	char a[8] = {'\0', '\0', '\0', '\0', '\0', '\0', 'b', 'a'};
	int c[10000] ={};
	int b = 0;
	b = a[7];
	b <<= 8;
	b += a[6];
	printf("%d\t%d\n", b, 97*256+98);
	b= 10000-1;
	printf("%d\n",sizeof(size_t));

}
