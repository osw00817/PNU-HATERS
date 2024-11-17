#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void hanoi(int n, int from, int to, int left) {
	if (n < 1) {
		return 0;
	}
	if (n == 1) {
		printf("\n%d %d", from, to);
		return 1;
	}
	hanoi(n - 1, from, left, to);
	hanoi(1, from, to, left);
	hanoi(n - 1, left, to, from);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		tmp *= 2.0;
	}
	printf("%.0lf", tmp - 1.0);

	if (n <= 20) {
		hanoi(n, 1, 3, 2);
	}
	return 0;
}