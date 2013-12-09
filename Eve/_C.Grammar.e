C.Definition.Type.Size = 0
C.Definition.Print._Eval = `
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
^	^&-I.Print
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

