test = [ 1,2,3]
for test {
		test._Iterator.Print
		&-I.Print
^
^
}
test2._Eval = `for test {
    test._Iterator.Print
    \&-I.Print
^
^
}`
test2
test3[0] = 1;
test3[1] = 2;
for test3 {
    test3._Iterator.Print
    &-I.Print
^
^
}


if 1< 2 {
	 ^1<2
^
} else {
	 ^1>2
^
}