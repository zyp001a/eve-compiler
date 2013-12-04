<DataStructure
<_Table.BasicCheck
<_Table.AdvancedCheck
<_Table.Column
Table:DataStructure
Table.Sep = `'\t'`
Table.Config.MaxCharArraySize = 15

Table.Stat._Eval = `
@-N.Read.CheckDone
^Column Number:   @|ColumnNumber-P|
HeadStartOffset: @|HeadStartOffset-P|
DataStartOffset: @|DataStartOffset-P|
^
`

Table.Read._Eval = `
@-N.BasicCheck.Run.CheckDone
@-N.AdvancedCheck.Run.CheckDone
`

Table.DraftStruct : C.Struct
Table.Struct : C.Struct

