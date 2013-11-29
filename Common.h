
#ifndef _COMMON
#define _COMMON
//#define EDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_FILE_NAME 1024
#define MAX_BLOCK_SIZE 1024*128


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
char* estrndup(char *str, int len);
char* estrsub(char *big, char *small);
char* estrcent(char *);
void estradd(char**, char *);
char* estrlower(char *);
char* estrupper(char *);
char* estrafter(char *, char);
char* estrbeforedup(char *, char);
void* estraddeol(char **);

char eisletter(char c);
char eisdigit(char c);
char eiss(char c);

void eerror(char *str);
void ewarn(char *str);
void IndexArray_Create(IndexArray *a);
Index IndexArray_Add(IndexArray *a, Index i);
void IndexArray_PassBySymbol(IndexArray*, IndexArray*);
void IndexArray_PassByValue(IndexArray*, IndexArray*);
void IndexArray_Dispose(IndexArray*);
void IndexArray_DisposeSub(IndexArray*);
char* ereadfile(FILE *fp);

#endif
