#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InlineRadixTreeChar.h"
main(){
	irtree *root;
	irtree_init(&root);
	irtree_putstr(root, "aaa", '\t');
	irtree_putstr(root, "abb", '\t');
	irtree_putstr(root, "abbb", '\t');


	int i = 0;
	irtree_print_code_param p;
	p.ind = 0;
	p.rtn_stmt = "return %d;";
	p.getchar_stmt = "egetc(fp)";
	p.endchar = '\t';
	p.endstr = "\\\t";
	irtree_print_code(root, &p);
	
}
