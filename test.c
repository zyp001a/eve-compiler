
#include "Role.h"
main(){
	char a[100];
//	scanf("\"%s\"",a);
//	printf("%s\n",a);
	Role *r;
	r = Role_New();
	RoleHash_Put(r->Subs, "eve", r);

}
