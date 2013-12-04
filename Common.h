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
typedef struct StringArray{
	Index Length;
	char **Values;
} StringArray;
typedef struct StringInt{
	char *Str;
	int Int;
} StringInt;
typedef struct StringIntArray{
	Index Length;
	int *IntValues;
	char **StrValues;
} StringIntArray;
typedef struct Int2{
	int Int1;
	int Int2;
} Int2;

char estrisnull(char *str);
char* estrdup(char *str);
char* estrndup(char *str, int len);
char* estrsub(char *big, char *small);
char* estrcent(char *);
void estrcat(char**, char *);
char* estrlower(char *);
char* estrupper(char *);
char* estrafter(char *, char);
char* estrbeforedup(char *, char);
void* estraddeol(char **);
int estrstat(char *, char);

char eisletter(char c);
char eisdigit(char c);
char eiss(char c);

void eerror(char *str);
void ewarn(char *str);

char* ereadfile(FILE *fp);

void IndexArray_Create(IndexArray *a);
Index IndexArray_Add(IndexArray *a, Index i);
void IndexArray_PassBySymbol(IndexArray*, IndexArray*);
void IndexArray_PassByValue(IndexArray*, IndexArray*);
void IndexArray_Dispose(IndexArray*);
void IndexArray_DisposeSub(IndexArray*);
void StringArray_Create(StringArray *);
Index StringArray_Add(StringArray *a, char *);
void StringArray_DisposeSub(StringArray*);
void StringIntArray_Create(StringIntArray *);
Index StringIntArray_Add(StringIntArray *a, char *s, int i);
void StringIntArray_DisposeSub(StringIntArray*);


#endif
