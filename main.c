/*
 * main.c file
 */
 
#include "Sociaty.h"
#include "Parser.h"
#include "Lexer.h" 

 
int main(int argc, char **argv)
{
	FILE *fp;
	char *str;
//	Expression *e = NULL;
	if(argc == 1)
		fp = stdin;
	else
		fp = fopen(argv[1], "r");
	str = ereadfile(fp);
	fclose(fp);
//	strcat(str,"\n");
//	sprintf(str, "%s\n",str);

	Sociaty_Create();
//	char *a;
//	estrdup(a, str);
//	printf("%s\n",str);
	ParseExpressionFromString(str);

//	char test[]=" 4 + 2*10 + 3*( 5 + 1 )";
//	int result = 0;
 
//	e = getAST(test);
 
//	result = evaluate(e);
 
//	printf("Result of '%s' is %d\n", test, result);
 
//	deleteExpression(e);
 
	return 0;
}
