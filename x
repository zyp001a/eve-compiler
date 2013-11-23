LINE 0: Read identifier, Use
LINE 0: Read string2, "Common"
LINE 1: TOKEN, END_OF_STATEMENT
	Try to Get Value: Use, _Eval, -1
		Check Parent 0, Eve
	Eval Content: 
========

========
--->Match 

LINE 1: TOKEN, END_OF_STATEMENT
--->Match statement
--->Match statement
LINE 2: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 2: Read identifier, Array
LINE 2: Read identifier, Print
LINE 4: Read string3, `
print $|_Name|.Iterator
`
--->Match ASSIGN VALUE
LINE 5: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 5: Read identifier, Array
LINE 5: Read identifier, _Eval
LINE 11: Read string3, `
$|_Name|.IsStart = 1
for $|_Name|.Iterator $|_Name| {
	ifelse $|_Name|.IsStart {$|_Name|.IsStart = ""} {^$|Separator|^}
	$|Print|
}
`
--->Match ASSIGN VALUE
LINE 12: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 12: Read identifier, a
LINE 12: Read identifier, Array
LINE 13: TOKEN, END_OF_STATEMENT
--->Match INHERENT
--->Match translation_unit statement
LINE 14: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 14: Read identifier, a
LINE 14: Read identifier, Print
LINE 14: Read string3, `^xxx^$$|Print|^xxx^`
--->Match ASSIGN VALUE
LINE 15: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 15: Read identifier, a
LINE 15: Read identifier, Separator
LINE 16: Read string2, ";
"
--->Match ASSIGN VALUE
LINE 17: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 17: TOKEN, add
LINE 17: Read identifier, a
LINE 17: Read int, 1
--->Match ADD
LINE 18: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 18: TOKEN, add
LINE 18: Read identifier, a
LINE 18: Read int, 2
--->Match ADD
LINE 19: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 19: TOKEN, add
LINE 19: Read identifier, a
LINE 19: Read int, 3
--->Match ADD
LINE 20: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 21: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 21: Read identifier, a
LINE 22: TOKEN, END_OF_STATEMENT
--->Match EVAL
	Try to Get Value: a, _Eval, -1
		Check Subordinate 0, a.Print
		Check Subordinate 1, a.Separator
		Check Parent 1, Array
		Check Subordinate 0, Array.Print
		Check Subordinate 1, Array._Eval
			FIND!!!	Eval Content: 
========

$|_Name|.IsStart = 1
for $|_Name|.Iterator $|_Name| {
	ifelse $|_Name|.IsStart {$|_Name|.IsStart = ""} {^$|Separator|^}
	$|Print|
}

========
	Try to Get Value: a, _Name, -1
	Try to Get Value: a, _Name, -1
	Try to Get Value: a, _Name, -1
	Try to Get Value: a, _Name, -1
	Try to Get Value: a, _Name, -1
	Try to Get Value: a, Separator, -1
		Check Subordinate 0, a.Print
		Check Subordinate 1, a.Separator
			FIND!!!	Try to Get Value: a, Print, -1
		Check Subordinate 0, a.Print
			FIND!!!	From Parents 1, Array
	Try to Get Value: Array, Print, -1
		Check Subordinate 0, Array.Print
			FIND!!!	Try to Get Value: a, _Name, -1
--->Match 
a.IsStart = 1
for a.Iterator a {
	ifelse a.IsStart {a.IsStart = ""} {^;
^}
	^xxx^
print a.Iterator
^xxx^
}


LINE 1: TOKEN, END_OF_STATEMENT
--->Match statement
LINE 1: Read identifier, a
LINE 1: Read identifier, IsStart
LINE 1: Read int, 1
--->Match ASSIGN VALUE
LINE 2: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 2: TOKEN, for
LINE 2: Read identifier, a
LINE 2: Read identifier, Iterator
LINE 2: Read identifier, a
LINE 8: Read block, 
	ifelse a.IsStart {a.IsStart = ""} {^;
^}
	^xxx^
print a.Iterator
^xxx^


--->Match FOR
LINE 1: TOKEN, END_OF_STATEMENT
--->Match statement
LINE 1: TOKEN, ifelse
LINE 1: Read identifier, a
LINE 1: Read identifier, IsStart
LINE 1: Read block, a.IsStart = ""

LINE 2: Read block, ^;
^

--->Match IF ELSE
LINE 0: Read identifier, a
LINE 0: Read identifier, IsStart
LINE 0: Read string2, ""
--->Match ASSIGN VALUE
LINE 1: TOKEN, END_OF_STATEMENT
--->Match statement
LINE 2: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 3: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 3: Print string, ^xxx^
LINE 4: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 4: TOKEN, print
LINE 4: Read identifier, a
LINE 4: Read identifier, Iterator
LINE 5: TOKEN, END_OF_STATEMENT
--->Match PRINT
--->Match translation_unit statement
LINE 5: Print string, ^xxx^
LINE 6: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 7: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 8: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 9: TOKEN, END_OF_STATEMENT
--->Match statement
LINE 9: TOKEN, ifelse
LINE 9: Read identifier, a
LINE 9: Read identifier, IsStart
LINE 9: Read block, a.IsStart = ""

LINE 10: Read block, ^;
^

--->Match IF ELSE
LINE 3: Print string, ^;
^
LINE 4: TOKEN, END_OF_STATEMENT
--->Match statement
LINE 5: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 11: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 11: Print string, ^xxx^
LINE 12: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 12: TOKEN, print
LINE 12: Read identifier, a
LINE 12: Read identifier, Iterator
LINE 13: TOKEN, END_OF_STATEMENT
--->Match PRINT
--->Match translation_unit statement
LINE 13: Print string, ^xxx^
LINE 14: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 15: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 16: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 17: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 18: TOKEN, END_OF_STATEMENT
--->Match statement
LINE 18: TOKEN, ifelse
LINE 18: Read identifier, a
LINE 18: Read identifier, IsStart
LINE 18: Read block, a.IsStart = ""

LINE 19: Read block, ^;
^

--->Match IF ELSE
LINE 6: Print string, ^;
^
LINE 7: TOKEN, END_OF_STATEMENT
--->Match statement
LINE 8: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 20: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 20: Print string, ^xxx^
LINE 21: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 21: TOKEN, print
LINE 21: Read identifier, a
LINE 21: Read identifier, Iterator
LINE 22: TOKEN, END_OF_STATEMENT
--->Match PRINT
--->Match translation_unit statement
LINE 22: Print string, ^xxx^
LINE 23: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 24: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 25: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 26: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 27: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 9: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
LINE 10: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
--->Match translation_unit statement
LINE 23: TOKEN, END_OF_STATEMENT
--->Match translation_unit statement
