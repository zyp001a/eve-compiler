#include "Sociaty.h"



extern Sociaty ns;
extern char *eve;
extern char *const_name;
extern int const_count;


void Sociaty_Create(){
	ns.Root = Role_New();
	RoleHash_Put(ns.Root->Subs, eve, ns.Root);
	ns.Root->Key = &eve[0];
	ns.Root->_Name = estrdup(eve);
	ns.Root->Depth = 0;
	
	ns.Curr = ns.Root;
//	RoleArray_AddNew(&ns.Members, eve);
	Hash_Create(&ns.UsedFiles);
}

void Sociaty_AddUsedFile(char *f){
	Hash_Add(&ns.UsedFiles, f);
}
Index Sociaty_SearchUsedFile(char *f){
  return Hash_Search(&ns.UsedFiles, f);
}
//add suboridnate
Role* Sociaty_RoleEmploy(Role *r, char *key){
	char name[255];
	Role *t = RoleHash_GetOrPut(r->Subs, key);
	if(r != ns.Root){
		sprintf(name, "%s.%s", r->_Name, key);
		t->_Name = estrdup(name);

	}
	else{
		t->_Name = estrdup(key);
	}
	if(t->Depth == -1) t->Depth = r->Depth +1;
	if(t->Key == NULL) t->Key = key;
	if(t->Sup != NULL && t->Sup != r) error("more than one sup"); 
	t->Sup = r;
//	Role_Print(t);
	return t;
}
//add element
Role* Sociaty_RoleExpend(Role *r, Index ind){
	Role *t;
	char name[255];
	Index i;
	if(ind >= r->_Elements->Length){
		r->_Elements->Length = ind + 1;
		if(r->_Elements->Size == 0)
			r->_Elements->Values =
				(Role**)malloc(r->_Elements->Size*sizeof(Role*));
		else if(r->_Elements->Length > r->_Elements->Size){
				r->_Elements->Size = r->_Elements->Length;
				r->_Elements->Values =
					(Role**)realloc(r->_Elements->Values, 
													r->_Elements->Size*sizeof(Role*));
		}
		
		for(i=0; i<r->_Elements->Length; i++){
			sprintf(name,"%s[%d]",r->_Name,i);			
			if(r->_Elements->Values[i] == NULL){
				t = Role_New();
				r->_Elements->Values[i] = t;
				t->_Name=estrdup(name);
				t->Key = r->Key;
				t->Sup = r->Sup;
				t->Index = i;			
			}
			
		}
	}
	return r->_Elements->Values[ind];
}
void Sociaty_RoleSetElements(Role *r, RoleArray *a){
	int i;
	Role *t;
	char name[255];
	if(r->_Elements->Size == 0){
		r->_Elements = a;
		for(i=0; i<a->Length; i++){
			t = r->_Elements->Values[i];
			t->Key = r->Key;
			t->Sup = r->Sup;
			t->Index = i;			
			sprintf(name,"%s[%d]",r->_Name,i);
			t->_Name = estrdup(name);			
		}

	}
	else {
		if(r->_Elements->Size < a->Length){
			r->_Elements->Size = a->Length;
			r->_Elements->Values = 
				(Role**)realloc(r->_Elements->Values,
												r->_Elements->Size*sizeof(Role*));

		}
		for(i=0; i<a->Length; i++){
			t = r->_Elements->Values[i];
			r->_Value = a->Values[i]->_Value;
			printf("%s\n", a->Values[i]->_Value);
			if(t->Key == NULL) t->Key = r->Key;
			if(t->Sup == NULL) t->Sup = r->Sup;
			if(t->Index == -1) t->Index = i;			
			if(t->_Name == NULL){
				sprintf(name,"%s[%d]",r->_Name,i);
				t->_Name = estrdup(name);			
			}
			free(a->Values[i]);
		}
		free(a->Values);
	}
	r->_Elements->Length = a->Length;


}

void Sociaty_PutString(char *s){
  fprintf(ns.Out, "%s", s);
}
void Sociaty_SetIn(char *str, char *op){
  char tmpfile[MAX_FILE_NAME];
  char step[8];
	if(ns.In != stdin && ns.In != NULL){
		fclose(ns.In);
	}
	if(estrisnull(str) || !strcmp(str,"stdout")){
    ns.In = stdin;
    return;
  }
	if(strcmp(str, ns.InFile)){
    strcpy(ns.InFile, str);
    ns.In = fopen(str, op);
    return;
  }

};
void Sociaty_SetOut(char *str, char *op){
	char tmpfile[MAX_FILE_NAME];
	char step[8];	
//	printf("1fopen%s\n", str);
	if(ns.Out != stdout && ns.Out != NULL){
//		fprintf(stderr,"fclose");
		fclose(ns.Out);
	}
//	printf("2fopen%s\n", str);
	if(estrisnull(str) || !strcmp(str,"stdout")){
		ns.Out = stdout;
		return;
	}
//	printf("3fopen%s\n", str);
	if(!strcmp(str,"stderr")){
		ns.Out = stderr;
		return;
	}
//	printf("4fopen%s\n", str);
	if(strcmp(str, ns.OutFile)){
    strcpy(ns.OutFile, str);
    ns.Out = fopen(str, op);
		return;
	}
//	printf("5fopen%s\n", str);

}


void Sociaty_WriteMembers(){
	return;
}

//Role* Sociaty_Ro


/*
Index Sociaty_RoleAddSubordinate(Index pi, char *str){
	int ci;
  char *m;
  char *n;
//	printf("xxx%d\n",pi);
  n = Sociaty_GetRole(pi)->_Name;
  m = (char *)malloc(strlen(n) + strlen(str) + 2);
  sprintf(m, "%s.%s", n, str);
  ci = Sociaty_AddNewRole(m);
	if(Sociaty_SearchIndexArray(&Sociaty_GetRole(pi)->Subordinates, ci) == -1) 
 		Sociaty_AddSSRelation(pi, ci); 
	return ci; 
} 
Index Sociaty_RoleAddElement(Index pi, char *str){ 
	int ci, i; 
  char *m; 
	char *n; 
	n = Sociaty_GetRole(pi)->_Name; 
	m = (char *)malloc(strlen(n) + strlen(str) + 3); 
	i = atoi(str); 
	sprintf(m, "%s[%d]", n, i); 
	ci = Sociaty_AddNewRole(m);
	if(Sociaty_SearchIndexArray(&Sociaty_GetRole(pi)->_Elements, ci) == -1)
		Sociaty_AddSERelation(pi, ci);
	return ci; 
} 
*/

/*


Index Sociaty_SearchRole(char *name){
	return RoleArray_SearchByName(&ns.Members, name);
}
Index Sociaty_SearchIndexArray(IndexArray *a, Index ci){
	Index i;
  Role *v;
  for(i=0;i<a->Length;i++)
    if(ci == a->Values[i]) return i;
  return -1;
}



Index Sociaty_AddNewRole(char *name){
	Index i;
	i = Sociaty_SearchRole(name);
	if(i == -1){
		i = RoleArray_AddNew(&ns.Members, name);
	}
	return i;
}



void Sociaty_PutChar(char c){
	fprintf(ns.Out, "%c", c);
}
*/
