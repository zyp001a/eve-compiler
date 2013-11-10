#ifndef _COMMON
#define _COMMON

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _Bool boolean

typedef int Index;

struct IndexArray{
	Index Length;
	Index *Values;
};

typedef struct IndexArray IndexArray;

void estrdup(char* ori, char *str);

void eerror(char *str);
void IndexArray_Create(IndexArray *a);
Index IndexArray_Add(IndexArray *a, Index i);

#endif
