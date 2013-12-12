#ifndef _EDATABASE
#define _EDATABASE
#include "Common.h"
#include "Eval.h"
#include "Platform.h"
#define CHECK_END_LENGTH 2
#define CHECK_START_LENGTH 5
char SeekToStart(FILE *fp, char *str);
void ParseFileAndSendToDatabase(Role *r);
#endif
