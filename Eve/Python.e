<ProgrammingLanguage

Python:ProgrammingLanguage

Python.CodeFile = "%|CmdArgs[0]|.@-N.%|EvalTime|.py"
Python.OutputFile = "%|CmdArgs[0]|.@-N.%|EvalTime|.output"

Python.Write._Eval = `
>@|CodeFile|
if @-N.TemplateFile {
@-N.Code = readfile @-N.TemplateFile
}
@-N.Code.Print
>stdout
`

Python.Run.CheckDone._Eval = `
if !isfile @@|OutputFile-N| {
%|Eve.CheckDone._Eval|
} else{
use @@|OutputFile-N|
}
`
Python.Run._Eval = `
@-N.Write.CheckDone
~perl @|CodeFile| > @|OutputFile|
<@|OutputFile|

`
Python.Exec._Eval = `
@-N.Write.CheckDone
~python @|CodeFile|
`
