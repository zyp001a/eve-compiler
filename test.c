/*
 * main.c file
 */
 
#include "Sociaty.h"
#include "Parser.h"
#include "Lexer.h" 
#include "Database.h"
#include <signal.h>
//#define EDEBUG
Sociaty ns;
char *eve = "Eve"; //common ansester
char *evalstr = "_Eval"; //evaluate title name
char *argsstr = "_Args";
char *evalargsstr = "_EvalArgs";
char *valuestr = "_Value";
char *namestr = "_Name";
char *elementstr = "_Element";
//char *superstr = "_Super";
char *prefix = "";
int const_count = 0;
char version[] = "v0.2.1";

//char *const_name = "EveConst";
#ifdef ETEST
char path[] = "ignore:./:/zyp/eve/compiler/Eve/:/zyp/eve/compile/MachineLearning/:/zyp/eve/Biology/";
char cincludepath[] = "/zyp/eve/compiler/Eve/C/";
char evehome[]= "/zyp/eve/compiler/Eve";
char biologyhome[]= "/zyp/eve/Biology";
#else
char path[] = "ignore:./:/home/zyp/lib/Eve/:/home/zyp/lib/Biology/";
char cincludepath[] = "/home/zyp/lib/Eve/C/";
char evehome[]= "/home/zyp/lib/Eve/";
char biologyhome[]= "/home/zyp/lib/Biology/";
#endif
char db_path[] = "/home/zyp/Database/";
char is_storetable = 0;
 
int main(int argc, char **argv)
{
	ns.Out = stdout;
//	ns.In = stdin;
//	ns.Err = stderr;
	ns.Step = 1;
	FILE *fp;
	FILE *tmpstdin;
	Role *r;
	char *str;
	char tmpfile[MAX_FILE_NAME];
	int i,li;
	RoleArray *ra;
	int c;
	
	Sociaty_Create();
	if(argc == 1){
		strcpy(ns.ProgramFile, ".eve");		
	}
	else if (!strcmp(argv[1], "store")){
		if(argc >=3){
			is_storetable = 1;
			strcpy(ns.ProgramFile, db_path);
			strcat(ns.ProgramFile, argv[2]);
			strcat(ns.ProgramFile, ".e");
			if(eisfile(ns.ProgramFile)){
				strcpy(tmpfile, ns.ProgramFile);
				strcat(tmpfile, ".backup");
				erename(ns.ProgramFile, tmpfile);
			}
			fp = fopen(ns.ProgramFile, "w");
			while ((c = egetc(stdin)) != '\0'){
				if(c == EOF) break;
				fprintf(fp, "%c", c);
			}
			fclose(fp);
		}
		else{
			eerror("please specify a table name for storetable");
			exit(1);
		}
	}
	else{
		strcpy(ns.ProgramFile, argv[1]);				
	}


	strcpy(ns.ErrFile, ns.ProgramFile);
	strcat(ns.ErrFile, ".log");
	strcpy(ns.ExecFile, ns.ProgramFile);
  strcat(ns.ExecFile, ".ec");
	ns.Err=fopen(ns.ErrFile, "w");	
	ns.Exec=fopen(ns.ExecFile, "w");
	echmod(ns.ExecFile, "0775");

	if(argc == 1){
		if(!isfrompipe()){
			printf("=======\n");
			printf("Eve language: a OOP based macro language\n");
			printf("Version: %s\n", version);
			printf("Original designed by setupX\n");
			printf("=======\n");
			printf("Press Ctrl+D to exit\n");
			li = 0;
			printf("~");
			ParseExpressionFromStdin("~");
		}
		else{
			ParseExpressionFromStdin("");
		}
	}
	else{
		fp = fopen(ns.ProgramFile, "r");
		ParseExpressionFromFp(fp);
		
		fclose(fp);
//*/	
	}
	fclose(ns.Err);
	fclose(ns.Exec);
/*
	char *torun = RoleHash_Get(ns.Root->Subs, "ToRun")->_Value;
//	printf("%c\n",egetc(stdin));


	if(torun!=NULL)
		system(torun);
*/
/*

*/
	return 0;
}
