#ifndef SYMTABLE
#define SYMTABLE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct symrec
{
  char *name;             /* name of symbol          */
  struct symrec *next;    /* link field              */
};
typedef struct symrec symrec;
symrec *sym_table = (symrec *)0;
symrec * putsym ( char *sym_name );

symrec * getsym ( char *sym_name );
void write_symtable();
#endif
