Eve._Eval = `^$-V
^`
L:Graduate
L.P : Graduate.Year1
Graduate.Year1 = 20
Graduate.Year1
Graduate.Year1.Fee.Count = 10000
Graduate.Year1.Fee._Eval = `
^Count &|Count|
^
`
L.P = 2
L.P.Print = `

`
L.P._Eval = `
Graduate.Year1.Fee
^$$22 $@a $|3 $$_Eval
^
^Parent Eval: ^ $$|_Eval| 
^Graduate.Year1:  %|Graduate.Year1| 
^
^Superior:  @|P|
^
^inherence $|Fee.Count|
^
^Value: $-V
^
^Name: $-N
^
`
L.P



