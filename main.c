/*
 * main.c file
 */
 
#include "Sociaty.h"
#include "Parser.h"
#include "Lexer.h" 
//#define EDEBUG
Sociaty ns;
char *eve = "Eve"; //common ansester
char *evalstr = "Eval"; //evaluate title name
char *valuestr = "Value";
char *namestr = "Name";
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
//	char *a = estrafter("asdf.asdDDDe13.dda'",'.');
//	printf("%s\n",a);
///*	
	Sociaty_Create();
	ParseExpressionFromString(str);
//*/	

	return 0;
}
