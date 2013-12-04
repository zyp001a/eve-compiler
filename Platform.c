#include "Platform.h"

#ifdef __unix__
#include <unistd.h> 
char eisfile(char *path){
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
	struct stat buf;
	stat(path, &buf);
	return S_ISDIR(buf.st_mode);
}
#endif
