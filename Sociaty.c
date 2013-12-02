#include "Sociaty.h"


extern Sociaty ns;
extern char *eve;
extern char *const_name;
extern int const_count;



void Sociaty_Create(){
	RoleArray_Create(&ns.Members);
	RoleArray_AddNew(&ns.Members, eve);
	Hash_Create(&ns.UsedFiles);
}

void Sociaty_AddUsedFile(char *f){
	Hash_Add(&ns.UsedFiles, f);
}
Index Sociaty_SearchUsedFile(char *f){
  return Hash_Search(&ns.UsedFiles, f);
}


Index Sociaty_AddRole(Role *r){
	return RoleArray_Add(&ns.Members, r);
}
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
   n = Sociaty_GetRole(i)->_Name; 
   m = (char *)malloc(strlen(n) + strlen(str) + 3); 
		 i = atoi(str); 
   sprintf(m, "%s[%d]", n, i); 
   ci = Sociaty_AddNewRole(m); 
   Sociaty_AddSERelation(pi, ci);
   return ci; 
 } 

void Sociaty_RoleAssignArray(Index pi, StringIntArray *a){ 
 	int i,li; 
	Role *r; 
	char tmpname[255]; 
//	printf("assign com1\n");
	r = Sociaty_GetRole(pi); 
	r->Elements.Length = a->Length;
	r->Elements.Values = (Index *)realloc(r->Elements.Values,
																			 a->Length * sizeof(Index));
//	printf("assign com2\n");
	for(i=0; i<r->Elements.Length; i++){
		sprintf(tmpname, "%s[%d]", r->_Name, i); 
		li = Sociaty_AddNewRole(tmpname);
		if(a->IntValues[i] != -1){
			Sociaty_GetRole(li)->_TargetIndex = a->IntValues[i];
		}
		else{
			Sociaty_GetRole(li)->_Value = estrdup(a->StrValues[i]);
		}
		r->Elements.Values[i] = li;
	}
//	printf("assign com3\n");
} 


/*
Index Sociaty_AddNewExpression(char *str){ 
 	Expression e; 
 	//Expression_CreateByString(&e, str); 
	//  return ExpressionArray_Add(&ns.Actions, &e); 
} 
*/


Role *Sociaty_GetRole(Index i){ 
 	return ns.Members.Values + i; 
}
 
char* Sociaty_GetValue(Index i){ 
 	int ci = i; 
 	char *s; 
	//	while (Sociaty_GetRole(i)->Parents 
	return s; 
} 


int Sociaty_SearchPCRelation(Index pi, Index ci){ 
	//	printf("search %d,%d\n",pi,ci); 
 	Role *parent, *child; 
 	int rtn; 
 	rtn = 0; 
 	rtn = Sociaty_SearchPRelation(pi, ci, rtn); 
	//	printf("prtn %d\n", rtn); 
 	if(rtn) return rtn; 
 	rtn = 0; 
 	rtn = Sociaty_SearchCRelation(pi, ci, rtn); 
	//	printf("crtn %d\n", rtn); 
 	return rtn;	 
} 
int Sociaty_SearchPRelation(Index pi, Index ci, int rtn){ 
 	Role *child; 
	Index i, subi; 
 	int subrtn; 
 	rtn ++; 
	child = ns.Members.Values + ci; 
	for(i=0; i<child->Parents.Length; i++){ 
 		subi = child->Parents.Values[i]; 
		if(pi == subi) 
 			return rtn; 
		subrtn = Sociaty_SearchPRelation(pi, subi, rtn); 
 		if(subrtn){ 
 			return subrtn; 
 		}
	} 
 	return 0; 
}

int Sociaty_SearchCRelation(Index pi, Index ci, int rtn){
	Role *child;
  Index i, subi;
	int subrtn;
	rtn --;
  child = ns.Members.Values + ci;
  for(i=0; i<child->Children.Length; i++){
		subi = child->Children.Values[i];
    if(pi == subi)
			return rtn;
    subrtn = Sociaty_SearchCRelation(pi, subi, rtn);
		if(subrtn){
			return subrtn;
		}
  }
	return 0;
}
void Sociaty_ClearArgs(Index pi){
	Role *r, *argr, *tmpr;
	int i;
	r= Sociaty_GetRole(pi);
	for(i=0; i<r->Subordinates.Length; i++){
		argr = Sociaty_GetRole(r->Subordinates.Values[i]);
		if(!strcmp(estrafter(argr->_Name, '.'),"_Args"))
			break;
	}
	for(i=0; i<argr->Elements.Length; i++){
		tmpr = Sociaty_GetRole(argr->Elements.Values[i]);
		strcmp(tmpr->_Value, "");
		tmpr->_TargetIndex = -1;
	}
	argr->Elements.Length = 0;
}

void Sociaty_AddPCRelation(Index pi, Index ci){
	IndexArray_Add(&Sociaty_GetRole(pi)->Children, ci);
	IndexArray_Add(&Sociaty_GetRole(ci)->Parents, pi);
}
void Sociaty_AddSERelation(Index pi, Index ci){
  IndexArray_Add(&Sociaty_GetRole(pi)->Elements, ci);
}
 
void Sociaty_AddSSRelation(Index pi, Index ci){
	IndexArray_Add(&Sociaty_GetRole(pi)->Subordinates, ci);
	IndexArray_Add(&Sociaty_GetRole(ci)->Superiors, pi);
}

void Sociaty_WriteIndexArray(IndexArray *a){
	Index i;
	printf("%d", a->Length);
	for(i=0; i<a->Length; i++){
		printf("\t%s", (ns.Members.Values + a->Values[i])->_Name);
	}
	printf("\n");
}
void Sociaty_WriteMembers(){
	Index i;
	Role *v;
	for(i=0;i<ns.Members.Length;i++){
		v = ns.Members.Values + i;
		printf("Index:    %d\n", i);
		printf("Name:     %s\n", v->_Name);
		printf("Value:    %s\n", v->_Value);
		printf("Target:   %d\n", v->_TargetIndex);
		printf("Subordinates: ");
		Sociaty_WriteIndexArray(&v->Subordinates);
		printf("Superiors: ");
		Sociaty_WriteIndexArray(&v->Superiors);
		printf("Parents: ");
		Sociaty_WriteIndexArray(&v->Parents);
		printf("Children: ");
		Sociaty_WriteIndexArray(&v->Children);
	printf("=====================\n");
	}

}
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
		Sociaty_AddPCRelation(0, i);
	}
	return i;
}
Index Sociaty_AddChildRole(Index pi, char *name){
	Index i = RoleArray_AddNew(&ns.Members, name);
	Sociaty_AddPCRelation(pi, i);
  return i;
}
Index Sociaty_AddConstRole(char *str){
	char *nstr;
	int ri;
	nstr = (char *)malloc(12);
	const_count++;
	sprintf(nstr, "CONST_%d",const_count);
	ri = Sociaty_AddNewRole(nstr); 
	Sociaty_GetRole(ri)->_Value = estrdup(str);
	free(nstr);
	return ri;
}



void Sociaty_PutChar(char c){
	fprintf(ns.Out, "%c", c);
}
void Sociaty_PutString(char *s){
  fprintf(ns.Out, "%s", s);
}

void Sociaty_SetOut(char *str, char *op){
	char tmpfile[MAX_FILE_NAME];
	char step[8];
	if(ns.Out != stdout && ns.Out != NULL){
//		fprintf(stderr,"fclose");
		fclose(ns.Out);
	}
	if(estrisnull(str) || !strcmp(str,"stdout")){
		ns.Out = stdout;
		return;
	}
	if(!strcmp(str,"stderr")){
		ns.Out = stderr;
		return;
	}
	if(!strncmp(str,"$-P", 3)){
		strcpy(tmpfile, ns.ProgramFile);
		sprintf(step, ".%d", ns.Step);
		strcat(tmpfile, step);
		strcat(tmpfile, str+3);
		if(!strcmp(tmpfile, ns.OutFile)){
			ns.Step ++;
			strcpy(ns.OutFile, tmpfile);
			ns.Out = fopen(tmpfile, op);
		}
		return;
	}
	
	if(!strcmp(str, ns.OutFile)){
    strcpy(ns.OutFile, str);
    ns.Out = fopen(str, op);
		return;
	}


}


/*
void Sociaty_EvalExpression(Expression *expr){
	switch (expr->Operation){
	case Value:
		Sociaty_Output(Sociaty_GetRole(expr->Role1)->_Value);
		return;
	case Set:
		Sociaty_GetRole(expr->Role1)->_Value = 
			estrdup(Sociaty_GetRole(expr->Role2)->_Value);
		return;
	case Gen:
		Sociaty_AddPCRelation(expr->Role1, 
													expr->Role2);
		return;		
  case Hire:
    Sociaty_AddSSRelation(expr->Role1, 
													expr->Role2);
    return;
	case Include:
		//Include
	case Eval:
		//Evaluate
		return;
	default:
		eerror("Expression_Eval: unknown operation");
	}
}
*/

/*
main(){
	Sociaty_Create();
	printf("Sociaty Created\n");
	Sociaty_AddSSRelation("a","b");
	Sociaty_AddPCRelation("c","b");
	Sociaty_AddPCRelation("a","c");

	Sociaty_SearchPCRelation(2,1);
	Sociaty_Write();
}
*/
