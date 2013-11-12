#include "Common.h"




char* estrdup(char *str){
	char *exp;
	if(str != NULL){
		exp = (char*)malloc(strlen(str)+1);		
		strcpy(exp, str);
	}
	else{
		exp = (char*)malloc(1);
		strcpy(exp, "");
	}
	return exp;
}
char* estrsub(char *big, char *small){

	char *sub;
	sub = big;
	if(big && small){
		int si = strlen(small);
		while(si--){
			if(big[si] != small[si]){
				return sub;
			}
			sub ++;
		}
	}
	return sub;
}
char* estrcent(char *str){
	char *rtn;
	int l;
	if(str != NULL){
		l = strlen(str);
		if(l<2) return estrdup(str);
		str ++;
		rtn = (char*)malloc(l-1);
		rtn[l-2] = '\0';
		strncpy(rtn, str, l-2);
	}
	else{
		return estrdup(str);
	}
	return rtn;
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



