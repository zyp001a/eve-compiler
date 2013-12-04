#include "Eval.h"
extern char path[];
extern Sociaty ns;
extern char *eve;
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
	Role *r= Sociaty_GetFinalRole(i);
	strcpy(str, r->_Name);
	strcat(str,".");
	strcat(str, evalstr);
//	p.title = evalstr;
//	p.len = strlen(evalstr);
//	Sociaty_AddNewRole(str);
	eval = GetDymValue(str);
//	printf("xxx%s\n", str);
	return EvalString(r, eval, 1);

}
char* EvalString(Role *r, char *str, char adddone){
	char result_buf[MAX_BLOCK_SIZE];
  char *result = &result_buf[0];
#ifdef EVALDEBUG
	fprintf(ns.Err, "\t---->Eval Content: \n========\n%s\n========\n", str);
#endif
  InterpretValue(r, str, &result);
	if(adddone){
		result[0] = '\n';
		result[1] = '\0';
		strcat(result, r->_Name);
		strcat(result, ".Done = 1\n");
	}
	else{
		result[0] = '\0';
	}
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
		if(eisfile(fname)) return fname;
/*
		strcpy(fname, token);
		strcat(fname, id);
		strcat(fname, ".ec");	
		if(eisfile(fname)) return fname;
*/
		strcpy(fname, token);
		strcat(fname, id);
		strcat(fname, ".e");	
		if(eisfile(fname)) return fname;
	}	
	return NULL;
}
char* UseFile(char *str){
  char* fpath;
  fpath=GetPath(str);
  if(fpath == NULL){
    eerror("fail to include file");
    eerror(str);
    exit(1);
  }

  if(Sociaty_SearchUsedFile(fpath) == -1){
    Sociaty_AddUsedFile(fpath);
		return fpath;
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
char* GetValue(Role *r){
	if(!estrisnull(r->_Value)) return r->_Value;
	if(r->_TargetIndex != -1)
		return Sociaty_GetRole(r->_TargetIndex)->_Value;
	return "";
}
char* GetFinalValue(Role *r){
	if(!estrisnull(r->_Value)) return r->_Value;
	Role *tmpr = r;
	while(tmpr->_TargetIndex != -1)
		 tmpr = Sociaty_GetRole(tmpr->_TargetIndex);
	return tmpr->_Value;
}
char* GetDymValueNoEve(char *name){
	int ind;
	Role *r;
	char *val;
#ifdef EVALDEBUG
  fprintf(ns.Err,"GetDymValue %s\n", name);
#endif

	ind = Sociaty_SearchRole(name);
	if(ind != -1){
		r = Sociaty_GetRole(ind);
		if(ExistValue(r)){
			val = GetFinalValue(r);
			if(!estrisnull(val)) return val;
		}
	}
	return GetValueDeep(name);

}
char* GetDymValue(char *name){
	char *v = GetDymValueNoEve(name);
	if(estrisnull(v)) v = GetDefaultValue(name);
#ifdef EVALDEBUG
	fprintf(ns.Err,"GetDymValue: %s = %s\n", name,v );
#endif
  return v;
}

char* GetDefaultValue(char *name){
	char name2[255];
	int ind;
	int len;
	char *ni, *val;
	len = strlen(name);
  ni = &name[0];
  while(len--){

    if(ni[0] == '.'){
			sprintf(name2, "%s.%s", eve, ni +1);
			ind = Sociaty_SearchRole(name2);
			if(ind != -1){
				val = GetFinalValue(Sociaty_GetFinalRole(ind));
				if(!estrisnull(val)) return val;
			}
		}
		ni ++;
	}		
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
	int slen = strlen(name);
	len = 0; 
	ni = &name[0];
	while(len++ < slen){
		ni ++;
		if(ni[0] == '.'){

//			level --;
//			if(level>0) continue;
			strcpy(suf, ni +1); //dump suffix

			strncpy(pre, name, len);
			pre[len] = '\0';
//			printf("see. %c  %d  %s   %s\n",ni[0],len,pre,suf);
			ind = Sociaty_SearchRole(pre);
			if(ind == -1) continue;
			pr = Sociaty_GetRole(ind); //get apprent role from prefix
			if(pr->_TargetIndex != -1){ //if a pointer do eval
				pr = Sociaty_GetFinalRole(ind);
				strcpy(name2, pr->_Name);
        strcat(name2, ".");
        strcat(name2, suf);

        rtn = GetDymValueNoEve(name2);
        if(!estrisnull(rtn)) return rtn;
			}
			
			for(j=pr->Parents.Length; j>0; --j){
				ppr = Sociaty_GetFinalRole(pr->Parents.Values[j-1]);
				strcpy(name2, ppr->_Name);
				strcat(name2, ".");
				strcat(name2, suf);
				
				rtn = GetDymValueNoEve(name2);
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
			tmpname = GetParentName(Sociaty_GetFinalRole(ind));
			if(tmpname == NULL){
				strcpy(name, eve);
			}
			else{
				strcpy(name, tmpname);
			}
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
//	Parameter, r: gene.AdvancedCheck.Run;

	if(estrisnull(name))
		return 1;
	if(pp->op[0] != '%' && pp->len>0){
		strcat(name, ".");
		strncat(name, pp->title, pp->len);
	}
#ifdef EVALDEBUG
	fprintf(ns.Err,"get name: %s\n",name);
#endif


	ind = Sociaty_AddNewRole(name);	
	r = Sociaty_GetFinalRole(ind);
	switch(pp->c){
	case 'V': //VALUE
		if(pp->index != -1) return 1;
		if(pp->op[0] != '%'){
			InterpretValue(r, GetDymValue(name), ps->out_curr);
		}
		else{
			InterpretValue(pp->r, GetDymValue(name), ps->out_curr);
		}
		break;
/*
	case 'E': //Elements
		if(pp->index == -1) return 1;
		if(r->Elements.Length <= pp->index) return 0;
		r = Sociaty_GetFinalRole(r->Elements.Values[pp->index]);
		InterpretValue(r, r->_Value, ps->out_curr);
		break;
*/
	case 'N': //NAME
		if(pp->index != -1) return 1;
		sprintf((*ps->out_curr),"%s",r->_Name);
    while((*ps->out_curr)[0] != '\0')
      (*ps->out_curr)++;
		break;
	case 'T':
		if(pp->index != -1) return 1;
    sprintf((*ps->out_curr),"%s",estrafter(r->_Name,'.'));
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
	case 'P':
		if(pp->index != -1) return 1;
		sprintf((*ps->out_curr),"^%s.Print^",r->_Name);
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
				 c == '\'' || c == '"'  || c == '`'  || c == '^' ){
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




