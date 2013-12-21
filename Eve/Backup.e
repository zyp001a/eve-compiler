Backup.Dir = "~"
Backup._EvalArgs = `
if &|_Args[0]-N|{
	 &|Dir-N| = &|_Args[0]-N|;
}
`
Backup._Eval = `
~perl %|EveHome|/_BackupScriptFile.pl &|Dir|
`