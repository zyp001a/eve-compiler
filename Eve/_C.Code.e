C.Code.Includes = `
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
`
C.Code.Functions = ``

C.Code = `
&|Includes|
&|Globals|
&|Functions|
main(){
&|Main|
}
`
C.AddInclude._Eval = `
@|Code.Includes| += &-A[0].Code
`
C.AddFunction._Eval = `
@|Code.Functions| += &-A[0].Code
`
