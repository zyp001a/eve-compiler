#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define SEP '\t'
#define SEPSTR "\t"
#define __START_OFFSET 0
#define egetc _IO_getc_unlocked
#define MAX_LINE_SIZE 32768
#define COL_NUM 7
#define GETCHAR "egetc(fp)"
#define RETURN_STATEMENT "linedump.chromosome=%d;"

typedef struct irtree irtree;
struct irtree{
	char val;
	int depth;
	int count;
	irtree *branchs;
};
void irtree_init(irtree **pn){
	*pn = (irtree*)malloc(sizeof(irtree));
	(*pn)->val = 'x';
	(*pn)->depth=0;
	(*pn)->count=0;
	(*pn)->branchs=(irtree*)malloc(sizeof(irtree));
}
irtree* irtree_search(irtree *n, char c){
	int i;
	irtree *np;
	for(i=0; i< n->count; i++){
		if(n->branchs[i].val == c){
			np = &n->branchs[i];
			return np;
		}
	}
	return NULL;
}
//extern int irtreei;
//extern char *rtn_stmt;
//extern char *getchar_stmt;
typedef struct irtree_print_code_param{
	char *getchar_stmt;
	char *rtn_stmt;
	int ind;
	char endchar;
	char *endstr;
} irtree_print_code_param;
void irtree_print_code(irtree *n, irtree_print_code_param *p){
	int i,j;
	if(n->count == 1){
		printf("%s;", p->getchar_stmt);
		irtree_print_code(&n->branchs[0], p);
	}
	else if(n->count == 0){
		printf(p->rtn_stmt, p->ind++);
	}
	else{
		printf("switch(%s){", p->getchar_stmt);
		for(i=0; i<n->count; i++){
			if(n->branchs[i].val == p->endchar){
				printf("case \'%s\':", p->endstr);
			}
			else{
				printf("case \'%c\':", n->branchs[i].val);
			}
			irtree_print_code(&n->branchs[i], p);
			printf("break;");
		}
		printf("}");
	}
}
irtree* irtree_branch(irtree *n, char c){
	irtree *np;
	int p;
	np = irtree_search(n,c);
	if(np != NULL) return np;
	p = n->count ++;
	n->branchs = (irtree*)realloc(n->branchs, n->count * sizeof(irtree));
	n->branchs[p].val = c;
	n->branchs[p].count = 0;
	n->branchs[p].depth = n->depth + 1;
	n->branchs[p].branchs = (irtree*)malloc(sizeof(irtree));
	np = &n->branchs[p];
	return np;
}
void irtree_putstr(irtree *root, char *str, char endstr){
	char *keyi;
	keyi = &str[0];
	irtree *n, *nn;
	n = irtree_branch(root, keyi[0]);
	while(keyi[1]!='\0'){
		nn = irtree_branch(n, keyi[1]);
		n = nn;
		keyi++;
	}
	irtree_branch(n, endstr);	
}

