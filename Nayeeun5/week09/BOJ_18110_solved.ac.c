#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int compare(void* a, void* b) {
	return *(int*)a - *(int*)b;
}
int main() {
	int N;
	int sum = 0, cnt = 0;
	int ans[10001] = { 0 };
	scanf("%d", &N);
	if (N == 0) {
		printf("0");
		return 0;
	}
	int* diff = malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &diff[i]);
	}
	qsort(diff, N, sizeof(int), compare);
	int del = round(N * 0.15);
	for (int i = del; i < N-del; i++) {
		sum += diff[i];
		cnt++;
	}
	int ave = round((float)sum / cnt);
	printf("%d",ave);
	free(diff);
	return 0;
}
