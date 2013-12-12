FileReader.Fetch._Eval = `
if !@|FormatText-N| {
	 @|FormatText-N| = readfile @|FormatFile-N|
}
parsefile @-N
`
