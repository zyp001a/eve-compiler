/*
 * main.c file
 */
 
#include "Sociaty.h"
#include "Parser.h"
#include "Lexer.h" 
#include <signal.h>
//#define EDEBUG
Sociaty ns;
char *eve = "Eve"; //common ansester
char *evalstr = "_Eval"; //evaluate title name
char *argsstr = "_Args";
char *valuestr = "_Value";
char *namestr = "_Name";
char *elementstr = "_Element";
//char *superstr = "_Super";
char *prefix = "";
int const_count = 0;
char version[] = "c0.1";
//char *const_name = "EveConst";

char path[] = "ignore:./:/zyp/eve/compiler/Eve/";
char cincludepath[] = "/zyp/eve/compiler/Eve/C";

 
int main(int argc, char **argv)
{
	ns.Out = stdout;
	ns.Step = 1;
	FILE *fp;
	Role *r;
	char *str;
	char line[32768];
	int li,c;
	char errfile[MAX_FILE_NAME];
	int ri;
	
	Sociaty_Create();
	
	if(argc == 1){
		printf("=======\n");
		printf("Eve language: a OOP based macro language\n");
    printf("Version: %s\n", version);
		printf("Original designed by setupX\n");
		printf("=======\n");
		printf("Press Ctrl+D to exit\n");
		
		ns.Err = fopen(".eve.log","a");
		ParseExpressionFromString("<Basic\n");
		li = 0;
		printf("~");
		while(c=getchar()){
			if(c == EOF){
				break;
			}
			else if (c == '\n'){
				printf("~");
				line[li] = '\n';
				line[li+1] = '\0';
				li = 0;
				ParseExpressionFromString(line);
			}
			else{
				line[li++] = c;
			}
		}
	}
	else{
		strcpy(ns.ProgramFile, argv[1]);
		
		fp = fopen(ns.ProgramFile, "r");
		strcpy(errfile, ns.ProgramFile);
		strcat(errfile, ".log");
		ns.Err=fopen(errfile, "w");

		ParseExpressionFromString("<Basic\n");
		ri = Sociaty_AddNewRole("CmdArgs");
		Sociaty_RoleAssignArrayByStringArray(ri, argc-1, argv+1);
		ri = Sociaty_AddNewRole("CIncludePath");
		strcpy(Sociaty_GetRole(ri)->_Value, cincludepath);

		ParseExpressionFromFp(fp);

//*/	
	}
	fclose(ns.Err);
	return 0;
}
