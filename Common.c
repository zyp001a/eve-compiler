#include "Common.h"


char estrisnull(char *str){
	if(str == NULL || str[0] == '\0')
		return '1';
	return '\0';
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
char *estrafter(char *str, char c){
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
	fseek(fp, 0L, SEEK_END);
	lsize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	str = (char *)malloc(lsize+1);
	result = fread (str,1,lsize,fp);
	if( result != lsize ){
		eerror("ereadfile failed");
		exit(1);
	}
	str[result] = '\n';
	str[result +1] = '\0';
	
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



