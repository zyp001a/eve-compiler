#include "Platform.h"
/*
	I'm not sure what io.h, unistd.h and stat.h belongs to, POSXI or GNU or UNIX, this need to be check later.
 */
#ifdef __unix__

char isfrompipe(){
	return !isatty(fileno(stdin));
}
char erename(char *oldname, char* newname){
	return (char)rename( (const char*)oldname , (const char *)newname );
}
#endif

#ifdef __unix__
#include <unistd.h> 
char eisfile(char *path){
	if(path == NULL) return 0;
	if( access( path, F_OK ) != -1 ) {
    return !eisdir(path);
	} else {
		return 0;
	}
}
#endif

#ifdef __GNUC__
#include <sys/stat.h>
char eisdir(char *path){
	if(path == NULL) return 0;
	struct stat buf;
	stat(path, &buf);
	return S_ISDIR(buf.st_mode);
}
char echmod(char *f, char mod[]){
	int i = strtol(mod, 0, 8);
	return chmod(f, i);
}
#endif
