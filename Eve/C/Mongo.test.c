#include "Mongo.h"
//gcc -std=c99 Mongo.test.c -lmongoc

int main(void)
{
	mongo conn[1];
	Mongo_Connect(conn);
	tutorial_simple_query(conn);
	mongo_destroy( conn );
	return 0;
}
