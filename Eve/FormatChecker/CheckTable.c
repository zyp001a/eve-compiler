#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MIN_ADJ_ROW 5
#define MIN_CHECK_ROW 1000
#define MAX_STAT_ELEMENT_SIZE 40
#define MAX_CHAR_ELEMENT_SIZE 15
#define AS_CATEGORY_CCHAR_CUT_LOW 8
#define AS_CATEGORY_CCHAR_CUT 15
#define AS_CATEGORY_CNOTNUM_CUT 8
#define SEP '\t'

typedef enum TypeV{
	TCATEGORY,
	TUINT,
	TINT,
	TUNUM,
	TNUM,
	TWORD,
	TSTRING
} TypeV;
char* TypeVNames[] = {
	"char",
	"int", //	"unsigned int",
	"int",
	"double", //	"unsigned double",
	"double",
	"char[15]", //MAX_CHAR_ELEMENT_SIZE
	"char*"
};

typedef struct ColStat{
	TypeV type;
	unsigned long max_len;
	char name[255];
} ColStat;

ColStat *colstat;
char infile[255];
FILE *fp;
int **cmap;
int **clen;
int ccol;
int crow;
char is_head_shorter;
long thead;
long tstart;
long tend;

void get_col_num(){
	int c,i;
	int csep = 0;
	
	long leol = 0;
	long leol2 = 0;
	int lcsep = 0;

	is_head_shorter = 0;
	tstart = -1;
	thead = -1;
	crow = 0;

  ccol = 0;
	fp = fopen(infile, "r");
	while (c=getc(fp)){
		if(c == EOF) break;
//		if( c> 127) printf("%d\t%c\n", c, c);
		else if(c == SEP){
			csep++;
		}
		else if (c == '\n'){
			if(lcsep){
				if(lcsep==csep){
					if(thead == -1) thead = leol2;
					if(tstart == -1) tstart = leol;
					crow++;
					if(crow > MIN_ADJ_ROW){
						ccol = lcsep + 1;
						break;
					}
				}
				else{
					if(crow){
						is_head_shorter = 0;
						tstart = -1;
						thead = -1;
						crow = 0;
					}
					else if(lcsep == csep - 1){
						if(thead == -1){
							thead = leol2;
							is_head_shorter = 1;
						}
						if(tstart == -1) tstart = leol;
					}
				}
			}
			lcsep = csep;
			csep = 0;
			leol2 = leol;
			leol = ftell(fp); 
		}
	}

}
void get_col_val_dump(){
	int c,i,j;
	int coli;
	int rowi;
	int vallen;

	cmap = (int **) malloc(ccol * sizeof(int*));
	for(j=0; j<ccol; j++) 
		cmap[j] = (int *)calloc(SCHAR_MAX, sizeof(int));
	clen = (int **)calloc(ccol, sizeof(int*));
  for(j=0; j<ccol; j++)
    clen[j] = (int *)calloc(MAX_STAT_ELEMENT_SIZE, sizeof(int));

	fseek(fp, thead, SEEK_SET);
	coli=0;
	rowi=0;
	vallen=0;
	while (c=getc(fp)) if (c == '\n') break; //skip one line
	while (c=getc(fp)) if (c == '\n') break; //skip 2rd line
	while (c=getc(fp)) if (c == '\n') break; //skip 3rd line
	while (c=getc(fp)){
		if(c == EOF) break;
		else if(c == SEP){
			if(vallen > MAX_STAT_ELEMENT_SIZE) vallen = MAX_STAT_ELEMENT_SIZE;
			clen[coli][vallen-1]++;
			vallen=0;
			coli++;
		}
		else if (c == '\n'){
			if(vallen > MAX_STAT_ELEMENT_SIZE) vallen = MAX_STAT_ELEMENT_SIZE;
      clen[coli][vallen-1]++;
      vallen=0;
			rowi++;
			if(rowi>MIN_CHECK_ROW) break;
			if(tend == ftell(fp)) break;
			coli=0;
		}
		else{
			if(vallen < MAX_CHAR_ELEMENT_SIZE)
				cmap[coli][c]++;
			vallen++;
		}
	}

}
TypeV get_type(int *pmap, int *plen){
	int i;
	int cdiff_char, cdiff_char_nd, cdiff_len;
	char not_num = 0;
	int max_len;

	cdiff_char = 0;
	cdiff_char_nd = 0;
	for(i=0; i<SCHAR_MAX; i++){
		if(pmap[i]){
			if(i != 'e' && i != 'E' &&
				 (i > '9' || i < '+' ||
					i == ',' || i == '.' || i == '/')
				){
				not_num = 1;
				cdiff_char_nd ++;
			}
			cdiff_char++;
		}
	}
	
	if(cdiff_char < AS_CATEGORY_CCHAR_CUT_LOW)
		return TCATEGORY;
	if(!not_num)
	{
		if(pmap['-'] || pmap['+'])
			if(pmap['.'])
				return TNUM;
			else
				return TINT;
		else
			if(pmap['.'])
				return TUNUM;
			else
				return TUINT;
	}				
	else {
		for(i=0; i<MAX_STAT_ELEMENT_SIZE; i++)
			if(plen[i])	max_len = i+1;
//		printf("%d\t%d\n", cdiff_char, cdiff_char_nd);
		if (cdiff_char < AS_CATEGORY_CCHAR_CUT &&
				cdiff_char_nd > AS_CATEGORY_CNOTNUM_CUT){
			return TCATEGORY;
		}
		else if (max_len != MAX_STAT_ELEMENT_SIZE){
			return TWORD;
		}
		else{
			return TSTRING;
		}
	}	
}
char validate_type(){
	int coli, vali, c;
	char rtn;
	rtn = 1;
	coli=0;
	while (c=getc(fp)){
		if(c == '\n') break;
		else if(c == '\t'){
			coli ++;
		}
		else{
			if(cmap[coli][c] == 0){
				rtn = 0;
			}
		}
	}
	return rtn;
}

void analysis_col_typev(){
	int coli, vali;
	TypeV t;
	int c;
	char val[255];
	int get_head;
	colstat = (ColStat *)malloc(ccol * sizeof(ColStat));
	for(coli=0; coli<ccol; coli++){
		colstat[coli].type = get_type(cmap[coli], clen[coli]);
	}

	fseek(fp, thead, SEEK_SET);
	if(is_head_shorter){
		crow--;
		strcpy(colstat[0].name, "COL1");
		coli=1;
		vali = 0;
		while (c=getc(fp)){
			if(c == '\n'){
				val[vali] = '\0';
        vali = 0;
        strcpy(colstat[coli].name, val);
				break;			
			}
			else if(c == SEP){
				val[vali] = '\0';
				vali = 0;
				strcpy(colstat[coli].name, val);
				coli ++;
			}
			else{
				val[vali] = c;
				vali++;
			}
		}
	}
	else{
		get_head=validate_type();
//		printf("%d\n",get_head);
		if(!get_head){
			fseek(fp, thead, SEEK_SET);
			coli = 0;
			vali = 0;
			while (c=getc(fp)){
				if(c == '\n'){
					val[vali] = '\0';
          vali = 0;
          strcpy(colstat[coli].name, val);
					break;
				}
				else if(c == SEP){
					val[vali] = '\0';
					vali = 0;
					strcpy(colstat[coli].name, val);
					coli ++;
				}
				else{
					val[vali] = c;
					vali++;
				}
			}
		}
		else{
			tstart = thead;
			for(coli=0; coli<ccol; coli++){
				sprintf(val, "COL%d", coli + 1);
				strcpy(colstat[coli].name, val);
			}
		}		
	}

}

void get_row_num_small(){
	int c,i;
	int csep;
	long leol = 0;
	char see_end;

	crow = 0;
	csep = 0;
	see_end = 0;
	fseek(fp, thead, SEEK_SET);
	while (c=getc(fp)){
		if(c == EOF) break;
		else if(c == SEP){
			csep++;
		}
		else if (c == '\n'){
			if(ccol!=csep+1 || crow > MIN_CHECK_ROW){
				tend = leol;
				see_end=1;
				break;
			}
			leol = ftell(fp);
			csep = 0;
			crow ++;
		}

	}
	if(!see_end) tend = ftell(fp);
	
}



int main(int argc, char **argv){
	strcpy(infile, argv[1]);
//	printf("%s\n",TypeVNames[5]);
//	strcpy(TypeVNames[5], "char[");
//	char buf[5];
/*
	sprintf(buf,"%d",MAX_CHAR_ELEMENT_SIZE);
	strcat(TypeVNames[TWORD], buf);
	strcat(TypeVNames[TWORD],"]");
*/
	get_col_num();
	get_row_num_small();
	get_col_val_dump();
	analysis_col_typev();
	fprintf(stderr, "column number %d\n", ccol);
	fprintf(stderr, "checked row number %d\n", crow);
	fprintf(stderr, "head %ld, start %ld, end %ld\n", thead, tstart, tend);
	int coli;
	for(coli=0; coli<ccol; coli++){
		printf("%s %s;\n",
					 TypeVNames[colstat[coli].type],
					 colstat[coli].name);
	}

//	readf();
	return 0;
//	printcmap();
}
