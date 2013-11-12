#include "Common.h"




char* estrdup(char *str){
	char *exp;
	if(str != NULL){
		exp = (char*)malloc(strlen(str)+1);		
		strcpy(exp, str);
	}
	return exp;
}

void eerror(char *str){
	fprintf(stderr, "%s\n", str);
}

char* ereadfile(FILE *fp){
	long lsize;
	char *str;
	size_t result;
	fseek(fp, 0L, SEEK_END);
	lsize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	str = (char *)malloc(lsize);
	result = fread (str,1,lsize,fp);
	if( result != lsize ){
		eerror("ereadfile failed");
		exit(1);
	}
	return str;
}


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



