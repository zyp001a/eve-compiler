20
Index:    0
Name:     Eve
Value:    
Target:   -1
Subordinates: 2	Eve.Print	Eve.CheckDone
Superiors: 0
Parents: 0
Children: 12	Eve.Print	Eve.Print._Eval	Eve.CheckDone	Eve.CheckDone._Eval	check	check._Eval	Graduate	Graduate.Year1	Graduate.Year1._Eval	L	L.P	Graduate.Year1.Done
=====================
Index:    1
Name:     Eve.Print
Value:    
Target:   -1
Subordinates: 1	Eve.Print._Eval
Superiors: 1	Eve
Parents: 1	Eve
Children: 0
=====================
Index:    2
Name:     Eve.Print._Eval
Value:    
^@-V^

Target:   -1
Subordinates: 0
Superiors: 1	Eve.Print
Parents: 1	Eve
Children: 0
=====================
Index:    3
Name:     Eve.CheckDone
Value:    
Target:   -1
Subordinates: 1	Eve.CheckDone._Eval
Superiors: 1	Eve
Parents: 1	Eve
Children: 0
=====================
Index:    4
Name:     Eve.CheckDone._Eval
Value:    
if not @-N.Done { @-N; }

Target:   -1
Subordinates: 0
Superiors: 1	Eve.CheckDone
Parents: 1	Eve
Children: 0
=====================
Index:    5
Name:     check
Value:    
Target:   -1
Subordinates: 1	check._Eval
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    6
Name:     check._Eval
Value:    
for check._Args {
		check._Args._Iterator.CheckDone
}

Target:   -1
Subordinates: 0
Superiors: 1	check
Parents: 1	Eve
Children: 0
=====================
Index:    7
Name:     Graduate
Value:    
Target:   -1
Subordinates: 1	Graduate.Year1
Superiors: 0
Parents: 1	Eve
Children: 1	L
=====================
Index:    8
Name:     Graduate.Year1
Value:    20
Target:   -1
Subordinates: 2	Graduate.Year1._Eval	Graduate.Year1.Done
Superiors: 1	Graduate
Parents: 1	Eve
Children: 1	L.P
=====================
Index:    9
Name:     Graduate.Year1._Eval
Value:    ^&-V
^
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    10
Name:     L
Value:    
Target:   -1
Subordinates: 1	L.P
Superiors: 0
Parents: 2	Eve	Graduate
Children: 0
=====================
Index:    11
Name:     L.P
Value:    
Target:   -1
Subordinates: 0
Superiors: 1	L
Parents: 2	Eve	Graduate.Year1
Children: 0
=====================
Index:    12
Name:     Graduate.Year1.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Graduate.Year1.Fee: Count 10000
Index:    0
Name:     Eve
Value:    
Target:   -1
Subordinates: 2	Eve.Print	Eve.CheckDone
Superiors: 0
Parents: 0
Children: 23	Eve.Print	Eve.Print._Eval	Eve.CheckDone	Eve.CheckDone._Eval	check	check._Eval	Graduate	Graduate.Year1	Graduate.Year1._Eval	L	L.P	Graduate.Year1.Done	Graduate.Year1.Fee	Graduate.Year1.Fee.Count	Graduate.Year1.Fee._Eval	L.P.Print	L.P[0]	L.P[1]	L.P[2]	L.P._Eval	L.P._Args	L.P._Args[0]	Graduate.Year1.Fee.Done
=====================
Index:    1
Name:     Eve.Print
Value:    
Target:   -1
Subordinates: 1	Eve.Print._Eval
Superiors: 1	Eve
Parents: 1	Eve
Children: 0
=====================
Index:    2
Name:     Eve.Print._Eval
Value:    
^@-V^

Target:   -1
Subordinates: 0
Superiors: 1	Eve.Print
Parents: 1	Eve
Children: 0
=====================
Index:    3
Name:     Eve.CheckDone
Value:    
Target:   -1
Subordinates: 1	Eve.CheckDone._Eval
Superiors: 1	Eve
Parents: 1	Eve
Children: 0
=====================
Index:    4
Name:     Eve.CheckDone._Eval
Value:    
if not @-N.Done { @-N; }

Target:   -1
Subordinates: 0
Superiors: 1	Eve.CheckDone
Parents: 1	Eve
Children: 0
=====================
Index:    5
Name:     check
Value:    
Target:   -1
Subordinates: 1	check._Eval
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    6
Name:     check._Eval
Value:    
for check._Args {
		check._Args._Iterator.CheckDone
}

Target:   -1
Subordinates: 0
Superiors: 1	check
Parents: 1	Eve
Children: 0
=====================
Index:    7
Name:     Graduate
Value:    
Target:   -1
Subordinates: 1	Graduate.Year1
Superiors: 0
Parents: 1	Eve
Children: 1	L
=====================
Index:    8
Name:     Graduate.Year1
Value:    20
Target:   -1
Subordinates: 3	Graduate.Year1._Eval	Graduate.Year1.Done	Graduate.Year1.Fee
Superiors: 1	Graduate
Parents: 1	Eve
Children: 1	L.P
=====================
Index:    9
Name:     Graduate.Year1._Eval
Value:    ^&-V
^
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    10
Name:     L
Value:    
Target:   -1
Subordinates: 1	L.P
Superiors: 0
Parents: 2	Eve	Graduate
Children: 0
=====================
Index:    11
Name:     L.P
Value:    2
Target:   -1
Subordinates: 3	L.P.Print	L.P._Eval	L.P._Args
Superiors: 1	L
Parents: 2	Eve	Graduate.Year1
Children: 0
=====================
Index:    12
Name:     Graduate.Year1.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    13
Name:     Graduate.Year1.Fee
Value:    
Target:   -1
Subordinates: 3	Graduate.Year1.Fee.Count	Graduate.Year1.Fee._Eval	Graduate.Year1.Fee.Done
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    14
Name:     Graduate.Year1.Fee.Count
Value:    10000
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    15
Name:     Graduate.Year1.Fee._Eval
Value:    
^Count $|Count|
^

Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    16
Name:     L.P.Print
Value:    
1

Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    17
Name:     L.P[0]
Value:    4
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    18
Name:     L.P[1]
Value:    2
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    19
Name:     L.P[2]
Value:    3
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    20
Name:     L.P._Eval
Value:    
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

Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    21
Name:     L.P._Args
Value:    
Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    22
Name:     L.P._Args[0]
Value:    1
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    23
Name:     Graduate.Year1.Fee.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
$$|_Eval|: 2

Xxx.sdaf.as.fd 22 a $|3 _Eval

$-L: 3

%Graduate.Year1.Done:  1 
@P[0]:  4
$|Fee.Count|: 10000
Value: 2
Name: L.P
Element: 2
Index:    0
Name:     Eve
Value:    
Target:   -1
Subordinates: 2	Eve.Print	Eve.CheckDone
Superiors: 0
Parents: 0
Children: 24	Eve.Print	Eve.Print._Eval	Eve.CheckDone	Eve.CheckDone._Eval	check	check._Eval	Graduate	Graduate.Year1	Graduate.Year1._Eval	L	L.P	Graduate.Year1.Done	Graduate.Year1.Fee	Graduate.Year1.Fee.Count	Graduate.Year1.Fee._Eval	L.P.Print	L.P[0]	L.P[1]	L.P[2]	L.P._Eval	L.P._Args	L.P._Args[0]	Graduate.Year1.Fee.Done	L.P.Done
=====================
Index:    1
Name:     Eve.Print
Value:    
Target:   -1
Subordinates: 1	Eve.Print._Eval
Superiors: 1	Eve
Parents: 1	Eve
Children: 0
=====================
Index:    2
Name:     Eve.Print._Eval
Value:    
^@-V^

Target:   -1
Subordinates: 0
Superiors: 1	Eve.Print
Parents: 1	Eve
Children: 0
=====================
Index:    3
Name:     Eve.CheckDone
Value:    
Target:   -1
Subordinates: 1	Eve.CheckDone._Eval
Superiors: 1	Eve
Parents: 1	Eve
Children: 0
=====================
Index:    4
Name:     Eve.CheckDone._Eval
Value:    
if not @-N.Done { @-N; }

Target:   -1
Subordinates: 0
Superiors: 1	Eve.CheckDone
Parents: 1	Eve
Children: 0
=====================
Index:    5
Name:     check
Value:    
Target:   -1
Subordinates: 1	check._Eval
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    6
Name:     check._Eval
Value:    
for check._Args {
		check._Args._Iterator.CheckDone
}

Target:   -1
Subordinates: 0
Superiors: 1	check
Parents: 1	Eve
Children: 0
=====================
Index:    7
Name:     Graduate
Value:    
Target:   -1
Subordinates: 1	Graduate.Year1
Superiors: 0
Parents: 1	Eve
Children: 1	L
=====================
Index:    8
Name:     Graduate.Year1
Value:    20
Target:   -1
Subordinates: 3	Graduate.Year1._Eval	Graduate.Year1.Done	Graduate.Year1.Fee
Superiors: 1	Graduate
Parents: 1	Eve
Children: 1	L.P
=====================
Index:    9
Name:     Graduate.Year1._Eval
Value:    ^&-V
^
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    10
Name:     L
Value:    
Target:   -1
Subordinates: 1	L.P
Superiors: 0
Parents: 2	Eve	Graduate
Children: 0
=====================
Index:    11
Name:     L.P
Value:    2
Target:   -1
Subordinates: 4	L.P.Print	L.P._Eval	L.P._Args	L.P.Done
Superiors: 1	L
Parents: 2	Eve	Graduate.Year1
Children: 0
=====================
Index:    12
Name:     Graduate.Year1.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    13
Name:     Graduate.Year1.Fee
Value:    
Target:   -1
Subordinates: 3	Graduate.Year1.Fee.Count	Graduate.Year1.Fee._Eval	Graduate.Year1.Fee.Done
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    14
Name:     Graduate.Year1.Fee.Count
Value:    10000
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    15
Name:     Graduate.Year1.Fee._Eval
Value:    
^Count $|Count|
^

Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    16
Name:     L.P.Print
Value:    
1

Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    17
Name:     L.P[0]
Value:    4
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    18
Name:     L.P[1]
Value:    2
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    19
Name:     L.P[2]
Value:    3
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    20
Name:     L.P._Eval
Value:    
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

Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    21
Name:     L.P._Args
Value:    
Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    22
Name:     L.P._Args[0]
Value:    1
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    23
Name:     Graduate.Year1.Fee.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    24
Name:     L.P.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================

$|_Args[0]|: 1
$|_Args[1]|: L.P.X._Args
Index:    0
Name:     Eve
Value:    
Target:   -1
Subordinates: 2	Eve.Print	Eve.CheckDone
Superiors: 0
Parents: 0
Children: 30	Eve.Print	Eve.Print._Eval	Eve.CheckDone	Eve.CheckDone._Eval	check	check._Eval	Graduate	Graduate.Year1	Graduate.Year1._Eval	L	L.P	Graduate.Year1.Done	Graduate.Year1.Fee	Graduate.Year1.Fee.Count	Graduate.Year1.Fee._Eval	L.P.Print	L.P[0]	L.P[1]	L.P[2]	L.P._Eval	L.P._Args	L.P._Args[0]	Graduate.Year1.Fee.Done	L.P.Done	L.P.X	L.P.X._Eval	L.P.X._Args	L.P.X._Args[0]	L.P.X._Args[1]	L.P.X.Done
=====================
Index:    1
Name:     Eve.Print
Value:    
Target:   -1
Subordinates: 1	Eve.Print._Eval
Superiors: 1	Eve
Parents: 1	Eve
Children: 0
=====================
Index:    2
Name:     Eve.Print._Eval
Value:    
^@-V^

Target:   -1
Subordinates: 0
Superiors: 1	Eve.Print
Parents: 1	Eve
Children: 0
=====================
Index:    3
Name:     Eve.CheckDone
Value:    
Target:   -1
Subordinates: 1	Eve.CheckDone._Eval
Superiors: 1	Eve
Parents: 1	Eve
Children: 0
=====================
Index:    4
Name:     Eve.CheckDone._Eval
Value:    
if not @-N.Done { @-N; }

Target:   -1
Subordinates: 0
Superiors: 1	Eve.CheckDone
Parents: 1	Eve
Children: 0
=====================
Index:    5
Name:     check
Value:    
Target:   -1
Subordinates: 1	check._Eval
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    6
Name:     check._Eval
Value:    
for check._Args {
		check._Args._Iterator.CheckDone
}

Target:   -1
Subordinates: 0
Superiors: 1	check
Parents: 1	Eve
Children: 0
=====================
Index:    7
Name:     Graduate
Value:    
Target:   -1
Subordinates: 1	Graduate.Year1
Superiors: 0
Parents: 1	Eve
Children: 1	L
=====================
Index:    8
Name:     Graduate.Year1
Value:    L.P.X._Args
Target:   -1
Subordinates: 3	Graduate.Year1._Eval	Graduate.Year1.Done	Graduate.Year1.Fee
Superiors: 1	Graduate
Parents: 1	Eve
Children: 1	L.P
=====================
Index:    9
Name:     Graduate.Year1._Eval
Value:    ^&-V
^
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    10
Name:     L
Value:    
Target:   -1
Subordinates: 1	L.P
Superiors: 0
Parents: 2	Eve	Graduate
Children: 0
=====================
Index:    11
Name:     L.P
Value:    2
Target:   -1
Subordinates: 5	L.P.Print	L.P._Eval	L.P._Args	L.P.Done	L.P.X
Superiors: 1	L
Parents: 2	Eve	Graduate.Year1
Children: 0
=====================
Index:    12
Name:     Graduate.Year1.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    13
Name:     Graduate.Year1.Fee
Value:    
Target:   -1
Subordinates: 3	Graduate.Year1.Fee.Count	Graduate.Year1.Fee._Eval	Graduate.Year1.Fee.Done
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    14
Name:     Graduate.Year1.Fee.Count
Value:    10000
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    15
Name:     Graduate.Year1.Fee._Eval
Value:    
^Count $|Count|
^

Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    16
Name:     L.P.Print
Value:    
1

Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    17
Name:     L.P[0]
Value:    4
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    18
Name:     L.P[1]
Value:    2
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    19
Name:     L.P[2]
Value:    3
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    20
Name:     L.P._Eval
Value:    
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

Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    21
Name:     L.P._Args
Value:    
Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    22
Name:     L.P._Args[0]
Value:    1
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    23
Name:     Graduate.Year1.Fee.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    24
Name:     L.P.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    25
Name:     L.P.X
Value:    
Target:   -1
Subordinates: 3	L.P.X._Eval	L.P.X._Args	L.P.X.Done
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    26
Name:     L.P.X._Eval
Value:    
^
\$|_Args[0]|: $|_Args[0]|
\$|_Args[1]|: $|_Args[1]|
^

Target:   -1
Subordinates: 0
Superiors: 1	L.P.X
Parents: 1	Eve
Children: 0
=====================
Index:    27
Name:     L.P.X._Args
Value:    
Target:   -1
Subordinates: 0
Superiors: 1	L.P.X
Parents: 1	Eve
Children: 0
=====================
Index:    28
Name:     L.P.X._Args[0]
Value:    1
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    29
Name:     L.P.X._Args[1]
Value:    
Target:   8
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    30
Name:     L.P.X.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	L.P.X
Parents: 1	Eve
Children: 0
=====================

$|_Args[0]|: 2
$|_Args[1]|: 
Index:    0
Name:     Eve
Value:    
Target:   -1
Subordinates: 2	Eve.Print	Eve.CheckDone
Superiors: 0
Parents: 0
Children: 30	Eve.Print	Eve.Print._Eval	Eve.CheckDone	Eve.CheckDone._Eval	check	check._Eval	Graduate	Graduate.Year1	Graduate.Year1._Eval	L	L.P	Graduate.Year1.Done	Graduate.Year1.Fee	Graduate.Year1.Fee.Count	Graduate.Year1.Fee._Eval	L.P.Print	L.P[0]	L.P[1]	L.P[2]	L.P._Eval	L.P._Args	L.P._Args[0]	Graduate.Year1.Fee.Done	L.P.Done	L.P.X	L.P.X._Eval	L.P.X._Args	L.P.X._Args[0]	L.P.X._Args[1]	L.P.X.Done
=====================
Index:    1
Name:     Eve.Print
Value:    
Target:   -1
Subordinates: 1	Eve.Print._Eval
Superiors: 1	Eve
Parents: 1	Eve
Children: 0
=====================
Index:    2
Name:     Eve.Print._Eval
Value:    
^@-V^

Target:   -1
Subordinates: 0
Superiors: 1	Eve.Print
Parents: 1	Eve
Children: 0
=====================
Index:    3
Name:     Eve.CheckDone
Value:    
Target:   -1
Subordinates: 1	Eve.CheckDone._Eval
Superiors: 1	Eve
Parents: 1	Eve
Children: 0
=====================
Index:    4
Name:     Eve.CheckDone._Eval
Value:    
if not @-N.Done { @-N; }

Target:   -1
Subordinates: 0
Superiors: 1	Eve.CheckDone
Parents: 1	Eve
Children: 0
=====================
Index:    5
Name:     check
Value:    
Target:   -1
Subordinates: 1	check._Eval
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    6
Name:     check._Eval
Value:    
for check._Args {
		check._Args._Iterator.CheckDone
}

Target:   -1
Subordinates: 0
Superiors: 1	check
Parents: 1	Eve
Children: 0
=====================
Index:    7
Name:     Graduate
Value:    
Target:   -1
Subordinates: 1	Graduate.Year1
Superiors: 0
Parents: 1	Eve
Children: 1	L
=====================
Index:    8
Name:     Graduate.Year1
Value:    L.P.X._Args
Target:   -1
Subordinates: 3	Graduate.Year1._Eval	Graduate.Year1.Done	Graduate.Year1.Fee
Superiors: 1	Graduate
Parents: 1	Eve
Children: 1	L.P
=====================
Index:    9
Name:     Graduate.Year1._Eval
Value:    ^&-V
^
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    10
Name:     L
Value:    
Target:   -1
Subordinates: 1	L.P
Superiors: 0
Parents: 2	Eve	Graduate
Children: 0
=====================
Index:    11
Name:     L.P
Value:    2
Target:   -1
Subordinates: 5	L.P.Print	L.P._Eval	L.P._Args	L.P.Done	L.P.X
Superiors: 1	L
Parents: 2	Eve	Graduate.Year1
Children: 0
=====================
Index:    12
Name:     Graduate.Year1.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    13
Name:     Graduate.Year1.Fee
Value:    
Target:   -1
Subordinates: 3	Graduate.Year1.Fee.Count	Graduate.Year1.Fee._Eval	Graduate.Year1.Fee.Done
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    14
Name:     Graduate.Year1.Fee.Count
Value:    10000
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    15
Name:     Graduate.Year1.Fee._Eval
Value:    
^Count $|Count|
^

Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    16
Name:     L.P.Print
Value:    
1

Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    17
Name:     L.P[0]
Value:    4
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    18
Name:     L.P[1]
Value:    2
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    19
Name:     L.P[2]
Value:    3
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    20
Name:     L.P._Eval
Value:    
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

Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    21
Name:     L.P._Args
Value:    
Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    22
Name:     L.P._Args[0]
Value:    1
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    23
Name:     Graduate.Year1.Fee.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    24
Name:     L.P.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    25
Name:     L.P.X
Value:    
Target:   -1
Subordinates: 3	L.P.X._Eval	L.P.X._Args	L.P.X.Done
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    26
Name:     L.P.X._Eval
Value:    
^
\$|_Args[0]|: $|_Args[0]|
\$|_Args[1]|: $|_Args[1]|
^

Target:   -1
Subordinates: 0
Superiors: 1	L.P.X
Parents: 1	Eve
Children: 0
=====================
Index:    27
Name:     L.P.X._Args
Value:    
Target:   -1
Subordinates: 0
Superiors: 1	L.P.X
Parents: 1	Eve
Children: 0
=====================
Index:    28
Name:     L.P.X._Args[0]
Value:    2
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    29
Name:     L.P.X._Args[1]
Value:    
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    30
Name:     L.P.X.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	L.P.X
Parents: 1	Eve
Children: 0
=====================
L.P[0]Index:    0
Name:     Eve
Value:    
Target:   -1
Subordinates: 2	Eve.Print	Eve.CheckDone
Superiors: 0
Parents: 0
Children: 33	Eve.Print	Eve.Print._Eval	Eve.CheckDone	Eve.CheckDone._Eval	check	check._Eval	Graduate	Graduate.Year1	Graduate.Year1._Eval	L	L.P	Graduate.Year1.Done	Graduate.Year1.Fee	Graduate.Year1.Fee.Count	Graduate.Year1.Fee._Eval	L.P.Print	L.P[0]	L.P[1]	L.P[2]	L.P._Eval	L.P._Args	L.P._Args[0]	Graduate.Year1.Fee.Done	L.P.Done	L.P.X	L.P.X._Eval	L.P.X._Args	L.P.X._Args[0]	L.P.X._Args[1]	L.P.X.Done	L.P._Iterator	L.P._Iterator.Print	L.P._Iterator.Print.Done
=====================
Index:    1
Name:     Eve.Print
Value:    
Target:   -1
Subordinates: 1	Eve.Print._Eval
Superiors: 1	Eve
Parents: 1	Eve
Children: 0
=====================
Index:    2
Name:     Eve.Print._Eval
Value:    
^@-V^

Target:   -1
Subordinates: 0
Superiors: 1	Eve.Print
Parents: 1	Eve
Children: 0
=====================
Index:    3
Name:     Eve.CheckDone
Value:    
Target:   -1
Subordinates: 1	Eve.CheckDone._Eval
Superiors: 1	Eve
Parents: 1	Eve
Children: 0
=====================
Index:    4
Name:     Eve.CheckDone._Eval
Value:    
if not @-N.Done { @-N; }

Target:   -1
Subordinates: 0
Superiors: 1	Eve.CheckDone
Parents: 1	Eve
Children: 0
=====================
Index:    5
Name:     check
Value:    
Target:   -1
Subordinates: 1	check._Eval
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    6
Name:     check._Eval
Value:    
for check._Args {
		check._Args._Iterator.CheckDone
}

Target:   -1
Subordinates: 0
Superiors: 1	check
Parents: 1	Eve
Children: 0
=====================
Index:    7
Name:     Graduate
Value:    
Target:   -1
Subordinates: 1	Graduate.Year1
Superiors: 0
Parents: 1	Eve
Children: 1	L
=====================
Index:    8
Name:     Graduate.Year1
Value:    L.P.X._Args
Target:   -1
Subordinates: 3	Graduate.Year1._Eval	Graduate.Year1.Done	Graduate.Year1.Fee
Superiors: 1	Graduate
Parents: 1	Eve
Children: 1	L.P
=====================
Index:    9
Name:     Graduate.Year1._Eval
Value:    ^&-V
^
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    10
Name:     L
Value:    
Target:   -1
Subordinates: 1	L.P
Superiors: 0
Parents: 2	Eve	Graduate
Children: 0
=====================
Index:    11
Name:     L.P
Value:    2
Target:   -1
Subordinates: 6	L.P.Print	L.P._Eval	L.P._Args	L.P.Done	L.P.X	L.P._Iterator
Superiors: 1	L
Parents: 2	Eve	Graduate.Year1
Children: 0
=====================
Index:    12
Name:     Graduate.Year1.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    13
Name:     Graduate.Year1.Fee
Value:    
Target:   -1
Subordinates: 3	Graduate.Year1.Fee.Count	Graduate.Year1.Fee._Eval	Graduate.Year1.Fee.Done
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    14
Name:     Graduate.Year1.Fee.Count
Value:    10000
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    15
Name:     Graduate.Year1.Fee._Eval
Value:    
^Count $|Count|
^

Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    16
Name:     L.P.Print
Value:    
1

Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    17
Name:     L.P[0]
Value:    4
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    18
Name:     L.P[1]
Value:    2
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    19
Name:     L.P[2]
Value:    3
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    20
Name:     L.P._Eval
Value:    
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

Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    21
Name:     L.P._Args
Value:    
Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    22
Name:     L.P._Args[0]
Value:    1
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    23
Name:     Graduate.Year1.Fee.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    24
Name:     L.P.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    25
Name:     L.P.X
Value:    
Target:   -1
Subordinates: 3	L.P.X._Eval	L.P.X._Args	L.P.X.Done
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    26
Name:     L.P.X._Eval
Value:    
^
\$|_Args[0]|: $|_Args[0]|
\$|_Args[1]|: $|_Args[1]|
^

Target:   -1
Subordinates: 0
Superiors: 1	L.P.X
Parents: 1	Eve
Children: 0
=====================
Index:    27
Name:     L.P.X._Args
Value:    
Target:   -1
Subordinates: 0
Superiors: 1	L.P.X
Parents: 1	Eve
Children: 0
=====================
Index:    28
Name:     L.P.X._Args[0]
Value:    2
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    29
Name:     L.P.X._Args[1]
Value:    
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    30
Name:     L.P.X.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	L.P.X
Parents: 1	Eve
Children: 0
=====================
Index:    31
Name:     L.P._Iterator
Value:    L.P[0]
Target:   -1
Subordinates: 1	L.P._Iterator.Print
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    32
Name:     L.P._Iterator.Print
Value:    
Target:   -1
Subordinates: 1	L.P._Iterator.Print.Done
Superiors: 1	L.P._Iterator
Parents: 1	Eve
Children: 0
=====================
Index:    33
Name:     L.P._Iterator.Print.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	L.P._Iterator.Print
Parents: 1	Eve
Children: 0
=====================
L.P[1]Index:    0
Name:     Eve
Value:    
Target:   -1
Subordinates: 2	Eve.Print	Eve.CheckDone
Superiors: 0
Parents: 0
Children: 33	Eve.Print	Eve.Print._Eval	Eve.CheckDone	Eve.CheckDone._Eval	check	check._Eval	Graduate	Graduate.Year1	Graduate.Year1._Eval	L	L.P	Graduate.Year1.Done	Graduate.Year1.Fee	Graduate.Year1.Fee.Count	Graduate.Year1.Fee._Eval	L.P.Print	L.P[0]	L.P[1]	L.P[2]	L.P._Eval	L.P._Args	L.P._Args[0]	Graduate.Year1.Fee.Done	L.P.Done	L.P.X	L.P.X._Eval	L.P.X._Args	L.P.X._Args[0]	L.P.X._Args[1]	L.P.X.Done	L.P._Iterator	L.P._Iterator.Print	L.P._Iterator.Print.Done
=====================
Index:    1
Name:     Eve.Print
Value:    
Target:   -1
Subordinates: 1	Eve.Print._Eval
Superiors: 1	Eve
Parents: 1	Eve
Children: 0
=====================
Index:    2
Name:     Eve.Print._Eval
Value:    
^@-V^

Target:   -1
Subordinates: 0
Superiors: 1	Eve.Print
Parents: 1	Eve
Children: 0
=====================
Index:    3
Name:     Eve.CheckDone
Value:    
Target:   -1
Subordinates: 1	Eve.CheckDone._Eval
Superiors: 1	Eve
Parents: 1	Eve
Children: 0
=====================
Index:    4
Name:     Eve.CheckDone._Eval
Value:    
if not @-N.Done { @-N; }

Target:   -1
Subordinates: 0
Superiors: 1	Eve.CheckDone
Parents: 1	Eve
Children: 0
=====================
Index:    5
Name:     check
Value:    
Target:   -1
Subordinates: 1	check._Eval
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    6
Name:     check._Eval
Value:    
for check._Args {
		check._Args._Iterator.CheckDone
}

Target:   -1
Subordinates: 0
Superiors: 1	check
Parents: 1	Eve
Children: 0
=====================
Index:    7
Name:     Graduate
Value:    
Target:   -1
Subordinates: 1	Graduate.Year1
Superiors: 0
Parents: 1	Eve
Children: 1	L
=====================
Index:    8
Name:     Graduate.Year1
Value:    L.P.X._Args
Target:   -1
Subordinates: 3	Graduate.Year1._Eval	Graduate.Year1.Done	Graduate.Year1.Fee
Superiors: 1	Graduate
Parents: 1	Eve
Children: 1	L.P
=====================
Index:    9
Name:     Graduate.Year1._Eval
Value:    ^&-V
^
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    10
Name:     L
Value:    
Target:   -1
Subordinates: 1	L.P
Superiors: 0
Parents: 2	Eve	Graduate
Children: 0
=====================
Index:    11
Name:     L.P
Value:    2
Target:   -1
Subordinates: 6	L.P.Print	L.P._Eval	L.P._Args	L.P.Done	L.P.X	L.P._Iterator
Superiors: 1	L
Parents: 2	Eve	Graduate.Year1
Children: 0
=====================
Index:    12
Name:     Graduate.Year1.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    13
Name:     Graduate.Year1.Fee
Value:    
Target:   -1
Subordinates: 3	Graduate.Year1.Fee.Count	Graduate.Year1.Fee._Eval	Graduate.Year1.Fee.Done
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    14
Name:     Graduate.Year1.Fee.Count
Value:    10000
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    15
Name:     Graduate.Year1.Fee._Eval
Value:    
^Count $|Count|
^

Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    16
Name:     L.P.Print
Value:    
1

Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    17
Name:     L.P[0]
Value:    4
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    18
Name:     L.P[1]
Value:    2
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    19
Name:     L.P[2]
Value:    3
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    20
Name:     L.P._Eval
Value:    
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

Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    21
Name:     L.P._Args
Value:    
Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    22
Name:     L.P._Args[0]
Value:    1
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    23
Name:     Graduate.Year1.Fee.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    24
Name:     L.P.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    25
Name:     L.P.X
Value:    
Target:   -1
Subordinates: 3	L.P.X._Eval	L.P.X._Args	L.P.X.Done
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    26
Name:     L.P.X._Eval
Value:    
^
\$|_Args[0]|: $|_Args[0]|
\$|_Args[1]|: $|_Args[1]|
^

Target:   -1
Subordinates: 0
Superiors: 1	L.P.X
Parents: 1	Eve
Children: 0
=====================
Index:    27
Name:     L.P.X._Args
Value:    
Target:   -1
Subordinates: 0
Superiors: 1	L.P.X
Parents: 1	Eve
Children: 0
=====================
Index:    28
Name:     L.P.X._Args[0]
Value:    2
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    29
Name:     L.P.X._Args[1]
Value:    
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    30
Name:     L.P.X.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	L.P.X
Parents: 1	Eve
Children: 0
=====================
Index:    31
Name:     L.P._Iterator
Value:    L.P[1]
Target:   -1
Subordinates: 1	L.P._Iterator.Print
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    32
Name:     L.P._Iterator.Print
Value:    
Target:   -1
Subordinates: 1	L.P._Iterator.Print.Done
Superiors: 1	L.P._Iterator
Parents: 1	Eve
Children: 0
=====================
Index:    33
Name:     L.P._Iterator.Print.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	L.P._Iterator.Print
Parents: 1	Eve
Children: 0
=====================
L.P[2]Index:    0
Name:     Eve
Value:    
Target:   -1
Subordinates: 2	Eve.Print	Eve.CheckDone
Superiors: 0
Parents: 0
Children: 33	Eve.Print	Eve.Print._Eval	Eve.CheckDone	Eve.CheckDone._Eval	check	check._Eval	Graduate	Graduate.Year1	Graduate.Year1._Eval	L	L.P	Graduate.Year1.Done	Graduate.Year1.Fee	Graduate.Year1.Fee.Count	Graduate.Year1.Fee._Eval	L.P.Print	L.P[0]	L.P[1]	L.P[2]	L.P._Eval	L.P._Args	L.P._Args[0]	Graduate.Year1.Fee.Done	L.P.Done	L.P.X	L.P.X._Eval	L.P.X._Args	L.P.X._Args[0]	L.P.X._Args[1]	L.P.X.Done	L.P._Iterator	L.P._Iterator.Print	L.P._Iterator.Print.Done
=====================
Index:    1
Name:     Eve.Print
Value:    
Target:   -1
Subordinates: 1	Eve.Print._Eval
Superiors: 1	Eve
Parents: 1	Eve
Children: 0
=====================
Index:    2
Name:     Eve.Print._Eval
Value:    
^@-V^

Target:   -1
Subordinates: 0
Superiors: 1	Eve.Print
Parents: 1	Eve
Children: 0
=====================
Index:    3
Name:     Eve.CheckDone
Value:    
Target:   -1
Subordinates: 1	Eve.CheckDone._Eval
Superiors: 1	Eve
Parents: 1	Eve
Children: 0
=====================
Index:    4
Name:     Eve.CheckDone._Eval
Value:    
if not @-N.Done { @-N; }

Target:   -1
Subordinates: 0
Superiors: 1	Eve.CheckDone
Parents: 1	Eve
Children: 0
=====================
Index:    5
Name:     check
Value:    
Target:   -1
Subordinates: 1	check._Eval
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    6
Name:     check._Eval
Value:    
for check._Args {
		check._Args._Iterator.CheckDone
}

Target:   -1
Subordinates: 0
Superiors: 1	check
Parents: 1	Eve
Children: 0
=====================
Index:    7
Name:     Graduate
Value:    
Target:   -1
Subordinates: 1	Graduate.Year1
Superiors: 0
Parents: 1	Eve
Children: 1	L
=====================
Index:    8
Name:     Graduate.Year1
Value:    L.P.X._Args
Target:   -1
Subordinates: 3	Graduate.Year1._Eval	Graduate.Year1.Done	Graduate.Year1.Fee
Superiors: 1	Graduate
Parents: 1	Eve
Children: 1	L.P
=====================
Index:    9
Name:     Graduate.Year1._Eval
Value:    ^&-V
^
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    10
Name:     L
Value:    
Target:   -1
Subordinates: 1	L.P
Superiors: 0
Parents: 2	Eve	Graduate
Children: 0
=====================
Index:    11
Name:     L.P
Value:    2
Target:   -1
Subordinates: 6	L.P.Print	L.P._Eval	L.P._Args	L.P.Done	L.P.X	L.P._Iterator
Superiors: 1	L
Parents: 2	Eve	Graduate.Year1
Children: 0
=====================
Index:    12
Name:     Graduate.Year1.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    13
Name:     Graduate.Year1.Fee
Value:    
Target:   -1
Subordinates: 3	Graduate.Year1.Fee.Count	Graduate.Year1.Fee._Eval	Graduate.Year1.Fee.Done
Superiors: 1	Graduate.Year1
Parents: 1	Eve
Children: 0
=====================
Index:    14
Name:     Graduate.Year1.Fee.Count
Value:    10000
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    15
Name:     Graduate.Year1.Fee._Eval
Value:    
^Count $|Count|
^

Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    16
Name:     L.P.Print
Value:    
1

Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    17
Name:     L.P[0]
Value:    4
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    18
Name:     L.P[1]
Value:    2
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    19
Name:     L.P[2]
Value:    3
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    20
Name:     L.P._Eval
Value:    
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

Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    21
Name:     L.P._Args
Value:    
Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    22
Name:     L.P._Args[0]
Value:    1
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    23
Name:     Graduate.Year1.Fee.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	Graduate.Year1.Fee
Parents: 1	Eve
Children: 0
=====================
Index:    24
Name:     L.P.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    25
Name:     L.P.X
Value:    
Target:   -1
Subordinates: 3	L.P.X._Eval	L.P.X._Args	L.P.X.Done
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    26
Name:     L.P.X._Eval
Value:    
^
\$|_Args[0]|: $|_Args[0]|
\$|_Args[1]|: $|_Args[1]|
^

Target:   -1
Subordinates: 0
Superiors: 1	L.P.X
Parents: 1	Eve
Children: 0
=====================
Index:    27
Name:     L.P.X._Args
Value:    
Target:   -1
Subordinates: 0
Superiors: 1	L.P.X
Parents: 1	Eve
Children: 0
=====================
Index:    28
Name:     L.P.X._Args[0]
Value:    2
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    29
Name:     L.P.X._Args[1]
Value:    
Target:   -1
Subordinates: 0
Superiors: 0
Parents: 1	Eve
Children: 0
=====================
Index:    30
Name:     L.P.X.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	L.P.X
Parents: 1	Eve
Children: 0
=====================
Index:    31
Name:     L.P._Iterator
Value:    L.P[2]
Target:   -1
Subordinates: 1	L.P._Iterator.Print
Superiors: 1	L.P
Parents: 1	Eve
Children: 0
=====================
Index:    32
Name:     L.P._Iterator.Print
Value:    
Target:   -1
Subordinates: 1	L.P._Iterator.Print.Done
Superiors: 1	L.P._Iterator
Parents: 1	Eve
Children: 0
=====================
Index:    33
Name:     L.P._Iterator.Print.Done
Value:    1
Target:   -1
Subordinates: 0
Superiors: 1	L.P._Iterator.Print
Parents: 1	Eve
Children: 0
=====================
