#include "Eval.h"
extern char path[];
extern Sociaty ns;
extern char* evalstr;
extern char *namestr;
extern char *valuestr;

char* Eval(Index i){
//	printf();
	Role *r;
	char *title, *value, *eval;
	char *result;
	r = Sociaty_GetRole(i);

	title = GetTitleName(r);
	if(!strcmp(title, evalstr)){
//		printf("%s\t%s\n",title,evalstr);
		eerror("Eval is not allowed to use");
		exit(1);
	}
	eval = GetEvalValue(r);
	InterpretValue(r, eval, &result);
//	fprintf(out, "%c\n", );	
/*	
	if(r->_Value != NULL){

		switch(r->_Lang){
		case awk:
			return;
		case bash:
			return;
		case c:
			return;
		case m4:
			return;
		case matlab:
			return;
		case perl:
			return;
		case python:
			return;
		case r:
			return;
		default:
			Sociaty_Output(r->_Value);
			return;
		}

		return;
	}
	pr = Sociaty_GetRole(pi);
*/
//warning r will lost if add new role 
// because of realloc
//	printf("Eval %d\t%d\n", i, pi);
}
/*
Lang GetLang(char *str){
	char *lstr = estrlower(str);
	if(!strcmp(lstr,"awk"))
		return awk;
	else if(!strcmp(lstr,"bash"))
    return bash;
	else if(!strcmp(lstr,"c"))
    return c;
  else if(!strcmp(lstr,"m4"))
    return m4;
  else if(!strcmp(lstr,"matlab"))
    return matlab;
  else if(!strcmp(lstr,"perl"))
    return perl;
  else if(!strcmp(lstr,"python"))
    return python;
  else if(!strcmp(lstr,"r"))
    return r;
  else 
		return stdout;
	free(lstr);
}
*/
char GetFlag(char *str){
	return 0;
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
char* GetTitleName(Role *r){
	return estrafter(r->_Name, '.');
}
char* GetTitleValue(Role *r, char *title){
	int i,j;
	Role *pr,* psr;
	char *rpr;
	for(i=0; i<r->Parents.Length; i++){
		pr = Sociaty_GetRole(r->Parents.Values[i]);
		for(j=0; j<pr->Subordinates.Length; j++){
			psr = Sociaty_GetRole(pr->Subordinates.Values[j]);
			if(strcmp(title, GetTitleName(psr)) 
				 && !estrisnull(psr->_Value)){
				return psr->_Value;
			}
		}
		rpr = GetTitleValue(pr, title);
		if(!estrisnull(rpr)){
			return rpr;
		}
	}
	return "";
}
char* GetEvalValue(Role *r){
	return GetTitleValue(r, evalstr);
}
void InterpretValue(Role *r, char *value, char **result){
}


