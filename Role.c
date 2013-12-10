#include "Role.h"



Role* Role_New(){
	Role *r = (Role*)malloc(sizeof(Role));

	r->_Name = NULL;

	r->_Value = NULL;
	r->_Target = NULL;
	RoleArray_Init(&r->_Elements);
	RoleHash_Init(&r->Subs);
	
	r->Index = -1;
	r->Depth = -1;
	r->Key = NULL;
	r->Sup = NULL;
	RoleArray_Init(&r->Prts);

	return r;
}
void Role_Print(Role *r){

	fprintf(stderr, "\nvalue %s,\nname %s\nkey %s\ndepth %d\nindex %d\n", 
					r->_Value, r->_Name, r->Key, r->Depth, r->Index
		);

}

void Role_Free(Role *r){
	if(r->_Value != NULL) free(r->_Value);
	if(r->_Name != NULL) free(r->_Name);
	if(r->Key != NULL) free(r->Key);

	RoleHash_Free(r->Subs);	
	RoleArray_Free(r->Prts);	
	RoleArray_Free(r->_Elements);
	free(r);
}
void Role_SetName(Role *r, char *name){
	if(r->_Name == NULL) 
		free(r->_Name);
	r->_Name = estrdup(name);
}
void Role_SetKey(Role *r, char *key){
	if(r->Key == NULL) 
		free(r->Key);
	r->Key = estrdup(key);
}
void Role_SetValue(Role *r, char *value){
	if(r->_Value == NULL) 
		free(r->_Value);
	r->_Value = estrdup(value);
}
void Role_SetTarget(Role *r, Role* t){
  r->_Target = t;
}



Role* Role_GetSup(Role *r, char level){
	if(level == 0)
		return r;
	else if(level == 1)
		return r->Sup;
	else
		return Role_GetSup(r->Sup, level-1);
}
char* Role_GetFinalValue(Role *r){
	Role *tr = r;
	while(tr->_Target != NULL)
		tr = r->_Target;
	return tr->_Value;
}


void Role_AddSub(Role* r, char* key, Role* t){
	RoleHash_Put(r->Subs, key, t);
}

static char Role_IsDirectlyRelevant(Role *r, Role *t, char op){
	Role *tmp;
	int i;

	if(op > -1 && RoleArray_Search(r->Prts, t) != -1){
		return 1;
	}

	if(op < 1 && RoleArray_Search(t->Prts, r) != -1){
		return -1;
	}

	for(i=0; i<r->Prts->Length; i++){
    tmp = r->Prts->Values[i];
		if(Role_IsDirectlyRelevant(tmp, t, 1)){
			return 1;
		}
	}
	for(i=0; i<t->Prts->Length; i++){
    tmp = t->Prts->Values[i];
    if(Role_IsDirectlyRelevant(r, tmp, -1)) return -1;
  }
	return 0;
}
void Role_AddPrt(Role* r, Role* t){
	if(Role_IsDirectlyRelevant(r,t,0))
		eerror("Directly Relevant !");
	else
		RoleArray_Add(r->Prts, t);
}
void Role_AddElements(Role* r, Role* t){
	RoleArray_Add(r->_Elements, t);
}





void RoleArray_Init(RoleArray **a){
	*a = (RoleArray *)malloc(sizeof(RoleArray));
  (*a)->Length = 0;
	(*a)->Size =0;
  (*a)->Values = NULL;
}
RoleArray* RoleArray_New(){
	RoleArray *ra;
	RoleArray_Init(&ra);
	return ra;
}

Index RoleArray_Add(RoleArray *a, Role *r){	
  Index p = a->Length++;
	if(a->Length >a->Size) a->Size ++;
	if(a->Values == NULL)
		a->Values = (Role**)malloc(sizeof(Role*));
	else
		a->Values = (Role**)realloc(a->Values,
														 a->Length * sizeof(Role*));
	a->Values[p] = r;
}
void RoleArray_Free(RoleArray *a){
	int i;
	for(i=0; i<a->Size; i++)
		Role_Free(a->Values[i]);
	free(a);
}

Index RoleArray_Search(RoleArray *a, Role *r){
  Index i;
  for(i=0;i<a->Length;i++){
    if(a->Values[i] == r) return i;
  }
  return -1;
}
/*
void RoleArray_PassbySymbol(RoleArray *a, RoleArray *b){
	if (a->Values != NULL){
		free(a->Values);
	}
	*a = *b;
}
*/

/*
 *    bellow code is modified from "strmap version 2.0.1" by setupx
 *
 *    ANSI C hash table for strings.
 *
 *    Version history:
 *    1.0.0 - initial release
 *    2.0.0 - changed function prefix from strmap to sm to ensure
 *        ANSI C compatibility
 *    2.0.1 - improved documentation
 *
 *    strmap.h
 *
 *    Copyright (c) 2009, 2011, 2013 Per Ola Kristensson.
 *
 *    Per Ola Kristensson <pok21@cam.ac.uk>
 *    Inference Group, Department of Physics
 *    University of Cambridge
 *    Cavendish Laboratory
 *    JJ Thomson Avenue
 *    CB3 0HE Cambridge
 *    United Kingdom
 *    strmap is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published \
by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
 */


void RoleHash_InitCapacity(RoleHash **map, unsigned int capacity){
  *map = malloc(sizeof(RoleHash));
  (*map)->count = capacity;

  (*map)->buckets = malloc((*map)->count * sizeof(Bucket));
  memset((*map)->buckets, 0,(*map)->count * sizeof(Bucket));
}
void RoleHash_Free(RoleHash *map){
	unsigned int i, j, n, m;
  Bucket *bucket;
  Pair *pair;

  if (map == NULL) {
    return;
  }
  n = map->count;
  bucket = map->buckets;
  i = 0;
  while (i < n) {
    m = bucket->count;
		pair = bucket->pairs;
    j = 0;
    while(j < m) {
      free(pair->value);
      pair++;
      j++;
    }
    free(bucket->pairs);
    bucket++;
    i++;
  }
  free(map->buckets);
  free(map);
}

Role* RoleHash_Get(const RoleHash *map, const char *key){
	unsigned int index;
  Bucket *bucket;
  Pair *pair;
  index = hash(key) % map->count;
  bucket = &(map->buckets[index]);
  pair = get_pair(bucket, key);
  if (pair == NULL) {
    return NULL;
  }
  return pair->value;
}
Role* RoleHash_GetOrPut(const RoleHash *map, const char *key){
  unsigned int index, key_len;
  Bucket *bucket;
  Pair *pair;


  index = hash(key) % map->count;
  bucket = &(map->buckets[index]);
  pair = get_pair(bucket, key);
  if (pair == NULL) {
		/* Create a key-value pair */
		if (bucket->count == 0) {
			/* The bucket is empty, lazily allocate space for a single
			 * key-value pair.
			 */
			bucket->pairs = malloc(sizeof(Pair));
			if (bucket->pairs == NULL) {
				return;
			}
			bucket->count = 1;
		}
		else {
			/* The bucket wasn't empty but no pair existed that matches the provided
			 * key, so create a new key-value pair.
			 */
			bucket->pairs = realloc(bucket->pairs, (bucket->count + 1) * sizeof(Pair));
			bucket->count++;
		}
		pair = &(bucket->pairs[bucket->count - 1]);
		strcpy(pair->key, key);
		pair->value = Role_New();
  }
  return pair->value;
}

void RoleHash_Put(const RoleHash *map, const char *key, const Role* value){
	unsigned int key_len, index;
	Bucket *bucket;
	Pair *pair;

	index = hash(key) % map->count;
  bucket = &(map->buckets[index]);

	if ((pair = get_pair(bucket, key)) != NULL) {
		pair->value = (Role*)value;
    return;
	}

	/* Create a key-value pair */
  if (bucket->count == 0) {
    /* The bucket is empty, lazily allocate space for a single
     * key-value pair.
     */
    bucket->pairs = malloc(sizeof(Pair));
    if (bucket->pairs == NULL) {
      return;
    }
    bucket->count = 1;
  }
  else {
    /* The bucket wasn't empty but no pair existed that matches the provided
     * key, so create a new key-value pair.
     */
    bucket->pairs = realloc(bucket->pairs, (bucket->count + 1) * sizeof(Pair));
    bucket->count++;
  }

	pair = &(bucket->pairs[bucket->count - 1]);
  strcpy(pair->key, key);
  pair->value = (Role*)value;
}
void RoleHash_Print(const RoleHash *map){
	unsigned int i, j, n, m;
  Bucket *bucket;
  Pair *pair;

  bucket = map->buckets;
  n = map->count;
  i = 0;
  while (i < n) {
    pair = bucket->pairs;
    m = bucket->count;
    j = 0;
    while (j < m) {
			printf("%s\n", pair->key);
			pair++;
      j++;
    }
    bucket++;
    i++;
  }
}
/*
 * Returns a pair from the bucket that matches the provided key,
 * or null if no such pair exist.
 */
static Pair * get_pair(Bucket *bucket, const char *key)
{
  unsigned int i, n;
  Pair *pair;

  n = bucket->count;
  if (n == 0) {
    return NULL;
  }
  pair = bucket->pairs;
  i = 0;
  while (i < n) {
    if (pair->key != NULL) {
      if (strcmp(pair->key, key) == 0) {
        return pair;
      }
    }
    pair++;
    i++;
  }
  return NULL;
}
/*
 * Returns a hash code for the provided string.
 */
static unsigned long hash(const char *str)
{
  unsigned long hash = 5381;
  int c;

  while (c = *str++) {
    hash = ((hash << 5) + hash) + c;
  }
  return hash;
}


