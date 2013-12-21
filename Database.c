#include "Database.h"
extern char db_path[];

void Database_ReadTableFile(FILE *fp){
	char str[MAX_BLOCK_SIZE];
	char db[MAX_FILE_NAME];
	char db_info[MAX_FILE_NAME];
	int size;
	char *p;
	if( (fgets(str, MAX_BLOCK_SIZE, fp)) != NULL ){
		strcpy(db, db_path);
		strcat(db, str);
		strcpy(db_info, db);
		strcat(db_info,".info");
	}
	if( (fgets(str, MAX_BLOCK_SIZE, fp)) != NULL ){
		p = &str[0];
		while(*p != '\0'){
			switch(*p){
			case 'i':
				break;
			case 'l':
				break;
			case 'f':
				break;
			case 'c':
				break;
			case 's':
				sscanf(p, "%d", &size);
				break;

			}
			p++;
		}
	}
	
}
void WriteDatabase(Role *r){
//	Role_Print(r);
}

