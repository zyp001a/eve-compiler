#include "Eval.h"
extern char path[];
extern Sociaty ns;
extern char* evalstr;
extern char* argsstr;
extern char *namestr;
extern char *valuestr;


#define EVALDEBUG
char* Eval(Index i){
	char *eval;
	TokenParam p;

	p.r = Sociaty_GetRole(i);
	p.title = GetTitleName(p.r);
	p.len = strlen(p.title);
	p.index = -1;

//if not null and has superiors
	if(estrisnull(p.r->_Value) && strcmp(p.r->_Name, p.title)){		
		p.r->_Value = GetValueFromSuperiors(&p);
#ifdef EVALDEBUG
		fprintf(stderr,"\tEval Set NewValue: %s\n", p.r->_Value);
#endif
	}

	p.title = evalstr;
	p.len = strlen(evalstr);
	eval = GetValue(&p);
	return EvalString(i, eval);

}
char* EvalString(Index i, char *str){
	char result_buf[MAX_BLOCK_SIZE];
  char *result = &result_buf[0];
#ifdef EVALDEBUG
	fprintf(stderr, "\tEval Content: \n========\n%s\n========\n", str);
#endif
  InterpretValue(i, str, &result);
  result[0] = '\n';
  result[1] = '\0';
  result =  &result_buf[0];
	return result;
}
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

char *GetValueRecursive(TokenParam *pp){
	Role *pr;
	char *ttitle;
	char *v;
	int j;
	TokenParam p;
	for(j=0; j<pp->r->Subordinates.Length; j++){
		pr = Sociaty_GetRole(pp->r->Subordinates.Values[j]);
#ifdef EVALDEBUG
		fprintf(stderr, "\t\tCheck Subordinate %d, %s\n", j, pr->_Name);
#endif
		ttitle = GetTitleName(pr);
		if(strlen(ttitle) < pp->len) continue;
		if(strncmp(pp->title, ttitle, pp->len)) continue;
#ifdef EVALDEBUG
    fprintf(stderr, "\t\t\tFIND!!!");
#endif
		if(pp->index == -1){
			if(!estrisnull(pr->_Value)) return pr->_Value;			
		}
		else{
			if(pp->index > pr->Elements.Length) continue;
			return Sociaty_GetRole(pr->Elements.Values[pp->index])->_Value;
		}
		
	}

	for(j=pp->r->Parents.Length; j>0; --j){
		pr = Sociaty_GetRole(pp->r->Parents.Values[j-1]);
#ifdef EVALDEBUG
    fprintf(stderr, "\t\tCheck Parent %d, %s\n", j-1, pr->_Name);
#endif
		p = *pp;
		p.r = pr;
		v = GetValueRecursive(&p);
		if(!estrisnull(v)) return v;
	}
	return NULL;
}

char *GetValue(TokenParam *pp){
	int i,j;
  Role *pr,* psr;
  char *rpr;
  char *ttitle;
  //_Value, _Name, _Super exception
#ifdef EVALDEBUG
  fprintf(stderr, "\tTry to Get Value: %s, ", pp->r->_Name);
  for(i=0; i<pp->len; i++){
    fprintf(stderr, "%c", pp->title[i]);
  }
  fprintf(stderr, ", %d\n", pp->index);
#endif
  if(!strncmp(pp->title, valuestr, pp->len)){
		if(pp->index == -1) return pp->r->_Value;
		else return Sociaty_GetRole(pp->r->Elements.Values[pp->index])->_Value;
	}
	if(!strncmp(pp->title, namestr, pp->len)) return pp->r->_Name;
  
  rpr = GetValueRecursive(pp);
	if(!estrisnull(rpr)) return rpr;

  return "";
}
char* GetValueByName(TokenParam *pp){
	char *n = estrndup(pp->title,pp->len);
	char *r = Sociaty_GetRole(Sociaty_SearchRole(n))->_Value;
	free(n);
	if(!estrisnull(r)) return r;
	return "";
}
char* GetValueFromSuperiors(TokenParam *pp){
	Role *sr;
	char *rpr;
	int i;
	TokenParam p;
	for(i=pp->r->Superiors.Length; i>0; --i){
		sr = Sociaty_GetRole(pp->r->Superiors.Values[i-1]);
#ifdef EVALDEBUG
		fprintf(stderr, "\tFrom Superior %d, %s\n", i-1, sr->_Name);
#endif		
		p = *pp;
		p.r = sr;
    rpr = GetValue(&p);
    if(!estrisnull(rpr)) return rpr;
	}
	return "";
}
char* GetValueFromParents(TokenParam *pp){
	Role *sr;
	char *rpr;
	int i;
	TokenParam p;
	for(i=pp->r->Parents.Length; i>0; --i){
		sr = Sociaty_GetRole(pp->r->Parents.Values[i-1]);
#ifdef EVALDEBUG
		fprintf(stderr, "\tFrom Parents %d, %s\n", i-1, sr->_Name);
#endif
		p = *pp;
    p.r = sr;
    rpr = GetValue(&p);
    if(!estrisnull(rpr)) return rpr;
	}
	return "";
}
/*
char* GetValueFromParents2(Role *r, char *title, int len){
	Role *pr, *ppr;
  char *rpr;
  int i,j;

  for(i=r->Parents.Length; i>0; --i){
    pr = Sociaty_GetRole(r->Parents.Values[i-1]);
		for(j=pr->Parents.Length; j>0; --j){
			ppr = Sociaty_GetRole(pr->Parents.Values[j-1]);
			rpr = GetValue(ppr, title, len);
			if(!estrisnull(rpr)){
				return rpr;
			}
		}
	}
	return "";
}
*/
char GetIdentifer(Scanner *ps, OperationType op, char idlen){
	char *trans;
	int len = 0;
	int len2;
	char *in_tmp2;
	TokenParam p;
	p.r = ps->r;
	p.index = -1;
	p.title = ps->in_curr + idlen + 1;
	if(ps->in_tmp[0] != '|') return 0;
	ps->in_tmp ++;

	if(ps->in_tmp[0] == '-'){
		ps->in_tmp ++;
		if(ps->in_tmp[0] == 'N'){
			ps->in_tmp ++;
			p.title = estrdup("_Name");
			goto OP;
		}
		else if (ps->in_tmp[0] == 'V'){
			ps->in_tmp ++;
      p.title = estrdup("_Value");
      goto OP;
		}
	}

	if(!eisletter(ps->in_tmp[0])) return 0;
	len ++;
	ps->in_tmp++;
	while(eiss(ps->in_tmp[0])){
		len ++;
		ps->in_tmp++;
	}

	if(ps->in_tmp[0] == '['){
		ps->in_tmp++;
		in_tmp2 = ps->in_tmp;
		len2 = 0;
		while(eisdigit(ps->in_tmp[0])){
			ps->in_tmp++;
			len2++;
		}
		if(ps->in_tmp[0] != ']') return 0;
		if(len2>0){
			p.index = atoi(estrndup(in_tmp2, len2));
		}
		ps->in_tmp++;
	}

	if(ps->in_tmp[0] != '|') return 0;
	ps->in_tmp ++;
	p.len = len;

OP:
	switch(op){
	case THIS: //$
//		printf("xxxxxx%s\n",ps->in_curr);
		trans = GetValue(&p);
		break;
	case PARENT: //$$
		trans = GetValueFromParents(&p);
		break;
	case SUPERIOR: //@
		trans = GetValueFromSuperiors(&p);
		break;
	case VALUE: //%
		trans = GetValueByName(&p);
		break;
	default:
		eerror("Unknow Operation");
	}

//        printf("get %s\n", trans);
	InterpretValue(ps->r->_Index, trans, ps->out_curr);
	ps->in_curr = ps->in_tmp;
	return 1;
	
}
void InterpretValue(Index i, char *v, char **out_curr){
	Scanner s;
	char c;
	s.r = Sociaty_GetRole(i);
	s.in_curr = v;
	s.out_curr = out_curr;
	while (1){
//		printf("%s\n", in_curr);
		switch(s.in_curr[0]){
		case '\0':
//			printf("END\n");
			return;
		case '\\':
			c = s.in_curr[1];
			if(c == '$'  || c == '@'  || c == '%'  ||
				 c == '|'  || c == '['  || c == ']'  ||
				 c == '\'' || c == '"'  || c == '`'  ){
				s.in_curr ++;
			}
			break;
	  case '$':
			s.in_tmp = s.in_curr + 1;
			if(s.in_tmp[0] == '$'){
				s.in_tmp ++;
				if(GetIdentifer(&s, PARENT, 2)) continue;
			}
			else{
				if(GetIdentifer(&s, THIS, 1)) continue;
			}
			break;
		case '@':
			s.in_tmp = s.in_curr + 1;
			if(GetIdentifer(&s, SUPERIOR, 1)) continue;
      break;
		case '%':
			s.in_tmp = s.in_curr + 1;
      if(GetIdentifer(&s, VALUE, 1)) continue;
      break;
		default:
			;
		}
		(*out_curr)[0] = s.in_curr[0];
		(*out_curr) ++;
		s.in_curr++;
	}
}




