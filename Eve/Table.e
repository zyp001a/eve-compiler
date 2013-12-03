<DataStructure
<Table.BasicCheck
Table:DataStructure

Table.Stat._Eval = `
@-N.Read.CheckDone
^Column Number: @|ColumnSet.Length|
^
`

Table.Read._Eval = `
@-N.BasicCheck.CheckDone
@-N.AdvancedCheck.CheckDone
`

Table.AdvancedCheck._Eval = `
^AdvancedCheck
^
`

