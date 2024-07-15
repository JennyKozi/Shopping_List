#include "shop.h"

int shop(int m, int n, int *k, int **c) {

	int max, min=m, i, j, s, P, cur;
	int **money, *costs;

	CHECK_MALLOC_NULL(money = malloc(n * sizeof(int *)));

	for (i = 0; i < n; i++) {
		CHECK_MALLOC_NULL(money[i] = malloc((m + 1) * sizeof(int)));
		for (s = 0; s < m + 1; s++) {
			money[i][s] = 0;  // Initialization for the elements of matrix money[][]
		}
	}

	for (j = 0; j < k[0]; j++) {
		P = m - c[0][j];  // P here indicates the amount that occurs after we have bought a model of the first product
		money[0][P] = 1;  // Complete with 1 the elements of the first row of money[][] whose column number is P
	}

	for (i = 1; i < n; i++) {
		for (s = 0; s < m + 1; s++) {
			if (money[i - 1][s] == 1) {  // Then s is one of the possible amounts that we currently have
				for (j = 0; j < k[i]; j++) {
					P = s - c[i][j];  // P: amount that occurs after we buy a model from current product
					if (P >= 0) {
						money[i][P] = 1;  // Complete current row of money[][] with 1 where necessary
					}
				}
			}
		}
	}

	for (s = 0; s < m + 1; s++) {
		if (money[n - 1][s] == 1) {  // Last row of money[][]: the first element whose value is 1 indicates min, by the number of its column s
			min = s;  // The minimum amount that is left in the end
			break;
		}
	}
	max = m - min;

	#ifdef COSTS

	CHECK_MALLOC_NULL(costs=malloc(n* sizeof(int)));

	for (i = 0; i < n; i++) {  // Initialization of array costs[]
		costs[i] = 0;
	}

	if (min != m) {  // If min=m, no solution found!
		cur = min;  // cur: the amount that we have after we have bought a product
		for (i = n - 1; i > 0; i--) {
			for (s = 0; s < m + 1; s++) {
				if (money[i - 1][s] == 1) {  // Then s is the amount of money that we have before we buy a product
					for (j = 0; j < k[i]; j++) {
						if (s - c[i][j] == cur) {  // Subtract from s each of the cost of the models of current product
							cur = s;
							costs[i] = c[i][j];  // Solution found for current product
							break;
						}
					}
					if (costs[i] != 0) {  // We have already found a cost of these product that fits our solution
						break;
					}
				}
			}
		}
		for (j = 0; j < k[0]; j++) {
			if (m - c[0][j] == cur) {
				costs[0] = c[i][j];  // Solution for the cost of the first product
				break;
			}
		}
		printf("\nItem costs: ");
		for (i = 0; i < n; i++) {
			printf("%d ", costs[i]);  // Print the cost for each product
		}
	}
	free(costs);

	#endif

	// Free memory
	for (i = 0; i < n; i++) {
		free(money[i]);
	}
	free(money);

	return max;
}
