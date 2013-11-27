#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "str2int.h"
#define SEP '\t'
#define SEPSTR "\t"
#define __START_OFFSET 0
#define egetc _IO_getc_unlocked
#define MAX_LINE_SIZE 32768
#define COL_NUM 7
#define GETCHAR "egetc(fp)"
#define RETURN_STATEMENT "linedump.chromosome=%d;"


char infile[255];
long tend;
int crow;

StrIntMap *chromosome;
long position_max = 0;
StrIntMap *strand;
StrIntMap *context;
long mc_max = 0;
long reads_max = 0;
long id_max = 0;

typedef struct __TableLine{
  char chromosome;
  long position;
  char strand;
  char context;
  long mc;
  long reads;
  long id;
} __TableLine;

typedef struct node node;
struct node{
	char val;
	int depth;
	int count;
	node *branchs;
};
void node_init(node **pn){
	*pn = (node*)malloc(sizeof(node));
	(*pn)->val = 'x';
	(*pn)->depth=0;
	(*pn)->count=0;
	(*pn)->branchs=(node*)malloc(sizeof(node));
}
node* node_search(node *n, char c){
	int i;
	node *np;
	for(i=0; i< n->count; i++){
		if(n->branchs[i].val == c){
			np = &n->branchs[i];
			return np;
		}
	}
	return NULL;
}
int nodei=0;
void node_print(node *n){
	int i,j;
	if(n->count == 1){
		printf("%s;", GETCHAR);
		node_print(&n->branchs[0]);
	}
	else if(n->count == 0){
		printf(RETURN_STATEMENT, nodei++);
	}
	else{
		printf("switch(%s){", GETCHAR);
		for(i=0; i<n->count; i++){
			if(n->branchs[i].val == SEP)
				printf("case __SEP:");
			else
				printf("case \'%c\':", n->branchs[i].val);
			node_print(&n->branchs[i]);
			printf("break;");
		}
		printf("}");
	}
}
node* node_branch(node *n, char c){
	node *np;
	int p;
	np = node_search(n,c);
	if(np != NULL) return np;
	p = n->count ++;
	n->branchs = (node*)realloc(n->branchs, n->count * sizeof(node));
	n->branchs[p].val = c;
	n->branchs[p].count = 0;
	n->branchs[p].depth = n->depth + 1;
	n->branchs[p].branchs = (node*)malloc(sizeof(node));
	np = &n->branchs[p];
	return np;
}
node *chromosome_root;

void stat_val(){
	int c, i, j;
	int rowi;
	char line[MAX_LINE_SIZE];
	char *it;
	int coli;
	long l;
	FILE *fp;
	char *token;
	

	chromosome = sim_new(128);
	fp = fopen(infile, "r");
	fseek(fp, __START_OFFSET, SEEK_SET);
	crow = 0;
	while (fgets(line, MAX_LINE_SIZE, fp)){
		coli=2;
		it = &line[0];
		while(it++){
			if(it[0] == SEP) coli++;
			else if(it[0] == '\n' || it[0] == EOF) break;
		}
		crow++;
		if(coli != COL_NUM){
			tend = ftell(fp);
			break;
		}
		token = strtok(line, SEPSTR);
		sim_incr(chromosome, token);
		token = strtok(NULL, SEPSTR);
		l=atol(token);
		position_max = l > position_max ? l : position_max;
	}		
	if(!tend) tend = ftell(fp);
}

static void iter_print(const char *key, const int value)
{
  printf("key %s: %d\n", key, value);
	
}

static void iter_tree(const char *key, const int value)
{
  const	char *keyi;
	keyi = key;

	node *n, *nn;
	n = node_branch(chromosome_root, keyi[0]);

	while(keyi[1]!='\0'){
		nn = node_branch(n, keyi[1]);
		n = nn;
		keyi++;
	}
	node_branch(n, SEP);	
}


void print_incode_hash(){
	int vali,c;
	int cc;
	printf("chromosome\n");
	
	sim_enum(chromosome, &iter_print);
	node_init(&chromosome_root);
	sim_enum(chromosome, &iter_tree);
	node_print(chromosome_root);
	printf("\n");
/*
	for(vali=0; vali<MAX_STAT_ELEMENT_SIZE; vali++){
		cc=0;
		for(c=0; c<SCHAR_MAX; c++){
			if(chromosome[vali][c]) cc++;
		}
		
		if(cc==1){
			printf("%s;\n",GETCHAR);
		}
		else{
			printf("switch(%s){\n", GETCHAR);	
		}
	}
	printf("}\n");
*/
}
int main(int argc, char **argv){
	strcpy(infile, argv[1]);
	stat_val();
	print_incode_hash();
	printf("position_max %ld\n", position_max);
	printf("row number %d\n", crow);
	printf("end offset %ld\n", tend);
	return 0;
}
