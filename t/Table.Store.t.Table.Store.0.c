#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "HashStringToInt.h"
#define SEP '\t'
#define SEPSTR "\t\n"
#define egetc _IO_getc_unlocked
#define MAX_LINE_SIZE 32768
#define COL_NUM 

char infile[255];
long tend;
int crow;

//part1
typedef struct __TableLine __TableLine;
struct __TableLine{
};

void stat_val(){
	int c, i, j;
	int rowi;
	char line[MAX_LINE_SIZE];
	char *it;
	int coli;
	long l;
	char *token;
	__TableLine tl;
	
	while ( (fgets(line, MAX_LINE_SIZE, stdin)) != NULL){
		
	}
}
int main(int argc, char **argv){


//
	stat_val();

	return 0;
}
