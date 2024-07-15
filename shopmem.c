#include "shop.h"

int rec(int, int, int, int *, int **, int, int **);

// Function shop
int shop(int m, int n, int *k, int **c) {
	int max, min, i, j, cur;
	int **memo;

	CHECK_MALLOC_NULL(memo = malloc((n + 1) * sizeof(int *)));

	for (i = 0; i < n + 1; i++) {
		CHECK_MALLOC_NULL(memo[i] = malloc((m + 1) * sizeof(int)));
		for (j = 0; j < m + 1; j++) {
			memo[i][j] = -1;  // Initialization for the elements of matrix memo[][]
		}
	}

	min = rec(m, m, n, k, c, 0, memo);
	max = m - min;

	#ifdef COSTS

	if (min != m) {
		printf("\nItem costs: ");
		cur = m;  // Current amount of money
		for (i = 1; i < n + 1; i++) {
			for (j = 0; j < m + 1; j++) {
				if (memo[i][j] == min) { // This element of memo[][] indicates, by the number of its column j, the money there is after the i-product is bought
					printf("%d ", cur - j);  // Solution for i-product is (cur - j)
					cur = j;
					break;  // Break because there is already a solution for the i-product
				}
			}
		}
		printf("%d", cur - min);  // Solution for the price of the last product
	}

	#endif

	// Free memory
	for (i = 0; i < n + 1; i++) {
		free(memo[i]);
	}
	free(memo);

	return max;
}

// Recursive function (rec)
int rec(int m, int P, int n, int *k, int **c, int i, int **memo) {
	int amount, min = m, j, R;

	if (P < 0) {  // No solution
		return m;
	}
	if (i == n) {  // There are no more products
		return P;
	}
	if (memo[i][P] != -1) {
		return memo[i][P];  // We have already calculated this value
	}
	for (j = 0; j < k[i]; j++) {
		amount = P - c[i][j];
		R = rec(m, amount, n, k, c, i + 1, memo);
		if (min > R && R >= 0) {  // Compare the return values
			min = R;  // Find the minimum possible amount that is left
		}
	}
	if (P >= 0) {
		memo[i][P] = min;  // Save this value to an element of memo[][]
	}
	return min;
}