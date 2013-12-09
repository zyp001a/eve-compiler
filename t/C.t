<C
test : C

test.Exec

struct : C.Struct
struct.Name = "str"
struct.Definitions[0]:C.Definition
struct.Definitions[0].Type.Name = 'int'
struct.Definitions[0].Name = 'col1'

struct.Definitions[1]:C.Definition
struct.Definitions[1].Type.Name = 'int'
struct.Definitions[1].Name = 'col2'
struct.Definitions[1].Type.Size = '5'

struct.Print

