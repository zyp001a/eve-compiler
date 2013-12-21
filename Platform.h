#ifndef _EPLATFORM
#define _EPLATFORM
#include <stdio.h>
#define egetc _IO_getc_unlocked
char erename(char *, char*);
char eisdir(char *);
char eisfile(char *);
char isfrompipe(void);
char echmod(char *, char []);
#endif
