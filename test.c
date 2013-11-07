#include <stdio.h>
#include <stdlib.h>
main(){
	int *a;
	int *b;
	a= malloc(2*sizeof(int));
	a[0]=1;
	a[1]=2;
	b = a + 1;
	printf("%d,%d,%d\n",a[0],a[1],*b);
}
