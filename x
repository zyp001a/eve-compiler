20
Graduate.Year1.Fee: Count 10000
$$|_Eval|: 2

Xxx.sdaf.as.fd 22 a $|3 _Eval

$-L: 3

%Graduate.Year1.Done:  1 
@P[0]:  4
$|Fee.Count|: 10000
Value: 2
Name: L.P
Element: 2

$|_Args[0]|: 1
$|_Args[1]|: 20

$|_Args[0]|: 2
$|_Args[1]|: 
L.P[0]L.P[1]L.P[2]t/1.tGraduate.Year1._Eval = `^&-V
^`
L:Graduate
L.P : Graduate.Year1
Graduate.Year1 = 20
Graduate.Year1

Graduate.Year1.Fee.Count = 10000
Graduate.Year1.Fee._Eval = `
^Count $|Count|
^
`
L.P = 2
L.P.Print = `
1
`
L.P =[4,2,3]

L.P._Eval = `
^Graduate.Year1.Fee: ^Graduate.Year1.Fee
^\$\$|_Eval|: ^@$$|_Eval|

^
Xxx.sdaf.as.fd $$22 $@a $|3 $$_Eval

\$-L: $-L

\%Graduate.Year1.Done:  %|Graduate.Year1.Done| 
\@P[0]:  @|P[0]|
\$|Fee.Count|: $|Fee.Count|
Value: $-V
Name: $-N
Element: $-E[1]
^
`
if 1 {
L.P 1
}

L.P.X._Eval = `
^
\$|_Args[0]|: $|_Args[0]|
\$|_Args[1]|: $|_Args[1]|
^
`
L.P.X 1,Graduate.Year1
L.P.X 2

for L.P {
		L.P._Iterator.Print
}

CmdArgs[0].Print
>tmp
<<t/1.t
>stdout
