#include "shop.h"

int main(int argc, char *argv[]) {  // argv[0]='shop'

	int M, N, i, j, max;
	int **C, *K;
	M = atoi(argv[1]);
	scanf("%d", &N);  // First input from file

	CHECK_MALLOC_NULL(K = malloc(N * sizeof(int)));
	CHECK_MALLOC_NULL(C = malloc(N * sizeof(int*)));

	for (i = 0; i < N; i++) {
		scanf("%d", &K[i]);  // Initialization of the elements of array K[]
		CHECK_MALLOC_NULL(C[i] = malloc(K[i] * sizeof(int)));
		for (j = 0; j < K[i]; j++) {
			scanf("%d", &C[i][j]);  // Initialization for the elements of matrix C[][]
		}
	}

	max = shop(M, N, K, C);  // Call function shop
	if (max == 0) {  // If max = 0, then min = M, so no money were spent
		printf("\nNo solution found.\n\n");
	}
	else {
		printf("\nMaximum amount spent is: %d\n\n", max);
	}

	// Free memory
	free(K);
	for (i = 0; i < N; i++) {
		free(C[i]);
	}
	free(C);

	return 0;
}