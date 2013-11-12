#include "Eval.h"
extern char path[];
void Eval(Index i, Index pi){
//	printf();
	Role *r;
	Role *pr;
	r = Sociaty_GetRole(i); 
	if(r->_Value != NULL){
		Sociaty_Output(r->_Value);
		return;
	}
	pr = Sociaty_GetRole(pi);
//warning r will lost if add new role 
// because of realloc
	printf("Eval %d\t%d\n", i, pi);
}

char* GetPath(char *id){
	char *token;

	token = strtok(path ,":");
	char *fname;
	FILE *tfp;
	fname = (char*)malloc(MAX_FILE_NAME);
	while ( token = strtok(NULL, ":") ){
		strcpy(fname, token);
		strcat(fname, id);
		//	printf("%s\n", fname);
		tfp = fopen(fname, "r");
		if(tfp != NULL){
			fclose(tfp);
			return fname;
		}

		strcpy(fname, token);
		strcat(fname, id);
		strcat(fname, ".e");	
    tfp = fopen(fname, "r");
    if(tfp != NULL){
      fclose(tfp);
      return fname;
    }
	}	
	return NULL;
}
