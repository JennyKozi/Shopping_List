#include <stdio.h>
#include <stdlib.h>

int shop(int, int, int *, int **);

// Check if the memory is allocated and malloc didn't fail
#define CHECK_MALLOC_NULL(p)  \
if ((p) == NULL) {  \
	perror("Cannot allocate memory!\n"); \
	exit(1);  \
};
