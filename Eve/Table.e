<DataStructure
<BasicStatistics
Table:DataStructure

Table.Stat._Eval = `
if @-N.ReadDone {
	 @|Read|
}
^Column Number: @|ColumnSet.Length|
^
`

Table.ReadDone = 0
Table.Read._Eval = `
if @-N.BasicCheckDone {
	 @|BasicCheck|
}
if @-N.AdvancedCheckDone {
	 @|AdvancedCheck|
}
@-N.BasicCheckDone = 1
`

Table.BasicCheckDone = 0
Table.BasicCheck._Eval = `

@-N.BasicCheckDone = 1
`

