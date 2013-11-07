#ifndef SYMHIERACHY
#define SYMHIERACHY
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _Bool boolean
void Sociaty_Create();
void Sociaty_Write();
void Sociaty_AddPCRelation(char *parent_name, char *child_name);
void Sociaty_AddSSRelation(char *superior_name, char *subordinate_name);
#endif
