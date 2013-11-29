#include "Eval.h"
extern char path[];
extern Sociaty ns;
extern char *evalstr;
extern char *argsstr;
extern char *namestr;
extern char *valuestr;
extern char *elementstr;


#define EVALDEBUG
char* Eval(Index i){
//	TokenParam p;
/*
	p.r = Sociaty_GetRole(i);
	p.cr = p.r;
	p.title = GetTitleName(p.r);
	p.len = strlen(p.title);
*/
//	p.index = -1;

//if not null and has superiors
/*
	if(estrisnull(p.r->_Value) && strcmp(p.r->_Name, p.title)){		
		p.r->_Value = GetValueFromSuperiors(&p);
#ifdef EVALDEBUG
		fprintf(ns.Err,"\tEval Set NewValue: %s\n", p.r->_Value);
#endif
	}
*/

	char str[255];
	Role *r;
	strcpy(str, Sociaty_GetRole(i)->_Name);
	strcat(str,".");
	strcat(str, evalstr);
//	p.title = evalstr;
//	p.len = strlen(evalstr);
	r = GetRole(str, 0);
	if(r == NULL){
		fprintf(ns.Err, "The method is not exist: %s\n", str);
		return "\n";
	}
	else{
		return EvalString(i, i, r->_Value);
	}

}
char* EvalString(Index i, Index ci, char *str){
	char result_buf[MAX_BLOCK_SIZE];
  char *result = &result_buf[0];
#ifdef EVALDEBUG
	fprintf(ns.Err, "\tEval Content: \n========\n%s\n========\n", str);
#endif
  InterpretValue(Sociaty_GetRole(i), Sociaty_GetRole(i), str, &result);
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
/*
char* GetTitleName(Role *r){
	return estrafter(r->_Name, '.');
}

Role *GetRoleRecursive(TokenParam *pp){
	Role *pr;
  char *ttitle;
	int j;
	for(j=0; j<pp->r->Subordinates.Length; j++){
    pr = Sociaty_GetRole(pp->r->Subordinates.Values[j]);
		ttitle = GetTitleName(pr);
		if(strlen(ttitle) < pp->len) continue;
		if(strncmp(pp->title, ttitle, pp->len)) continue;
		if(pp->index == -1){
      if(!estrisnull(pr->_Value)) return pr;
    }
    else{
      if(pp->index > pr->Elements.Length) continue;
      return Sociaty_GetRole(pr->Elements.Values[pp->index]);
    }
	}
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
		fprintf(ns.Err, "\t\tCheck Subordinate %d, %s\n", j, pr->_Name);
#endif
		ttitle = GetTitleName(pr);
		if(strlen(ttitle) < pp->len) continue;
		if(strncmp(pp->title, ttitle, pp->len)) continue;
#ifdef EVALDEBUG
    fprintf(ns.Err, "\t\t\tFIND!!!");
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
    fprintf(ns.Err, "\t\tCheck Parent %d, %s\n", j-1, pr->_Name);
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
  fprintf(ns.Err, "\tTry to Get Value: %s, ", pp->r->_Name);
  for(i=0; i<pp->len; i++){
    fprintf(ns.Err, "%c", pp->title[i]);
  }
  fprintf(ns.Err, ", %d\n", pp->index);
#endif
	

  if(!strncmp(pp->title, valuestr, pp->len))
		return pp->r->_Value;
	if(!strncmp(pp->title, namestr, pp->len)) 
		return pp->r->_Name;
	if(!strncmp(pp->title, elementstr, pp->len) && pp->index != -1)
		return Sociaty_GetRole(pp->r->Elements.Values[pp->index])->_Value;
	if(!strncmp(pp->title, argsstr, pp->len))
		return Sociaty_GetRole(pp->r->Args.Values[pp->index])->_Value;
  
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
		fprintf(ns.Err, "\tFrom Superior %d, %s\n", i-1, sr->_Name);
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
		fprintf(ns.Err, "\tFrom Parents %d, %s\n", i-1, sr->_Name);
#endif
		p = *pp;
    p.r = sr;
    rpr = GetValue(&p);
    if(!estrisnull(rpr)) return rpr;
	}
	return "";
}
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
Role* GetRole(char *name, int level){
	Role *pr, *ppr;
	char *ni;
	int len, ind, j;
	char name2[255], pre[255], suf[255];
	Role *r;
	if(level==0){
		ind = Sociaty_SearchRole(name);
		if(ind != -1){
			r = Sociaty_GetRole(ind);
			if(!estrisnull(r->_Value)) return r;
		}
	}
	len = strlen(name);
	ni = &name[len];
	while(len){
		len --;
		ni --;
		if(ni[0] == '.'){
			level --;
			if(level>0) continue;
			strcpy(suf, ni +1);
			strncpy(pre, name, len);
			pre[len] = '\0';
			ind = Sociaty_SearchRole(pre);
			if(ind == -1) continue;
			pr = Sociaty_GetRole(ind);
			for(j=pr->Parents.Length; j>0; --j){
				ppr = Sociaty_GetRole(pr->Parents.Values[j-1]);
				strcpy(name2, ppr->_Name);
				strcat(name2, ".");
				strcat(name2, suf);
				r = GetRole(name2, 0);
				if(r != NULL) return r;
			}
		}
	}
	return NULL;
}
Role *GetRoleByParam(TokenParam *pp){
	char name[255];
	char *tmp;
	Role *rtn;
	int opi;
	int level;
//	printf("xxxxxxxx%d\n", pp->len);
	if(pp->op[0] == '%'){ //absolute name 

		strncpy(name, pp->title, pp->len);
		name[pp->len] = '\0';
//		printf("xxxxxxxx%s,%d\n", &name[0],pp->len);
		rtn = GetRole(&name[0], 0);

	}
	else if(pp->op[0] == '&'){ //relative name
		strcpy(name, pp->cr->_Name);
		strcat(name, ".");
		strncat(name, pp->title, pp->len);
		rtn = GetRole(&name[0], 0);
	}
	else{
		opi = 0;
		level = 0;
		while(opi<pp->oplen){
			if(pp->op[opi] == '$'){
				strcpy(name, pp->r->_Name);
				strcat(name, ".");
				strncat(name, pp->title, pp->len);
				rtn = GetRole(&name[0], level);
				level ++;
			}
			else if(pp->op[opi] == '@'){
//				printf("%s\n", pp->r->_Name);
				tmp = estrbeforedup(pp->r->_Name, '.');
//				printf("%s\n",tmp);
				strcpy(name, tmp);
				strcat(name, ".");
        strncat(name, pp->title, pp->len);
				rtn = GetRole(&name[0], level);
			}
			opi++;
		}
	}
	return rtn;
}

char ScanIdentifer(Scanner *ps){
	int len, len2;
	char *tmp, *tmp2;
	Role *rtn;
	char *val, *indexstr;
	int index;
	char c;
	TokenParam p;
	p.r = ps->r;
	p.cr = ps->cr;


	tmp = ps->in_curr;
//	printf("xxxx, %c%c\n", tmp[0], tmp[1]);
	
  /* get op*/
	p.op = ps->in_curr;
	p.oplen = 0;
	while(tmp[0] == '$' || tmp[0] == '@' || tmp[0] == '%'|| tmp[0] == '&'){
		p.oplen++;
		tmp++;
	}
//	printf("%s\n",tmp[-1]);
// TODO @-V &-V
	if(p.op[p.oplen-1] == '$' && tmp[0] == '-'){

		c = tmp[1];
		tmp +=2;
		index = -1;
		if(tmp[0] == '['){
      tmp++;
			tmp2 = tmp;
			len2= 0;
      while(eisdigit(tmp[0])){
				len2++;
        tmp++;
      }
      if(tmp[0] != ']') return 0;
      tmp++; //skip ]
			indexstr = estrndup(tmp2, len2);
			index = atoi(indexstr);
			free(indexstr);
    }

		switch(c){
		case 'N': //NAME
			if(index != -1) return 0;
			rtn = ps->r;
			val = ps->r->_Name;
			break;
		case 'V': //VALUE
			if(index != -1) return 0;
			rtn = ps->r;
			val = ps->r->_Value;
			break;
		case 'A': //ARGV
			if(ps->r->Args.Length <= index) return 0;
			rtn = Sociaty_GetRole(ps->r->Args.Values[index]);
			val =	rtn->_Value;
			break;
		case 'E': //Elements
      if(ps->r->Elements.Length <= index) return 0;
      rtn = Sociaty_GetRole(ps->r->Elements.Values[index]);
      val = rtn->_Value;
      break;
		case 'P': //Parents
			break;
		case 'S': //Superiors
			break;
		case 'B': //Subordinates
			break;
		}

		InterpretValue(ps->r, rtn, val, ps->out_curr);
		ps->in_curr = tmp;
		return 1;
	}

	
	
	if(tmp[0] != '|') return 0; 
	tmp ++;
	p.title = tmp;
	p.len = 0;
	/*get identifiers*/
	while(1){
		/*get title*/
		if(!eisletter(tmp[0])) return 0;
		p.len ++;
		tmp++;
		while(eiss(tmp[0])){
//		printf("%c\t%d\n", tmp[0], p.len);
			p.len ++;
			tmp++;
		}

		/*get index
			index must be digits
		 */
		if(tmp[0] == '['){
			p.len ++;
			tmp++;
			while(eisdigit(tmp[0])){ 
				p.len ++;
				tmp++;
			}
			if(tmp[0] != ']') return 0;
			p.len ++;
			tmp++; //skip ]
		}
		/*eval para*/
		if(tmp[0] == '|') break;
		if(tmp[0] != '.') return 0;
		p.len++;
		tmp ++;
	}
	rtn = GetRoleByParam(&p);
	if(rtn == NULL) return 0;
	InterpretValue(ps->r, rtn, rtn->_Value, ps->out_curr);
	ps->in_curr = tmp + 1;
	return 1;
	
}
void InterpretValue(Role *r, Role *cr, char *v, char **out_curr){
	Scanner s;
	char c;
	s.r = r;
	s.cr = cr;
	s.in_curr = v;
	s.out_curr = out_curr;
	while (1){
//		printf("%c\n", s.in_curr[0]);

		switch(s.in_curr[0]){
		case '\0':
//			printf("END\n");
			return;
		case '\\':
			c = s.in_curr[1];
			if(c == '$'  || c == '@'  || c == '%'  || c == '&' ||
				 c == '|'  || c == '['  || c == ']'  ||
				 c == '\'' || c == '"'  || c == '`'  ){
				s.in_curr ++;
			}
			break;
	  case '$':
			if(ScanIdentifer(&s)) continue;
			break;
		case '@':
			if(ScanIdentifer(&s)) continue;
      break;
		case '%':
      if(ScanIdentifer(&s)) continue;
      break;
		case '&':
			if(ScanIdentifer(&s)) continue;
      break;
		default:
			;
		}
		(*out_curr)[0] = s.in_curr[0];
		(*out_curr) ++;
		s.in_curr++;
	}
}




