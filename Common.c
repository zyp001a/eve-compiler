#include "Common.h"


char estrisnull(char *str){
	if(str == NULL || str[0] == '\0')
		return 1;
	return 0;
}

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
char* estrndup(char *str, int len){
	char *exp;
	exp = (char*)malloc(len+1);
	strncpy(exp, str, len);
	exp[len]= '\0';
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
char *estrlower(char *str){
	char *rtn;
	rtn = (char* )malloc(strlen(str)+1);
	int i = 0;
	while(str[0]){
		rtn[i++]=tolower(str[0]);
		str++;
	}
	rtn[i] = '\0';
	return rtn;
}

void estrcat(char **a, char *b){
	if(b==NULL) return;
	int lena;
	if(*a==NULL){
		*a=estrdup(b);
	}
	else{
		*a=(char*)realloc(*a, (strlen(*a) + strlen(b) + 1));
		strcat(*a,b);
	}
}
char *estrupper(char *str){
	char *rtn;
	rtn = (char* )malloc(strlen(str)+1);
	int i = 0;
	while(str[0]){
		rtn[i++]=toupper(str[0]);
		str++;
	}
	rtn[i] = '\0';
	return rtn;
}
char* estrafter(char *str, char c){
	if(str == NULL) return "";
	char *rtn = str;
	while(str++){
//		printf("%c\t%c\n", str[0], c);
		if(str[0] == c){
			rtn = str + 1;
		}
		else if(str[0] == '\0'){
			break;
		}
	}
	return rtn;
}

char* estrbeforedup(char *str, char c){
	if(str == NULL) return "";
	char *stri = &str[0];
	int i = 0;
	int ri = -1;
	char *rtn;
	while(1){
//		printf("%c\n", stri[0]);
		if(stri[0] == c){
			ri = i;
		}
		else if(stri[0] == '\0'){
			break;
		}
		i ++;
		stri++;
	}
	if(ri != -1){
		rtn = (char *)malloc(ri+1);
		strncpy(rtn, str, ri);
		rtn[ri] = '\0';
	}
	else{
		rtn =estrdup("");
	}
	return rtn;
}

void* estraddeol(char **str){
	int slen = strlen(*str);
	*str=(char *)realloc(*str, slen+2);
	(*str)[slen] = '\n';
	(*str)[slen+1] = '\0';
}
int estrstat(char *str, char c){
	int i = 0;
	char *stri;
	stri = &str[0];
	while(stri[0] != '\0'){
//		printf("%c\n",str[0]);
		if(stri[0] == c)
			i ++;
		stri++;
	}
	return i;
}

char eisletter(char c){
	if(c >= 'a' && c <= 'z') return 1;
	if(c >= 'A' && c <= 'Z') return 1;
	if(c == '_') return 1;
	return 0;
}
char eisdigit(char c){
	if(c >= '0' && c <= '9') return 1;
	return 0;
}
char eiss(char c){
	if(c >= 'a' && c <= 'z') return 1;
  if(c >= 'A' && c <= 'Z') return 1;
  if(c == '_') return 1;
	if(c >= '0' && c <= '9') return 1;
	return 0;
}



void eerror(char *str){
	fprintf(stderr, "Error: %s\n", str);
}
void ewarn(char *str){
	fprintf(stderr, "Warning: %s\n", str);
}

char* ereadfile(FILE *fp){
	long lsize;
	char *str;
	size_t result;
//	printf("ereadfile\n");
	if(fp == NULL) eerror("readfile error");
	fseek(fp, 0L, SEEK_END);
	lsize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	str = (char *)malloc(lsize+1);
	result = fread (str,1,lsize,fp);
	if( result != lsize ){
		eerror("ereadfile failed");
//		exit(1);
	}
	str[result] = '\0';

	return str;
}

IndexArray *IndexArray_New(){
	IndexArray *a;
	a=malloc(sizeof(IndexArray));
  a->Length = 0;
//  if(a->Values != NULL) free(a->Values);
  a->Values = (Index *)malloc(sizeof(Index));
}

void IndexArray_Create(IndexArray *a){
  a->Length = 0;
//	if(a->Values != NULL) free(a->Values);
	a->Values = (Index *)malloc(sizeof(Index));
}

Index IndexArray_Add(IndexArray *a, Index i){
  int p = a->Length++;
  a->Values = (Index *)realloc(a->Values,
                      a->Length * sizeof(Index));
	a->Values[p] = i;
  return p;
}
void IndexArray_PassBySymbol(IndexArray *a, IndexArray *b){
	if(a->Values != NULL)
		free(a->Values);
	*a = *b;
}

void IndexArray_PassByValue(IndexArray *a, IndexArray *b){
	a->Length = b->Length;
	if(a->Values != NULL){
		a->Values = (Index* )realloc(a->Values, a->Length*sizeof(Index));
	}
	else{
		a->Values = (Index* )malloc(a->Length*sizeof(Index));
	}
	int i;
	for(i=0; i<a->Length; i++){
		a->Values[i] = b->Values[i];
	}
}
void IndexArray_Dispose(IndexArray* a){
	free(a->Values);
	free(a);
}
void IndexArray_DisposeSub(IndexArray* a){
	free(a->Values);
}
StringArray *StringArray_New(){
	StringArray *a;
	a = malloc(sizeof(StringArray));
	a->Length = 0;
  a->Values = (char**)malloc(sizeof(char*));
}
void StringArray_Create(StringArray *a){
	int i;

//	if(a->Values != NULL) free(a->Values);
	a->Length = 0;
  a->Values = (char**)malloc(sizeof(char*));

}
Index StringArray_Add(StringArray *a, char *s){
	int p = a->Length++;
  a->Values = (char **)realloc(a->Values,
															 a->Length * sizeof(char *));
  a->Values[p] = estrdup(s);
  return p;
}
void StringArray_DisposeSub(StringArray *a){
	int i;
	for(i=0; i<a->Length; i++)
		if(a->Values[i] != NULL) free(a->Values[i]);
	if(a->Values!=NULL) free(a->Values);
	a->Length = 0;
	
}
void StringIntArray_Create(StringIntArray *a){
	int i;

//	if(a->Values != NULL) free(a->Values);
	a->Length = 0;
  a->StrValues = (char**)malloc(sizeof(char*));
	a->IntValues = (int*)malloc(sizeof(int));
}
Index StringIntArray_Add(StringIntArray *a, char *s, int i){
	int p = a->Length++;
  a->StrValues = (char **)realloc(a->StrValues,
															 a->Length * sizeof(char *));
  a->IntValues = (int *)realloc(a->IntValues,
															 a->Length * sizeof(int));
  a->StrValues[p] = estrdup(s);
	a->IntValues[p] = i;
  return p;
}
void StringIntArray_DisposeSub(StringIntArray *a){
	int i;
	for(i=0; i<a->Length; i++)
		if(a->StrValues[i] != NULL) free(a->StrValues[i]);
	if(a->StrValues!=NULL) free(a->StrValues);
	if(a->IntValues!=NULL) free(a->IntValues);
	a->Length = 0;
	
}

