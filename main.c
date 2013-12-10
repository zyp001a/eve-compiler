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

char path[] = "ignore:./:/zyp/eve/compiler/Eve/:/zyp/eve/compile/MachineLearning/:/zyp/eve/compiler/Biology/";
char cincludepath[] = "/zyp/eve/compiler/Eve/C";

 
int main(int argc, char **argv)
{
	ns.Out = stdout;
//	ns.In = stdin;
//	ns.Err = stderr;
	ns.Step = 1;
	FILE *fp;
	Role *r;
	char *str;
	char line[32768];
	int li,c;
	char errfile[MAX_FILE_NAME];
	int i;
	RoleArray *ra;
	Sociaty_Create();
	
	if(argc == 1){
		printf("=======\n");
		printf("Eve language: a OOP based macro language\n");
    printf("Version: %s\n", version);
		printf("Original designed by setupX\n");
		printf("=======\n");
		printf("Press Ctrl+D to exit\n");
		strcpy(ns.ErrFile,".eve.log");
		ns.Err = fopen(ns.ErrFile,"a");
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
		strcpy(ns.ErrFile, ns.ProgramFile);
		strcat(ns.ErrFile, ".log");
		ns.Err=fopen(ns.ErrFile, "w");
//		ns.Err = stderr;
		
		ParseExpressionFromString("<Basic\n");
		r = Sociaty_RoleEmploy(ns.Root, "CmdArgs");
		RoleArray_Init(&ra);
		ra->Length = ra->Size = argc-1;
		ra->Values = (Role**)malloc(ra->Size*sizeof(Role*));
		for(i=0; i<ra->Length; i++){
			ra->Values[i] = Role_New();
			ra->Values[i]->_Value = argv[i+1];
		}
		Sociaty_RoleSetElements(r, ra);


		r = Sociaty_RoleEmploy(ns.Root, "CIncludePath");
		r->_Value = estrdup(cincludepath);

		ParseExpressionFromFp(fp);

//*/	
	}
	fclose(ns.Err);

	return 0;
}
