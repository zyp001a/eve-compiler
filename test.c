#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *bb = "ad $c $c";
char *c = "cxxxx";

char eisletter(char c){
	if(c >= 'a' && c <= 'z') return 1;
	if(c >= 'A' && c <= 'Z') return 1;
	if(c == '_') return 1;
	return 0;
}
char eisdigit(char c){
	if(c >= '0' && c <= '9') return 1;
	return 0;
}
char eiss(char c){
	if(c >= 'a' && c <= 'z') return 1;
  if(c >= 'A' && c <= 'Z') return 1;
  if(c == '_') return 1;
	if(c >= '0' && c <= '9') return 1;
	return 0;
}
char *GetValue(char *v){
	if(v[0] =='b') return bb;
	if(v[0] =='c') return c;
	return "";
}
void itpr(char *v, char **out_curr){

	char *in_curr, *trans;
	char *in_tmp;
	int end = 0;
	in_curr = v;
	while (!end){
//		printf("%s\n", in_curr);
		switch(in_curr[0]){
		case '\0':
//			printf("END\n");
			end=1;
			return;
		case '\\':
			in_curr ++;
			(*out_curr)[0] = in_curr[0];
			(*out_curr) ++;
			in_curr++;
			continue;
	  case '$':
			in_tmp = in_curr +1;
			if(eisletter(in_tmp[0])){
				in_tmp++;
				while(eiss(in_tmp[0])){
					in_tmp++;
				}
			
				trans = GetValue(in_curr + 1);
//				printf("get %s\n", trans);
				itpr(trans, out_curr);
				in_curr = in_tmp;
			}
			else{
				(*out_curr)[0] = in_curr[0];
				(*out_curr) ++;
				in_curr++;
			}
			continue;
		default:
			(*out_curr)[0] = in_curr[0];
			(*out_curr) ++;
			in_curr++;
		}
	}
}

main(){
	char *a = "123456789 $bb abcdefghi \\$bb";
	char d[100000];
	char *e = &d[0];
	itpr(a, &e);
	printf("%s\n",d);
}

