<DataStructure
<_Table.BasicCheck
<_Table.AdvancedCheck
<_Table.Read
<_Table.Column
Table:DataStructure
Table.Sep = '\t'
Table.Config.MaxCharArraySize = 15

Table.Stat._Eval = `
@-N.Read.CheckDone
^Column Number:   @|ColumnNumber-P|
HeadStartOffset: @|HeadStartOffset-P|
DataStartOffset: @|DataStartOffset-P|
^
`



Table.Struct : C.Struct

