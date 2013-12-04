#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "HashStr2Int.h"
#include "InlineRadixTreeChar.h"
#define SEP '\t'
#define SEPSTR "\t"
#define __START_OFFSET 0
#define egetc _IO_getc_unlocked
#define MAX_LINE_SIZE 32768
#define COL_NUM 7

char infile[255];
long tend;
int crow;

//part1
sihash *chromosome;
irtree *chromosome_root;
static void iter_tree(const char *key, const int value)
{
	char *s = (char *)key;
	irtree_putstr(chromosome_root, s, SEP);
}
long position_max = 0;
//

typedef struct __TableLine{
//part2
  char chromosome;
  long position;
//
} __TableLine;


void stat_val(){
	int c, i, j;
	int rowi;
	char line[MAX_LINE_SIZE];
	char *it;
	int coli;
	long l;
	FILE *fp;
	char *token;
	
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
//part3
		token = strtok(line, SEPSTR);
		sihash_incr(chromosome, token);
		token = strtok(NULL, SEPSTR);
		l=atol(token);
		position_max = l > position_max ? l : position_max;
//
	}		
	if(!tend) tend = ftell(fp);
}

static void iter_print(const char *key, const int value)
{
  printf("key %s: %d\n", key, value);	
}


void print_incode_hash(){
	int vali,c;
	int cc;
	printf("chromosome\n");
	
//	sihash_enum(chromosome, &iter_print);

// part4
	irtree_init(&chromosome_root);
	sihash_enum(chromosome, &iter_tree);
	irtree_print_code_param p;
	p.ind = 0;
	p.rtn_stmt = "linedump.chromosome = %d;";
  p.getchar_stmt = "egetc(fp)";
  p.endchar = '\t';
  p.endstr = "\\\t";
	irtree_print_code(chromosome_root, &p);
	printf("\n");
//

}
int main(int argc, char **argv){
	strcpy(infile, "@@|File|");
//part5
	chromosome = sihash_new(128);
//
	stat_val();
/*
	print_incode_hash();
	printf("position_max %ld\n", position_max);
	printf("row number %d\n", crow);
	printf("end offset %ld\n", tend);
*/
	return 0;
}
