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

char* estrdup(char *str);

void eerror(char *str);
void IndexArray_Create(IndexArray *a);
Index IndexArray_Add(IndexArray *a, Index i);
char* ereadfile(FILE *fp);

#endif
