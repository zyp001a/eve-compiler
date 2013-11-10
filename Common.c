#include "Common.h"

char* estrdup(char *str){
	char *buffer;
	buffer = (char*)malloc(strlen(str)+1);
	strcpy(buffer, str);
	return buffer;
}


typedef int Index;

struct IndexArray{
	Index Length;
	Index *Values;
};

typedef struct IndexArray IndexArray;
void IndexArray_Create(IndexArray *a){
  a->Length = 0;
  a->Values = malloc(sizeof(Index));
}

Index IndexArray_Add(IndexArray *a, Index i){
  int p = a->Length++;
  a->Values = realloc(a->Values,
                      a->Length * sizeof(Index));
	a->Values[p] = i;
  return p;
}



