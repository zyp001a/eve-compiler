
test = "test-value"
test.Local1 = "test.Local1-value"
test.Local2 = "test.Local2-value"

test.sub.Local1 = "test.sub.Local1-value"
test.sub:parent
parent.Local1 = "parent.Local1-value"
parent.Local2 = "parent.Local2-value"


test.sub._Eval = `
^==========
Eval &-N
Macro Test
Global   %
\%|CmdArgs[0]|:     %|CmdArgs[0]|
\%|CmdArgs[0]-V|:   %|CmdArgs[0]-V|
\%|CmdArgs[0]-N|:   %|CmdArgs[0]-N|
\%|CmdArgs[0]-L|:   %|CmdArgs[0]-L|
Local    &
\&|Local1|:         &|Local1|
\&|Local2|:         &|Local2|
\&|Local1-N|:       &|Local1-N|
\&|Local2-N|:       &|Local2-N|
\&|_Args[0]|:       &|_Args[0]|
Superior @
\&\@|Local1|:        &@|Local1|
\&\@|Local2|:        &@|Local2|
\@|Local1|:         @|Local1|
\@|Local2|:         @|Local2|
\@|Local2-N|:       @|Local2-N|
Parent   $
\&\$|Local1|:        &$|Local1|
\&\$|Local2|:        &$|Local2|
\$|Local1|:         $|Local1|
\$|Local2|:         $|Local2|
Mix
\%\@|test.Local1|:   %@|test.Local1|
^
`
test.sub "ARGV[0]"

child:test.sub
child.Local1 = "child.Local1-value"
child
//getenv