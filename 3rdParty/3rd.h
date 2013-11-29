#include "strmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRMAP_STR 255
static void iter(const char *key, const char *value, const void *obj)
{
  fprintf(stderr, "%s: %s\n", key, value);
}
typedef StrMap* Hash;
void Hash_Init(Hash *h){
	*h = sm_new(128);
	if (*h == NULL) { fprintf(stderr,"alloc hash failed\n"); }
}
void Hash_Add(Hash *h, char *key, char *value){
	sm_put(*h, key, value);
}
void Hash_GetValue(Hash *h, char *key, char **value){
	char *buf;
	buf = malloc(MAX_STRMAP_STR);
  int resultc;
	resultc = sm_get(*h, key, buf, MAX_STRMAP_STR);
  if (resultc == 0){
//		printf("%s: %s\n", key, buf);
		*value = "";
	}
	else{
//		printf("%s: %s\n", key, buf);
		*value = buf;
	}
}
void Hash_AddInt(Hash *h, char *key, long value){
  sm_put(*h, key, (char*)value);
}
void Hash_GetValueInt(Hash *h, char *key, long *value){
  char *buf;
  buf = malloc(MAX_STRMAP_STR);
  int resultc;
  resultc = sm_get(*h, key, buf, MAX_STRMAP_STR);
  if (resultc == 0){
//    printf("%s: %s\n", key, buf);
    *value = 0;
  }
  else{
//    printf("%s: %s\n", key, buf);
    *value = (size_t)buf;
  }
}



/*
typedef struct HashII{
	int key;
	int value;
	UT_hash_handle hh; 
} HashII;
void HashII_Init(HashII **ph){
	*ph = NULL;
}
void HashII_Add(HashII **ph, int k, int v){
  HashII *e;
	HashII buf;
//	e = &buf;
	e=(HashII*)malloc(sizeof(HashII));
  e->key = k;
  e->value = v;
	HashII *h;
	h = *ph;
  HASH_ADD_INT(h, key, e);
	printf("%d\t%d\n",e->key, e->value);
}
int HashII_SearchValue(HashII **ph, int k){
  HashII *e;
	HashII *h;
  h = *ph;
//	HASH_FIND_INT(h, &k, e);
//	return e->value;
	return 0;
}
HashII* HashII_SearchPair(HashII *h, int k){
	HashII *e;
  HASH_FIND_INT(h, &k, e);
	return e;
}
void HashII_SearchAndDelete(HashII *h, int k){
	HashII *e;
  HASH_FIND_INT(h, &k, e);
	HASH_DEL(h, e);
}
*/



