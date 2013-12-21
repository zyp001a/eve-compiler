print qq(
gene:Table
gene.Struct.Definitions[0]:C.Definition
gene.Struct.Definitions[0].Type.Name = "int";
gene.Struct.Definitions[0].Name = "a"
gene.Store.ExecuteFile = "./tmp.x"
gene.Store.Compile
ToRun = gene.Store.ExecuteFile;
);
print chr(0);
printf("1\n2\n3\n");
