Use "Common"
Lang.C._Eval = `
$_Value
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

Lang.C.Includes = `
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
`
Lang.C.Structs = ``
Lang.C.Functions = ``
Lang.C.MainDef = `
main(){
`
Lang.C.MainBody = `$_Value`
Lang.C.MainEnd = `}`


