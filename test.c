#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct da{
	int l;
	void* arr;
} da;
main(){
	da a;

	char **x =(char**)malloc(10*sizeof(char*));
	x[0] = strdup("xxxxx");
	x[1]  = strdup("xxxxx");
	a.arr = x;
	printf("%s\t%s\n", (char**)a.arr[0], (char**)a.arr[1]);
}
