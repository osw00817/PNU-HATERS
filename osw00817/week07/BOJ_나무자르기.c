#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int N;

int bSearch(int* ar, int first, int last, int target) {
	int mid;
	if (first > last)
		return -1; // Å½»ö ½ÇÆÐ

	mid = (first + last) / 2;
	//printf("MID: %d\n", mid);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (ar[i] - mid > 0) {
			sum += ar[i] - mid;
		}
	}
	//printf("SUM: %d\n", sum);
	if (target == sum)
		return mid;
	else if (sum < target)
		return bSearch(ar, first, mid - 1, target);
	else
		return bSearch(ar, mid + 1, last, target);
}

int main() {
	int M;
	int max = 0;
	scanf("%d %d", &N, &M);
	int* niga_list = (int*)malloc(sizeof(int) * N);
	int loop = N;
	while (loop--) {
		scanf("%d", &niga_list[loop]);
		if (niga_list[loop] > max) max = niga_list[loop];
	}
	int result = bSearch(niga_list, 0, max - 1, M);
	printf("%d", result);
	free(niga_list);
	return 0;
}
