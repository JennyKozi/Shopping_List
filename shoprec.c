#include "shop.h"

int rec(int, int, int, int *, int **, int);

// Function shop
int shop(int m, int n, int *k, int **c) {
	int max, min;
	min = rec(m, m, n, k, c, 0);
	max = m - min;
	return max;
}

// Recursive function (rec)
int rec (int m, int P, int n, int *k, int **c, int i) {
	int amount, min = m, j, R;

	if (P < 0) {  // No solution
		return m;
	}
	if (i == n) {  // && P >= 0, there are no more products
		return P;
	}
	for (j = 0; j < k[i]; j++) {
		amount = P - c[i][j];
		R = rec(m, amount, n, k, c, i + 1);
		if (min > R && R >= 0) {  // Compare the return values
			min = R;  // Find the minimum possible amount that is left
		}
	}
	return min;
}