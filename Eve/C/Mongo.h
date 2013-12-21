#include "mongo.h"
#include <stdlib.h>


MONGO_EXPORT void bson_print_json_raw( const char *data ) {
    bson_iterator i;
    const char *key;
    int temp;
    bson_timestamp_t ts;
    char oidhex[25];
    bson scope;
    bson_iterator_from_buffer( &i, data );
		printf( "{");
		temp = 0;
    while ( bson_iterator_next( &i ) ) {
        bson_type t = bson_iterator_type( &i );
        if ( t == 0 )
            break;
				if ( temp++ != 0 ){
					printf( "," );
				}
        key = bson_iterator_key( &i );

        printf( "\"%s\":", key);
        switch ( t ) {
        case BSON_BOOL:
            printf( "%s" , bson_iterator_bool( &i ) ? "true" : "false" );
            break;
        case BSON_DOUBLE:
            printf( "%f" , bson_iterator_double( &i ) );
            break;
        case BSON_INT:
            bson_printf( "%d" , bson_iterator_int( &i ) );
            break;
        case BSON_LONG:
            printf( "%lld" , ( uint64_t )bson_iterator_long( &i ) );
            break;
        case BSON_STRING:
            printf( "\"%s\"" , bson_iterator_string( &i ) );
            break;
        case BSON_OID:
            bson_oid_to_string( bson_iterator_oid( &i ), oidhex );
            printf( "\"%s\"" , oidhex );
            break;
        case BSON_DATE:
            printf( "%ld" , ( long int )bson_iterator_date( &i ) );
            break;
        case BSON_SYMBOL:
            printf( "SYMBOL: %s" , bson_iterator_string( &i ) );
            break;
        case BSON_BINDATA:
            printf( "BSON_BINDATA" );
            break;
        case BSON_UNDEFINED:
            printf( "BSON_UNDEFINED" );
            break;
        case BSON_NULL:
            printf( "BSON_NULL" );
            break;
        case BSON_REGEX:
            printf( "BSON_REGEX: %s", bson_iterator_regex( &i ) );
            break;
        case BSON_CODE:
            printf( "BSON_CODE: %s", bson_iterator_code( &i ) );
            break;
        case BSON_CODEWSCOPE:
            printf( "BSON_CODE_W_SCOPE: %s", bson_iterator_code( &i ) );
            bson_iterator_code_scope_init( &i, &scope, 0 );
            printf( "\n\t SCOPE: " );
            bson_print( &scope );
            bson_destroy( &scope );
            break;
        case BSON_TIMESTAMP:
            ts = bson_iterator_timestamp( &i );
            printf( "i: %d, t: %d", ts.i, ts.t );
            break;
        case BSON_OBJECT:
        case BSON_ARRAY:
            bson_print_json_raw( bson_iterator_value( &i ) );
            break;
        default:
            bson_errprintf( "can't print type : %d\n" , t );
        }
    }
    printf( "}" );
}
MONGO_EXPORT void bson_print_json( const bson *b ){
	bson_print_json_raw( b->data);
}
int count;
static void tutorial_simple_query( mongo *conn ) {
  bson query[1];
  mongo_cursor cursor[1];

  bson_init( query );
  bson_append_string( query, "_id", "GO:0060438" );
  bson_finish( query );

  mongo_cursor_init( cursor, conn, "db.test.GeneOntology.Ontology" );
  mongo_cursor_set_query( cursor, query );

  while( mongo_cursor_next( cursor ) == MONGO_OK ) {
		bson_print_json( &cursor->current );
/*
    bson_iterator iterator[1];		
    if ( bson_find( iterator, mongo_cursor_bson( cursor ), "name" )) {
			printf( "name: %s\n", bson_iterator_string( iterator ) );
    }
*/
  }

  bson_destroy( query );
  mongo_cursor_destroy( cursor );
}
void initialize(void)
{
  count=0;
}
char Mongo_Connect(mongo *conn){
	int status = mongo_client( conn, "rna", 27017 );
  if( status != MONGO_OK ) {
    switch ( conn->err ) {
    case MONGO_CONN_NO_SOCKET:  printf( "no socket\n" ); return 0;
    case MONGO_CONN_FAIL:       printf( "connection failed\n" ); return 0;
    case MONGO_CONN_NOT_MASTER: printf( "not master\n" ); return 0;
    }
	}
	return 1;

}
