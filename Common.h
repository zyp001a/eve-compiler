
#ifndef _COMMON
#define _COMMON
//#define EDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_FILE_NAME 1024



typedef int Index;

typedef struct IndexArray{
	Index Length;
	Index *Values;
} IndexArray;

typedef struct IntTuple2{
	int Int1;
	int Int2;
} IntTuple2;
char estrisnull(char *str);
char* estrdup(char *str);
char* estrsub(char *big, char *small);
char* estrcent(char *);
char* estrlower(char *);
char* estrupper(char *);
char* estrafter(char *, char);

char eisletter(char c);
char eisdigit(char c);
char eiss(char c);

void eerror(char *str);
void ewarn(char *str);
void IndexArray_Create(IndexArray *a);
Index IndexArray_Add(IndexArray *a, Index i);
void IndexArray_PassbySymbol(IndexArray*, IndexArray*);
char* ereadfile(FILE *fp);

#endif
