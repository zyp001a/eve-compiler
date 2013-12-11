#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "HashStr2Int.h"
#include "InlineRadixTreeChar.h"
#define SEP '@@|Sep|'
#define SEPSTR "@@|Sep|\n"
#define __START_OFFSET @@|DataStartOffset|
#define egetc _IO_getc_unlocked
#define MAX_LINE_SIZE 32768
#define COL_NUM @@|ColumnNumber|

char infile[255];
long tend;
int crow;

//part1
^for @@-N.DraftStruct.Definitions {
	iname = \&-I.Name;
	if(\&-I.Type.Name == 'char' && !\&-I.Type.Size) {
		^
		sihash* \%|iname-P|_hash;
		irtree* \%|iname-P|_tree;
		static void \%|iname-P|_tree_iter(const char *key, const int value)
		{
			char *s = (char *)key;
			printf("key %s: %d\n", key, value);
			irtree_putstr(\%|iname-P|_tree, s, SEP);
		}
		
		^
	}else if(\&-I.Type.Name != 'char*'){
		^
		long \%|iname-P|_max = LONG_MIN;
		long \%|iname-P|_min = LONG_MAX;
		^
	}
}
^
 /*
sihash *chromosome;
irtree *chromosome_root;
long position_max = 0;
static void iter_tree(const char *key, const int value)
{
	char *s = (char *)key;
	printf("key %s: %d\n", key, value);	
	irtree_putstr(chromosome_root, s, SEP);
}
 */

//

^
@@-N.DraftStruct.Name = '__TableLine'
@@-N.DraftStruct.Print
^
/*
typedef struct __TableLine{
//part2
  char chromosome;
  long position;
//
} __TableLine;
*/

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
		^for @@-N.DraftStruct.Definitions {

				if (\&-i == 0) {
					^token = strtok(line, SEPSTR);^;
				}else{ 
					^token = strtok(NULL, SEPSTR);^;
				}

				iname = \&-I.Name;
				if(\&-I.Type.Name == 'char') {
					if(\&-I.Type.Size){
						^l=strlen(token);
						\%|iname-P|_max = l > \%|iname-P|_max ? l : \%|iname-P|_max;
						\%|iname-P|_min = l < \%|iname-P|_min ? l : \%|iname-P|_min;
						^
					}else{
						^sihash_incr(\%|iname-P|_hash, token);
						^;
					}
				}else if(\&-I.Type.Name == 'long' || \&-I.Type.Name == 'double') {
					^l=atol(token);
					\%|iname-P|_max = l > \%|iname-P|_max ? l : \%|iname-P|_max;
					\%|iname-P|_min = l < \%|iname-P|_min ? l : \%|iname-P|_min;
					^;
				}
			}
		^
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
	strcpy(infile, "@@|File|");
//part5
^
  for @@-N.DraftStruct.Definitions {
		iname = \&-I.Name;
		if(\&-I.Type.Name == 'char' && !\&-I.Type.Size) {
			^
			\%|iname-P|_hash = sihash_new(128);
			irtree_init(&\%|iname-P|_tree);
			^
		}
  }
^
//
	stat_val();

	print_type();
	printf("@@-N.DataEndOffset =  %ld\n", tend);
	printf("@@-N.RowNumber =  %d\n", crow);
/*
	printf("position_max %ld\n", position_max);
	printf("row number %d\n", crow);
	printf("end offset %ld\n", tend);
*/
	return 0;
}
