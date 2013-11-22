/*
 * main.c file
 */
 
#include "Sociaty.h"
#include "Parser.h"
#include "Lexer.h" 
//#define EDEBUG
Sociaty ns;
char *eve = "Eve"; //common ansester
char *evalstr = "_Eval"; //evaluate title name
char *argsstr = "_Args";
char *valuestr = "_Value";
char *namestr = "_Name";
char *superstr = "_Super";
FILE *out = stdout;
char *prefix = "";
int const_count = 0;
//char *const_name = "EveConst";

char path[] = "ignore:./:/zyp/eve/compiler/Eve/";

 
int main(int argc, char **argv)
{
	FILE *fp;
	char *str;
	Sociaty_Create();
	if(argc == 1)
		fp = stdin;
	else
		fp = fopen(argv[1], "r");
	//fclose(fp);
//	char *a = estrafter("asdf.asdDDDe13.dda'",'.');
//	printf("%s\n",a);
///*	

	ParseExpressionFromFp(fp);
//	Sociaty_WriteMembers();
//*/	

	return 0;
}
