#include "Database.h"
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
static char ReadOne(FILE *fp, ReadParam *p){
	char buf2[255];
	int ii,i2;	
	int c;
	int i,j,k;
	char buf[CHECK_END_LENGTH];
	int slen;
	int max;
	char *str;
	if(egetc(fp) == EOF) return 0;
	fseek(fp, p->ia->Values[0]-1, SEEK_CUR);
	for(ii=1; ii<p->ia->Length; ii++){
		str = p->sa->Values[ii];
		slen = p->ia->Values[ii];
		max = slen;
		if(max > CHECK_END_LENGTH) max = CHECK_END_LENGTH;
//		printf("ii%d,%s,%d,max%d\n",ii,str, slen,max);		
		i = 0;
		i2 =0;
		while(1){
			c = egetc(fp);
			buf[i] = c;
			buf2[i2] = buf[i];
			i2++;
			if(buf[i] != str[i] && c != EOF){
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

			if(i==max){
//				printf("%d,%d\n",i2,max);
				buf2[i2-max+1] = '\0';
				if(max<slen) fseek(fp, slen-max, SEEK_CUR);
				break;
			}
			if(c==EOF){
				return 0;
			}
		}
		p->ra->Values[ii-1]->_Value = estrdup(buf2);
//		printf("%s\t%s\n",p->ra->Values[ii-1]->_Name, buf2);
	}
	return 1;
}
static void WriteDatabase(Role *r){
//	Role_Print(r);
}
void ParseFileAndSendToDatabase(Role *r){
	Role *fmt, *dup;
  char *fmt_text;
  char *file;
  FILE *fp;
	Scanner *ps;
	
  fmt = Sociaty_RoleEmploy(r, "Format");
	dup = Sociaty_RoleEmploy(r, "Dump");
  fmt_text = GetDymValue(RoleHash_Get(r->Subs, "FormatText"));
  file = GetDymValue(RoleHash_Get(r->Subs, "File"));
  fp = fopen(file,"r");
  if(fp!=NULL){

		char *out;
		ps = Scanner_New(dup, fmt_text, &out);
		ps->read_param = ReadParam_New();

		*ps->out_curr = &ps->read_param->buf[0];
		ps->is_read = 1;

		InterpretValue(ps);
		if(ps->read_param->sa->Length){
			SeekToStart(fp, ps->read_param->sa->Values[0]);
			while(ReadOne(fp, ps->read_param)){
				printf("%s\t%s\n",ps->read_param->ra->Values[0]->_Value,ps->read_param->ra->Values[1]->_Value);
				WriteDatabase(dup);
			}
		}
  }
}
