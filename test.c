#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct da{
	int l;
	void* arr;
} da;

main(){
	char a = 1;
	a++;
	char *b;
	b = malloc(2);
	while(a++<100){
		b[0] = a;
		printf("%s\n",b);
	}
}
