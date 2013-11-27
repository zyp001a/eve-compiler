#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "3rd.h"
#define __FILE "gene.pos"
#define __START_OFFSET 0
#define __END_OFFSET 779752
#define __BASIC_LINE_NUM 22685
#define __SEP '\t'
#define egetc _IO_getc_unlocked
#define TOKE_VAL(fp, vali)														\
	vali=0;\
while((c = fget(fp))!=__SEP)\
	val[vali++] = c;\
val[vali] = '\0';\


typedef struct __TableLine{
	char chromosome;
	int position;
	char strand;
	char context;
	int mc;
	int reads;
	int id;
} __TableLine;
typedef struct __Table{
	__TableLine *lines;
	int size;
	int col_num;
} __Table;
void __readfile(char* file, __Table* pt){
	pt->size = __BASIC_LINE_NUM;

	pt->lines = 
		(__TableLine*) malloc(__BASIC_LINE_NUM * sizeof(__TableLine));
	pt->col_num = __BASIC_LINE_NUM;
	FILE *fp;
	fp = fopen(file, "r");
	fseek(fp, __START_OFFSET, SEEK_SET);
	int c;
	int vali;
	char val[255];
	__TableLine linedump;
	__TableLine* t;
	int coli=0;
	while(1){
		t = &pt->lines[coli];
		egetc(fp);egetc(fp);egetc(fp);switch(egetc(fp)){case '2':switch(egetc(fp)){case '0':egetc(fp);t->chromosome=0;break;case '1':egetc(fp);t->chromosome=1;break;case '2':egetc(fp);t->chromosome=2;break;case __SEP:t->chromosome=3;break;}break;case '1':switch(egetc(fp)){case __SEP:t->chromosome=4;break;case '0':egetc(fp);t->chromosome=5;break;case '1':egetc(fp);t->chromosome=6;break;case '2':egetc(fp);t->chromosome=7;break;case '3':egetc(fp);t->chromosome=8;break;case '4':egetc(fp);t->chromosome=9;break;case '5':egetc(fp);t->chromosome=10;break;case '6':egetc(fp);t->chromosome=11;break;case '7':egetc(fp);t->chromosome=12;break;case '8':egetc(fp);t->chromosome=13;break;case '9':egetc(fp);t->chromosome=14;break;}break;case '3':egetc(fp);t->chromosome=15;break;case '4':egetc(fp);t->chromosome=16;break;case '5':egetc(fp);t->chromosome=17;break;case '6':egetc(fp);t->chromosome=18;break;case '7':egetc(fp);t->chromosome=19;break;case '8':egetc(fp);t->chromosome=20;break;case '9':egetc(fp);t->chromosome=21;break;case 'X':egetc(fp);t->chromosome=22;break;case 'Y':egetc(fp);t->chromosome=23;break;}
		vali=0;
		while(c=egetc(fp)){
			if(c=='\t') break;
			val[vali]=c;
			vali++;
		}
		val[vali]='\0';
//		printf("%s\n", val);
		t->position = atoi(val);
		while(egetc(fp)!='\n'){}
		if(coli+1 == pt->col_num) break;
//			if(ftell(fp) == __END_OFFSET) break;
		coli++;
		
	}
	
}
void print_table(__Table* pt){
	int i;
	__TableLine *t;
	for(i=0; i<pt->col_num; i++){
		t = &pt->lines[i];
		printf("%d\t%d\n",
					 t->chromosome, t->position);
	}
}
main(){
	__Table __table;
	__readfile(__FILE, &__table);
	print_table(&__table);
	
}
