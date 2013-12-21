#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define egetc _IO_getc_unlocked
#define CHECK_START_LENGTH 5
char SeekToStart(FILE *fp, char *str){
	char c;
	int i,j,k;
	char buf[CHECK_START_LENGTH];
	int slen = strlen(str);
	int max = slen;
	if(max > CHECK_START_LENGTH) max = CHECK_START_LENGTH;
	i = 0;
	while(1){
		buf[i] = egetc(fp);
		if(buf[i] != str[i]){
			if(i>0){
				j=0;
				k=0;
				while(j<i-1){
					if(buf[j+1]==str[j]){
						buf[k]=buf[j+1];
						k++;
					}
					else{
						k = 0;
					}
					j ++;
				}
				i = k;
			}
			continue;
		}
		i ++;
//		printf("i%d\tmax\t%d\tslen\t%d\t%s\n",i,max,slen,str);
		if(i==max){
//			if(max<slen) fseek(fp, slen-max, SEEK_CUR);
			fseek(fp, -max, SEEK_CUR);
			return 1;
		}
	}
	return 0;
}

void GetFileStartAndColumnNum(File *fp, long *pos, int *col_num){
	int c,i;
	int csep = 0;
	
	long leol = 0;
	long leol2 = 0;
	int lcsep = 0;

	long tstart = -1;
	long thead = -1;
  int	crow = 0;

  int ccol = 0;

	while (c=egetc(fp)){
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
						tstart = -1;
						thead = -1;
						crow = 0;
					}
					else if(lcsep == csep - 1){
						if(thead == -1){
							thead = leol2;
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
	*pos = tstart;
	*col_num = ccol;
}
