
#include "Role.h"
#include <limits.h>
long* f(){
	long bf[12345678];
	long *a;
	a = &bf[0];
	return a;
}
main(){
	char a[100];
//	scanf("\"%s\"",a);
//	printf("%s\n",a);
	Role *r;
	char *s;
	long *l;
	int i;
	for(i=0;i<INT_MAX;i++){
		printf("%d\n",i);
		l = f();
	}
	printf("%s\n",s);
	r = Role_New();
	RoleHash_Put(r->Subs, "eve", r);

}
