Eve.Print._Eval = `
^@-V^
`
Eve.CheckDone._Eval = `
if not @-N.Done { @-N; }
`
/* macro programming*/
check._Eval = `
for check._Args {
		check._Args._Iterator.CheckDone
}
`


