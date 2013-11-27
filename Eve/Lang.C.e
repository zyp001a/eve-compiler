Use "Common"

Lang.C._Eval = `
>a.c
^
$|Code|
^
>stdout
~gcc a.c
~./a.out

`

EasyC : Lang.C
EasyC.Code = 
`
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
$|Func|
main(){
$|Main|
}

`




