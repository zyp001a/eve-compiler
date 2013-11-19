Use "Common"

a=`_Run echo a`

a.Print
a
b=`_Run echo b`
b.Print

b._Eval=`
$$_Eval
_Print
bb
_EndPrint
`
b