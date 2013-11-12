#ifndef _COMMON
#define _COMMON
//#define EDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _Bool boolean




typedef int Index;

typedef struct IndexArray{
	Index Length;
	Index *Values;
} IndexArray;

typedef struct IntTuple2{
	int Int1;
	int Int2;
} IntTuple2;

char* estrdup(char *str);

void eerror(char *str);
void IndexArray_Create(IndexArray *a);
Index IndexArray_Add(IndexArray *a, Index i);
char* ereadfile(FILE *fp);

#endif
