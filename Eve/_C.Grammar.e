C.Definition._EvalArgs = `
if &-A[0] { &-N.Name = &-A[0]; }
if &-A[1] { &-N.Type.Name = &-A[1]; }
if &-A[2] { &-N.Type.Size = &-A[2]; }
if &-A[3] { &-N.Type.IsUnsigned = &-A[3]; }
`
C.Definition.Type.Size = 0
C.Definition.Print._Eval = `
if @|Type.IsUnsigned-N| {
^unsigned ^
}
if @|Type.Size-N| {
^@|Type.Name| @|Name|[@|Type.Size|];
^
} else {
^@|Type.Name| @|Name|;
^
}
`
//C.Struct.Definitions._Iterator : C.Definition
C.Struct.Type = "@|Name|"
C.Struct.Print._Eval = `
^typedef struct @|Name| @|Type|;
struct @|Name|{
^
for @|Definitions-N| {
^	^\&-I.Print
}
^};
^
`


C.Function.Code = `
void @-N(){
  @|Block|
}
`
C.Process.Invoke._Eval = `
`

