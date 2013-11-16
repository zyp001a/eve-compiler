#include "Hash.h"

void Hash_Create(Hash* h){
	h->Length=0;
	h->DataTable = (char **)malloc(sizeof(char*));
}

Index Hash_Add(Hash* h, char *str){
	int p = h->Length++;
	h->DataTable = (char **)realloc(h->DataTable, h->Length * sizeof(char*));
	h->DataTable[p] = estrdup(str);
	return p;
}

Index Hash_Search(Hash* h, char *str){
	Index i;
	for(i=0; i<h->Length; i++){
		if(!strcmp(h->DataTable[i], str)){			
			return i;
		}
	}
	return -1;
} 
