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

	char str[255];
//	Role *r;
	char *eval;
	strcpy(str, Sociaty_GetRole(i)->_Name);
	strcat(str,".");
	strcat(str, evalstr);
//	p.title = evalstr;
//	p.len = strlen(evalstr);
//	Sociaty_AddNewRole(str);
	eval = GetDymValue(str);
//	printf("xxx%s\n", str);
	return EvalString(i, eval);

}
char* EvalString(Index i, char *str){
	char result_buf[MAX_BLOCK_SIZE];
  char *result = &result_buf[0];
#ifdef EVALDEBUG
	fprintf(ns.Err, "\t---->Eval Content: \n========\n%s\n========\n", str);
#endif
  InterpretValue(Sociaty_GetRole(i), str, &result);
  result[0] = '\n';
  result[1] = '\0';

	strcat(result, Sociaty_GetRole(i)->_Name);
	strcat(result, ".Done = 1\n");

  result =  &result_buf[0];
#ifdef EVALDEBUG
	fprintf(ns.Err, "\t---->Result: \n========\n%s\n========\n", result);
#endif
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
//			printf("%s\n", fname);
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
char ExistValue(Role *r){
	if(!estrisnull(r->_Value)) return 1;
	if(r->_TargetIndex != -1) return 1;
	return 0;
}
char *GetParentName(Role *r){
	if(r->Parents.Length == 0) return NULL;
	return Sociaty_GetRole(r->Parents.Values[r->Parents.Length-1])->_Name;
}
char* GetDymValue(char *name){
	int ind;
	Role *r;
#ifdef EVALDEBUG
  fprintf(ns.Err,"GetDymValue %s\n", name);
#endif

	ind = Sociaty_SearchRole(name);
	if(ind == -1){
		return GetValueDeep(name);
	}
	r = Sociaty_GetRole(ind);
	if(ExistValue(r)){
		return GetValue(r);
	}
	else{
		return GetValueDeep(name);
	}
	return "";
}
char* GetValue(Role *r){
	if(!estrisnull(r->_Value)) return r->_Value;
	if(r->_TargetIndex != -1)
		return Sociaty_GetRole(r->_TargetIndex)->_Value;
	return "";
}
char* GetValueDeep(char *name){
//	printf("name %s\tlevel %d\n",name,level);
#ifdef EVALDEBUG
	fprintf(ns.Err,"GetValueDeep %s\n", name);
#endif
	Role *pr, *ppr;
	char *ni;
	int len, ind, j;
	char name2[255], pre[255], suf[255];
	Role *r;
	char *rtn;
/*
	ind = Sociaty_SearchRole(name);
	if(ind != -1){
		r = Sociaty_GetRole(ind);
		return r;
//			if(!estrisnull(r->_Value)) return r;
	}
*/
	len = strlen(name);
	ni = &name[len];
	while(len){
		len --;
		ni --;
		if(ni[0] == '.'){
//			level --;
//			if(level>0) continue;
			strcpy(suf, ni +1);
			strncpy(pre, name, len);
			pre[len] = '\0';
			ind = Sociaty_SearchRole(pre);
			if(ind == -1) continue;
			pr = Sociaty_GetFinalRole(ind);

			for(j=pr->Parents.Length; j>0; --j){
				ppr = Sociaty_GetFinalRole(pr->Parents.Values[j-1]);
				strcpy(name2, ppr->_Name);
				strcat(name2, ".");
				strcat(name2, suf);
				
				rtn = GetDymValue(name2);
				if(!estrisnull(rtn)) return rtn;
			}
		}
	}
	return "";
}
char EvalParam(TokenParam *pp, Scanner *ps){
	char name[255], *tmpname;
	char *tmp;
	Role *r;
	int opi;
	int ind;

	tmp = &pp->op[0];
	opi = pp->oplen;
	if(pp->op[0] == '%'){ //absolute name
		tmp ++;
    opi --;
		if(pp->len > 0 ){
			strncpy(name, pp->title, pp->len);
			name[pp->len] = '\0';
		}
		else{
			return 0;
		}
	}
	else if(pp->op[0] == '&'){ //relative name
		tmp ++;
		opi --;
		strcpy(name, pp->r->_Name);
	}
	else{
		strcpy(name, pp->r->_Name);
	}
	
	while(opi>0){
		switch(tmp[0]){
		case '$':
			ind = Sociaty_SearchRole(name);
			if(ind == -1) return 0;
			tmpname = GetParentName(Sociaty_GetRole(ind));
			if(tmpname == NULL) return 0;
			strcpy(name, tmpname);
			break;
		case '@':
			tmpname = estrbeforedup(name, '.');
			strcpy(name, tmpname);
			free(tmpname);
			break;
		default:
			return 0;
		}
		opi--;
		tmp++;
	}

	if(estrisnull(name))
		return 1;
	if(pp->op[0] != '%' && pp->len>0){
		strcat(name, ".");
		strncat(name, pp->title, pp->len);
	}


	ind = Sociaty_AddNewRole(name);	
	r = Sociaty_GetRole(ind);
	switch(pp->c){
	case 'V': //VALUE
		if(pp->index != -1) return 1;
		InterpretValue(r, GetDymValue(name), ps->out_curr);
		break;
	case 'E': //Elements
		if(pp->index == -1) return 1;
		if(r->Elements.Length <= pp->index) return 0;
		r = Sociaty_GetRole(r->Elements.Values[pp->index]);
		InterpretValue(r, r->_Value, ps->out_curr);
		break;
	case 'N': //NAME
		if(pp->index != -1) return 1;
		sprintf((*ps->out_curr),"%s",r->_Name);
    while((*ps->out_curr)[0] != '\0')
      (*ps->out_curr)++;
		break;
	case 'L':
		if(pp->index != -1) return 1;
		sprintf((*ps->out_curr),"%d",r->Elements.Length);
		while((*ps->out_curr)[0] != '\0') 
			(*ps->out_curr)++;
		break;
  case 'I':
		if(pp->index != -1) return 1;
		sprintf((*ps->out_curr),"%s._Iterator",r->_Name);
		while((*ps->out_curr)[0] != '\0')
      (*ps->out_curr)++;
		break;
/*
	case 'P': //Parents
		break;
	case 'S': //Superiors
		break;
	case 'B': //Subordinates
		break;
*/
	default:
		return 0;
	}


	return 1;
}

char ScanIdentifer(Scanner *ps){
	int len, len2;
	char *tmp, *tmp2;
	Role *rtn;
//	Role *opr;
	int see_left = 0;
	int see_dash = 0;
	char *val, *indexstr;
	char c;
	TokenParam p;
	p.r = ps->r;

	p.op = ps->in_curr;
	tmp = ps->in_curr+1;
	p.oplen = 1;
	while(tmp[0] == '$' || tmp[0] == '@'){
		p.oplen++;
		tmp++;
	}

	rtn = NULL;	
	p.len = 0;
	if(tmp[0] == '|'){
		see_left =1;
		tmp ++;
		p.title = tmp;
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
			if(tmp[0] == '|' || tmp[0] == '-'){	
//				printf("xxxxx%c\n",p.op[0]);
				break;
			}
			else if(tmp[0] == '.'){
				p.len++;
				tmp ++;
			}
			else{
				return 0;
			}
		}
	}

//	fprintf(ns.Err,"---------%c:%s:%s\n",p.op[0],rtn->_Name,rtn->_Value);
	p.index = -1;
	if(tmp[0] == '-'){
		see_dash = 1;
		p.c = tmp[1];
		tmp += 2;
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
			p.index = atoi(indexstr);
			free(indexstr);
    }
	}
	else{
		p.c = 'V';
	}

	if(see_left){
		if(tmp[0] != '|') return 0;
		tmp ++ ;
	}
	if(!see_left && !see_dash) return 0;
#ifdef EVALDEBUG
	int i;
  fprintf(ns.Err, "Parameter, r: %s\n\t",	p.r->_Name);
  for(i=0; i<p.len; i++){
    fprintf(ns.Err, "%c", p.title[i]);
  }
  fprintf(ns.Err, "\top ");
	for(i=0; i<p.oplen; i++){
    fprintf(ns.Err, "%c", p.op[i]);
  }
  fprintf(ns.Err, "\tindex %d\tchar %c\n", p.index, p.c);
#endif

	if(!EvalParam(&p, ps)) return 0;

	ps->in_curr = tmp;
	return 1;
}
void InterpretValue(Role *r, char *v, char **out_curr){
	Scanner s;
	char c;
	s.r = r;
	s.in_curr = v;
	s.out_curr = out_curr;
	while (1){

		switch(s.in_curr[0]){
		case '\0':
			return;
		case '\\':
			c = s.in_curr[1];
			if(c == '$'  || c == '@'  || c == '%'  || c == '&'  ||
				 c == '|'  || c == '['  || c == ']'  || c == '\\' ||
				 c == '\'' || c == '"'  || c == '`'  ){
				s.in_curr ++;
			}
			break;
		case '%':
      if(ScanIdentifer(&s)) continue;
      break;
		case '&':
			if(ScanIdentifer(&s)) continue;
      break;
		case '@':
      if(ScanIdentifer(&s)) continue;
      break;
    case '$':
      if(ScanIdentifer(&s)) continue;
      break;
		default:
			;
		}
		(*s.out_curr)[0] = s.in_curr[0];
		(*s.out_curr) ++;
		s.in_curr++;
	}
}




