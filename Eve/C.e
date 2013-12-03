<ProgrammingLanguage
C:ProgrammingLanguage

C.Definition = `
^&|Type| &|Name|;
^
`
C.Structure = `
^typedef struct &|Name| {
^
for &-N.Definitions {
		&|Definitions-I|.Print
}
^} $|Name|;
^
`


C.ExecuteFile = "%|CmdArgs[0]|.@-N.x"
C.CodeFile = "%|CmdArgs[0]|.@-N.c"


C.Write._Eval = `
>@|CodeFile|
@-N.Code.Print
>stdout
`

C.Compile._Eval = `
@-N.Write.CheckDone
~gcc @|CodeFile| -o @|ExecuteFile| -I%|CIncludePath|
`

C.Run._Eval = `
@-N.Compile.CheckDone
~./@|ExecuteFile|
`
