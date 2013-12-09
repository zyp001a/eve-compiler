test=[1,2,3,4]
test._Eval = `
^&-a()
&-a(\t)
&-a(,end,)
&-a(,,%s\t)
&-a(\,\,,;;;,%s1)
^
`
test