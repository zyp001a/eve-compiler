a._Eval = `_Print
a:$a
Value:$_Value
Name:$_Name
_EndPrint`
a.b="bbb"
a.a = 'aaa'
a
b:a
b.a = '1'
b._Eval = `

_Print
$b
xxx
_EndPrint`
b