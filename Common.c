#include "Common.h"

void estrdup(char* ori, char *str){
	if(ori == NULL){
		ori = (char*)malloc(strlen(str)+1);
	}
	else{
		ori = (char*)realloc(ori, strlen(str)+1);
	}
	strcpy(ori, str);
}

void eerror(char *str){
	fprintf(stderr, "%s\n", str);
}
/*
char* ereadfile(File *fp){
	return 
}
*/

void IndexArray_Create(IndexArray *a){
  a->Length = 0;
  a->Values = (Index *)malloc(sizeof(Index));
}

Index IndexArray_Add(IndexArray *a, Index i){
  int p = a->Length++;
  a->Values = (Index *)realloc(a->Values,
                      a->Length * sizeof(Index));
	a->Values[p] = i;
  return p;
}



