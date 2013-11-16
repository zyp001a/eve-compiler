C._Eval = `
SetOut "a.c"
Print
$Includes
$Structs
$Functions
$MainDef
$MainBody
$MainEnd
EndPrint
SetOut ""
Run gcc a.c
Run ./a.out

`
C.Includes = `
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
`
C.Structs = ``
C.Functions = ``
C.MainDef = `
main(){
`
C.MainBody = `$_Value`
C.MainEnd = `}`


