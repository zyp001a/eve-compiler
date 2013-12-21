#include "SharedMemory.h"
main(){
	int *result = set_shm();
	int *r2 = get_shm();
	printf("%d\n", *r2);
}
