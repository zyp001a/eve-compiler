C:Eve
Use CEnv
C.Out = CEnv.C;
C=[
$WriteCode
CEnv
]
C.Eval=[
@Eval($Value);
$MainCodes.Add($RawValue);
]
C.WriteCode={
$Includes
$Structs
$Functions
$MainHead
$MainCodes
$MainTail
}
C.Includes = {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
}
C.Structs = {}
C.Functions = {}
C.MainHead = {
void main()\{
}
C.MainTail = {
\}
}





