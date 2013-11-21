Use "Common"

Lang.C._Eval = `
$$_Value
_SetOut "a.c"
_Print

$Includes

$Structs

$Functions

$MainDef
$Main
$MainEnd

_EndPrint
_SetOut ""
_Run gcc a.c
_Run ./a.out
`

Lang.C.Includes = `
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
`

Lang.C.Structs = ``
Lang.C.Structs

Lang.C.Functions = ``

Lang.C.MainDef = `
main(){
`

Lang.C.Main = `$_Value`

Lang.C.MainEnd = `}`


