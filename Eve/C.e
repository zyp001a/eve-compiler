<ProgrammingLanguage
<_C.Grammar
<_C.Hash


C:ProgrammingLanguage


C.ExecuteFile = "%|CmdArgs[0]|.@-N.x"
C.CodeFile = "%|CmdArgs[0]|.@-N.c"
C.OutputFile = "%|CmdArgs[0]|.@-N.output"

C.Write._Eval = `
>@|CodeFile|
@-N.Code.Print
>stdout
`

C.Compile._Eval = `
@-N.Write.CheckDone
~gcc @|CodeFile| -o @|ExecuteFile| -I%|CIncludePath|
`

C.Run.CheckDone._Eval = `
if !isfile @@|OutputFile-N| {
%|Eve.CheckDone._Eval|
} else{
use @@|OutputFile-N|
}
`
C.Run._Eval = `
@-N.Compile.CheckDone
~./@|ExecuteFile| > @|OutputFile|
<@|OutputFile|

`
