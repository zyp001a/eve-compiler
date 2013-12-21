MongoDB.Address = "rna:27017"
if IsTest {
MongoDB.Database = "test"
}else{
MongoDB.Database = "eve"
}
