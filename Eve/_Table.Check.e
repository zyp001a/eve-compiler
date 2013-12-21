Table.BasicCheck:C
Table.DraftStruct : C.Struct
Table.DraftStruct.Name = "@@-N"
Table.BasicCheck.TemplateFile = "_Table.BasicCheck.e.c"

Table.AdvancedCheck:C
Table.AdvancedCheck.TemplateFile = "_Table.AdvancedCheck.e.c"
Table.AdvancedCheck.Run._Eval = `
@@|BasicCheck.Run.CheckDone-N|
%|C.Run._Eval|
`


