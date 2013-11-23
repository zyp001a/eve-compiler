Use "Common"

Array.Print = `
print $|_Name|.Iterator
`
Array._Eval = `
$|_Name|.IsStart = 1
for $|_Name|.Iterator $|_Name| {
	ifelse $|_Name|.IsStart {$|_Name|.IsStart = ""} {^$|Separator|^}
	$|Print|
}
`
a:Array

a.Print=`^xxx^$$|Print|^xxx^`
a.Separator=";
"
add a 1
add a 2
add a 3

a
