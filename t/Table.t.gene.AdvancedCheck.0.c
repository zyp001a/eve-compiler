#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "HashStringToInt.h"
#include "InlineRadixTreeStringToChar.h"
#define SEP '\t'
#define SEPSTR "\t\n"
#define __START_OFFSET 0
#define egetc _IO_getc_unlocked
#define MAX_LINE_SIZE 32768
#define COL_NUM 6

char infile[255];
long tend;
int crow;

//part1

		sihash* COL1_hash;
		irtree* COL1_tree;
		static void COL1_tree_iter(const char *key, const int value)
		{
			char *s = (char *)key;
			printf("key %s: %d\n", key, value);
			irtree_putstr(COL1_tree, s, SEP);
		}
		
		
		long COL2_max = LONG_MIN;
		long COL2_min = LONG_MAX;
		
		long COL3_max = LONG_MIN;
		long COL3_min = LONG_MAX;
		
		long COL4_max = LONG_MIN;
		long COL4_min = LONG_MAX;
		
		sihash* COL5_hash;
		irtree* COL5_tree;
		static void COL5_tree_iter(const char *key, const int value)
		{
			char *s = (char *)key;
			printf("key %s: %d\n", key, value);
			irtree_putstr(COL5_tree, s, SEP);
		}
		
		
		sihash* COL6_hash;
		irtree* COL6_tree;
		static void COL6_tree_iter(const char *key, const int value)
		{
			char *s = (char *)key;
			printf("key %s: %d\n", key, value);
			irtree_putstr(COL6_tree, s, SEP);
		}
		
		typedef struct __TableLine __TableLine;
struct __TableLine{
	char COL1;
	long COL2;
	long COL3;
	char COL4[15];
	char COL5;
	char COL6;
};


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
		coli=1;
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
		token = strtok(line, SEPSTR);sihash_incr(COL1_hash, token);
						token = strtok(NULL, SEPSTR);l=atol(token);
					COL2_max = l > COL2_max ? l : COL2_max;
					COL2_min = l < COL2_min ? l : COL2_min;
					token = strtok(NULL, SEPSTR);l=atol(token);
					COL3_max = l > COL3_max ? l : COL3_max;
					COL3_min = l < COL3_min ? l : COL3_min;
					token = strtok(NULL, SEPSTR);l=strlen(token);
						COL4_max = l > COL4_max ? l : COL4_max;
						COL4_min = l < COL4_min ? l : COL4_min;
						token = strtok(NULL, SEPSTR);sihash_incr(COL5_hash, token);
						token = strtok(NULL, SEPSTR);sihash_incr(COL6_hash, token);
						
//
	}		
	if(!tend) tend = ftell(fp);
}


void print_type(){
	int vali,c;
	int cc;
	printf("chromosome\n");
	
//	sihash_enum(chromosome, &iter_print);

// part4
/*
	sihash_enum(chromosome, &iter_tree);
	irtree_print_code_param p;
	p.ind = 0;
	p.rtn_stmt = "linedump.chromosome = %d;";
  p.getchar_stmt = "egetc(fp)";
  p.endchar = '\t';
  p.endstr = "\\t";
	irtree_print_code(chromosome_root, &p);
	printf("\n");
*/
//

}
int main(int argc, char **argv){
	strcpy(infile, "t/Table.t.input1");
//part5

			COL1_hash = sihash_new(128);
			irtree_init(&COL1_tree);
			
			COL5_hash = sihash_new(128);
			irtree_init(&COL5_tree);
			
			COL6_hash = sihash_new(128);
			irtree_init(&COL6_tree);
			
//
	stat_val();

	print_type();
	printf("gene.DataEndOffset =  %ld\n", tend);
	printf("gene.RowNumber =  %d\n", crow);
/*
	printf("position_max %ld\n", position_max);
	printf("row number %d\n", crow);
	printf("end offset %ld\n", tend);
*/
	return 0;
}
