b1._Eval = `
^b1
^
`
b2._Eval = `
^b2
^
`

a.Do._Eval = `
b1.CheckDone
b2.CheckDone
^$|_Args[0]| - a.Do
^
`
a.Do 1
a.Do 2
