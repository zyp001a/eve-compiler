#include "Eval.h"
extern char path[];
extern Sociaty ns;
extern char* evalstr;
extern char* argsstr;
extern char *namestr;
extern char *valuestr;


//#define EDEBUGPRO
char* Eval(Index i){
//	printf();
	Role *r;
	char *title, *value, *eval, *args;
	char result_buf[100000];
  char *result = &result_buf[0];
	r = Sociaty_GetRole(i);

	title = GetTitleName(r);
/*
	if(!strcmp(title, evalstr)){
//		printf("%s\t%s\n",title,evalstr);
		eerror("Eval is not allowed to use");
		exit(1);
	}
*/
#ifdef EDEBUGPRO
	printf("Eval: %s\n", r->_Name);
  printf("\tEval Get Title: %s\n", title);
#endif
//if not null and has superiors
	if(estrisnull(r->_Value) && strcmp(r->_Name, title)){		
#ifdef EDEBUGPRO
    printf("\tEval Try to Get NewValue: %s\n");
#endif
		r->_Value = GetValueFromSuperiors(r, title, strlen(title));
#ifdef EDEBUGPRO
		printf("\tEval Set NewValue: %s\n", r->_Value);
#endif
	}

/*
	args = GetValue(r, argsstr, strlen(argsstr));	
#ifdef EDEBUGPRO
	printf("ArgsContent %s\n", args);
#endif
	InterpretValue(r, args, &result);
*/
	eval = GetValue(r, evalstr, strlen(evalstr)); 
#ifdef EDEBUGPRO
	printf("\tEval GetEvalContent: \n========\n%s\n========\n", eval);
#endif
	InterpretValue(r, eval, &result);
	result[0] = '\n';
	result[1] = '\0';
	result =  &result_buf[0];
//	printf("%s\n", result);
	return result;
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
	char tpath[MAX_FILE_NAME];
	char *fname;
	FILE *tfp;
	strcpy(tpath, path);
	token = strtok(tpath ,":");

	fname = (char *)malloc(MAX_FILE_NAME);

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
		strcat(fname, ".ec");	
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
char* GetValueFromSuperiors(Role *r, char *title, int len){
	Role *sr;
	char *rpr;
	int i;

	for(i=r->Superiors.Length; i>0; --i){
		sr = Sociaty_GetRole(r->Superiors.Values[i-1]);
#ifdef EDEBUGPRO
		printf("\tFrom Superior %d, %s\n", i-1, sr->_Name);
#endif		

    rpr = GetValue(sr, title, len);

    if(!estrisnull(rpr)){
			
			return rpr;
		}
	}
	return "";
}
char* GetValueFromParents(Role *r, char *title, int len){
	Role *sr;
	char *rpr;
	int i;

	for(i=r->Parents.Length; i>0; --i){
		sr = Sociaty_GetRole(r->Parents.Values[i-1]);
#ifdef EDEBUGPRO
		printf("\tFrom Superior %d, %s\n", i-1, sr->_Name);
#endif		

    rpr = GetValue(sr, title, len);

    if(!estrisnull(rpr)){
			
			return rpr;
		}
	}
	return "";
}
char* GetValue(Role *r, char *title, int len){
	int i,j;
	Role *pr,* psr;
	char *rpr;
	char *ttitle;
	//_Value, _Name, _Super exception
#ifdef EDEBUGPRO
	printf("\t\tTry to Get Value: %s, %s\n", r->_Name, title);
#endif
	if(!strncmp(title, valuestr, strlen(valuestr))){
		return r->_Value;
	}
	if(!strncmp(title, namestr, strlen(namestr))){
		return r->_Name;
	}

/*
	if(!strncmp(title, superstr, strlen(superstr))){
		ttitle = GetTitleName(r);
		return GetValueFromSuperiors(r, ttitle, strlen(ttitle));
	}
*/

	rpr = GetValueRecursive(r, title, len);


#ifdef EDEBUGPRO
//      printf("GetValue From Self\n");
#endif
	if(!estrisnull(rpr)){
		return rpr;
	}
//	}
/*
	for(i=0; i<r->Parents.Length; i++){
		pr = Sociaty_GetRole(r->Parents.Values[i]);

#ifdef EDEBUGPRO
//		printf("GetValue Try From Parent %s, Total %d\n", pr->_Name, r->Parents.Length);
#endif
		rpr = GetValueRecursive(pr, title, len);
		if(!estrisnull(rpr)){
			return rpr;
		}
	}
*/
	return "";
}
char *GetValueRecursive(Role *pr, char *title, int len){
	Role *psr;
	char *ttitle;
	char *v;
	int j;
	for(j=0; j<pr->Subordinates.Length; j++){
		psr = Sociaty_GetRole(pr->Subordinates.Values[j]);
#ifdef EDEBUGPRO
		printf("\t\t\tCheck Subordinate %d, %s\n", j, psr->_Name);
#endif
		ttitle = GetTitleName(psr);

		if(strlen(ttitle) >= len
			 && !strncmp(title, ttitle, len)
			 && !estrisnull(psr->_Value)){

			return psr->_Value;
		}
	}

	for(j=pr->Parents.Length; j>0; --j){
		psr = Sociaty_GetRole(pr->Parents.Values[j-1]);
#ifdef EDEBUGPRO
    printf("\t\tCheck Parent %d, %s\n", j-1, psr->_Name);
#endif
		v = GetValueRecursive(psr, title, len);
		if(!estrisnull(v)) return v;
	}
	
	return NULL;
}

void InterpretValue(Role *r, char *v, char **out_curr){
	char *in_curr, *trans;
	char *in_tmp;
	int len;
	int end = 0;
	in_curr = v;
	while (!end){
//		printf("%s\n", in_curr);
		switch(in_curr[0]){
		case '\0':
//			printf("END\n");
			end=1;
			return;
		case '\\':
			if(in_curr[1] == '$' || in_curr[1] == '@'){
				in_curr ++;
			}
			else if (in_curr[1] == '\\'){
				(*out_curr)[0] = in_curr[0];
				(*out_curr) ++;
				in_curr++;
			}
			break;
	  case '$':
			in_tmp = in_curr +1;
			len = 0;
			if(eisletter(in_tmp[0])){
				len ++;
				in_tmp++;
				while(eiss(in_tmp[0])){
					len ++;
					in_tmp++;
				}			
				trans = GetValue(r, in_curr + 1, len);
//				printf("get %s\n", trans);
				InterpretValue(r, trans, out_curr);
				in_curr = in_tmp;
				continue;
			}
			else if (in_tmp[0] == '$'){
				in_tmp ++;
				if(eisletter(in_tmp[0])){
					len ++;
					in_tmp++;
					while(eiss(in_tmp[0])){
						len ++;
						in_tmp++;
					}
					trans = GetValueFromParents(r, in_curr + 2, len);
//        printf("get %s\n", trans);
					InterpretValue(r, trans, out_curr);
					in_curr = in_tmp;
					continue;
				}
      }
			break;
		case '@':
			in_tmp = in_curr +1;
      len = 0;
      if(eisletter(in_tmp[0])){
        len ++;
        in_tmp++;
        while(eiss(in_tmp[0])){
          len ++;
          in_tmp++;
        }
        trans = GetValueFromSuperiors(r, in_curr + 1, len);
//        printf("get %s\n", trans);
        InterpretValue(r, trans, out_curr);
        in_curr = in_tmp;
				continue;
      }
      break;
		default:
			;
		}
		(*out_curr)[0] = in_curr[0];
		(*out_curr) ++;
		in_curr++;
	}
}




