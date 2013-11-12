/*
 * main.c file
 */
 
#include "Sociaty.h"
#include "Parser.h"
#include "Lexer.h" 

Sociaty ns;
char *eve = "Eve";
FILE *out = stdout;
char *const_name = "EveConst";
int const_count = 0;
char path[] = "ignore:./:/home/zyp/dna/core/src/Eve/";

 
int main(int argc, char **argv)
{
	FILE *fp;
	char *str;
	if(argc == 1)
		fp = stdin;
	else
		fp = fopen(argv[1], "r");
	str = ereadfile(fp);
	fclose(fp);
//	char *a = estrcent("'a'");
//	printf("%s\n",a);
///*	
	Sociaty_Create();
	ParseExpressionFromString(str);
//*/	

	return 0;
}
