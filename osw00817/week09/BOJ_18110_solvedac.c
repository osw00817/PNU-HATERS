#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int N;
	scanf("%d", &N);
	if (N == 0) {
		printf("%d", 0);
		return 0;
	}
	int numOfException = round(N * 0.15);
	int* nums = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
	}

	qsort(nums, N, sizeof(int), compare);

	int sum = 0;
	int tmp = 0;
	for (int i = numOfException; i < N - numOfException; i++) {
		tmp++;
		sum += nums[i];
	}

	printf("%.0lf", round(sum * 1.0 / tmp));
	free(nums);
	return 0;
}