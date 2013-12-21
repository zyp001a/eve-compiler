#include "Common.h"
#include "Database.h"
#include "Reader.h"
#include "Eval.h"
#include "Platform.h"
int main(int argc, char **argv)
{
	
	if(argc < 2){
		fprintf("Please specifiy db name");
		exit(1);
	}
	TableParam *p;
	char dump[MAX_BLOCK_SIZE];
	char *dp = &dump[0];
	while((c = egetc(stdin)) != '\0'){
		*dp = c;
		dp ++;
	}
	*dp = '\0';
	dp = &dump[0];
	ReadFile(stdin, dp);
	return 0;
}

