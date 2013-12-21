<ProgrammingLanguage
<_C.Grammar
<_C.Hash
<_C.Code

C:ProgrammingLanguage


C.ExecuteFile = "%|CmdArgs[0]|.@-N.%|EvalTime|.x"
C.CodeFile = "%|CmdArgs[0]|.@-N.%|EvalTime|.c"
C.OutputFile = "%|CmdArgs[0]|.@-N.%|EvalTime|.output"
C.TemplateFile = "_@-N.c"
C.Write._Eval = `
>@|CodeFile|
if isfile @-N.TemplateFile {
@-N.Code = readfile @-N.TemplateFile
}
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
C.Exec._Eval = `
@-N.Compile.CheckDone
~./@|ExecuteFile|
`
