#ifndef ESHAREDMEMORY
#define ESHAREDMEMORY
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h> 
#define SHM_FILE "/shmfile"
int *set_shm(){
	int *result = NULL;
 
/* Open the shared memory. */
	int descriptor = shm_open(SHM_FILE, 
													O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if (descriptor == -1){
		fprintf(stderr, "open shared memory error: %s\n", strerror(errno));
		exit(1);
	}
/* Size up the shared memory. */
	if(ftruncate(descriptor, sizeof(int)) == -1){
		fprintf(stderr, "ftruncate error %s\n");
		exit(1);
	}
	result = mmap(NULL, sizeof(int), 
								PROT_WRITE | PROT_READ, MAP_SHARED, 
								descriptor, 0 );
	*result = 1;
	return result;
}
int *get_shm(){
  int *result = NULL;
  int integerSize = sizeof(int);

/* Open the shared memory. */
  int descriptor = shm_open(SHM_FILE,
														O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);

/* Size up the shared memory. */
  result = mmap(NULL, integerSize,
                PROT_WRITE | PROT_READ, MAP_SHARED,
                descriptor, 0 );
  return result;
}

#endif
