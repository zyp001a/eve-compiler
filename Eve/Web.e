
RemoteFile.LocalDir = "/zyp/dump/"
RemoteFile.Download._Eval = `
~cd @|LocalDir| && wget -N @|RemoteAddress| -o @-N.log
// "==> RETR @|FileName| ... done"
//@|LocalAddress-N| = @|LocalDir|
//@|LocalAddress-N| += @|FileName-N|
`

