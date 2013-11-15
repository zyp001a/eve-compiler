#ifndef _ACTION
#define _ACTION
#include "Common.h"
#include "Role.h"
#include "Sociaty.h"



char* Eval(Index i);
char* GetPath(char *);
//Lang GetLang(char *);
char GetFlag(char *);

char* GetTitleName(Role *r);
char* GetTitleValue(Role *r, char *title, int len);
char *GetTitleValueLevel1(Role *pr, char *title, int len);

char* GetTitleValueFromSuperiors(Role *r, char *title, int len);
char* GetEvalValue(Role *r);
void InterpretValue(Role *r, char *value, char **result);


#endif
