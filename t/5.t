a._Eval = `Print
a:$a
Value:$_Value
Name:$_Name
EndPrint`
a.b="bbb"
a.a = 'aaa'
a
b:a
b.a = '1'
b._Eval = `

Print
$b
xxx
EndPrint`
b