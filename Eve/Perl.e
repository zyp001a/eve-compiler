<ProgrammingLanguage

Perl:ProgrammingLanguage

Perl.CodeFile = "%|CmdArgs[0]|.@-N.%|EvalTime|.pl"
Perl.OutputFile = "%|CmdArgs[0]|.@-N.%|EvalTime|.output"

Perl.Write._Eval = `
>@|CodeFile|
if @-N.TemplateFile {
@-N.Code = readfile @-N.TemplateFile
}
@-N.Code.Print
>stdout
`

Perl.Run.CheckDone._Eval = `
if !isfile @@|OutputFile-N| {
%|Eve.CheckDone._Eval|
} else{
use @@|OutputFile-N|
}
`
Perl.Run._Eval = `
@-N.Write.CheckDone
~perl @|CodeFile| > @|OutputFile|
<@|OutputFile|

`
Perl.Exec._Eval = `
@-N.Write.CheckDone
~perl @|CodeFile|
`
