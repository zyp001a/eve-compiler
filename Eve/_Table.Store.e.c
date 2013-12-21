#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "HashStringToInt.h"
#define SEP '@@|Sep|'
#define SEPSTR "@@|Sep|\n"
#define egetc _IO_getc_unlocked
#define MAX_LINE_SIZE 32768
#define COL_NUM @@|ColumnNumber|

char infile[255];
long tend;
int crow;

//part1
^for @@-N.Struct.Definitions {
	iname = \&-I.Name;

	if(\&-I.Type.Hash.Name) {
		^
		sihash* \%|iname-P|_hash;
		int \%|iname-P|_ind;
		FILE* \%|iname-P|_fp;
		int \%|iname-P|_hashkeysize = \&|_Iterator.Type.Hash.KeySize-P|;
		^
	}
}
@@-N.Struct.Name = '__TableLine'
@@-N.Struct.Print
^
void stat_val(){
	int c, i, j;
	int rowi;
	char line[MAX_LINE_SIZE];
	char *it;
	int coli;
	long l;
	char *token;
	__TableLine tl;
	FILE *fp;
	FILE *fp2;
	fp = fopen("%|DatabasePath|/@@-N.edb","w");
	if(fp == NULL) fprintf(stderr,"cannot open db file\n");

	while ( (fgets(line, MAX_LINE_SIZE, stdin)) != NULL){
^
		for @@-N.Struct.Definitions {
        if (\&-i == 0) {
          ^token = strtok(line, SEPSTR);
					if(token == NULL) break;
					^;
        }else{
          ^token = strtok(NULL, SEPSTR);^;
        }
				iname = \&-I.Name;
				if(\&-I.Type.IsHash){
					if(\&-I.Type.Create){
						^
						tl.\%|iname-P| =
							sihash_getorputdb(\%|iname-P|_hash, token,
																&\%|iname-P|_ind, \%|iname-P|_fp, 
																\%|iname-P|_hashkeysize);
						^;
					}else{
						^
						tl.\%|iname-P| = sihash_get(\%|iname-P|_hash, token);
						if(tl.\%|iname-P| == NULL) continue;
						^
					}
				}else if(\&-I.Type.Name == 'char' && \&-I.Type.Size) {
					^
					if(strlen(token) >= \&|_Iterator.Type.Size-P|)
						fprintf(stderr, "exceed max size \&|_Iterator.Name-P|");
					strcpy(tl.\%|iname-P|, token);
					^;
				}else if((\&-I.Type.Name == 'int' || \&-I.Type.Name == 'short') || \&-I.Type.Name == 'char'){
					^tl.\%|iname-P| = atoi(token);
          ^;
				}else if(\&-I.Type.Name == 'long'){
          ^tl.\%|iname-P| = atol(token);
          ^;
				}else if(\&-I.Type.Name == 'float' || \&-I.Type.Name == 'double'){
          ^tl.\%|iname-P| = atof(token);
          ^;
        }
			}
^	
			fwrite(&tl, sizeof(__TableLine), 1, fp);
	}
	fclose(fp);

}
int main(int argc, char **argv){

^
  for @@-N.Struct.Definitions {
		iname = \&-I.Name;
		if(\&-I.Type.IsHash) {
			^\%|iname-P|_ind = 0;
			^
			if(\&-I.Type.Name == 'char'){
				^\%|iname-P|_hash = sihash_new(128);
				^;
			}else if(\&-I.Type.Name == 'int'){
				^\%|iname-P|_hash = sihash_new(16384);
				^;
			}
			if(\&-I.Type.Create){
				^\%|iname-P|_fp = fopen("\%|DatabasePath-P|/\&|_Iterator.Type.Hash.Name-P|.edb","w");
				^;
			}else{
				^
				sihash_adddb(\%|iname-P|_hash, "\%|DatabasePath-P|/\&|_Iterator.Type.Hash.Name-P|.edb");
				^;
			}
		}
  }
^
//
	stat_val();
^
 for @@-N.Struct.Definitions {
		iname = \&-I.Name;
		if(\&-I.Type.IsHash) {
			if(\&-I.Type.Create){
				^fclose(\%|iname-P|_fp);
				^
			}
		}
 }
^

	return 0;
}
