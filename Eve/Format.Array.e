Use "Common"
Format.Array.Print = `$_Name.Iterator.Print `
Format.Array._Eval = `
$_Name.IsStart = 1
For $_Name.Iterator $_Name \`
	IfElse $_Name.IsStart '$_Name.IsStart = ""' '^$Separator^'
	$Print
\` 
`

a:Format.Array

a.Print=`~xxx
$$Print
~xxx`
a.Separator=";
"

Add a 1
Add a 2
Add a 3

a
