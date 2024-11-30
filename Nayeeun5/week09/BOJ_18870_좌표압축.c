#include<stdio.h>
#include<stdlib.h>

int compare(void* a, void* b) {
	return *(int*)a - *(int*)b;
}
int binary_search(int* v_arr, int N, int a) {
    int low = 0, high = N;
    while (low < high) {
        int mid = (low + high) / 2;
        if (v_arr[mid] < a)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
int main() {
	int N;
	scanf("%d", &N);
	int* arr = malloc(sizeof(int) * N);
	int* sort = malloc(sizeof(int) * N);
	int* v_arr = malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		sort[i] = arr[i];
	}
	qsort(sort, N, sizeof(int), compare);
	int idx = 1;
	v_arr[0] = sort[0];
	for (int i = 1; i < N; i++) {
		if (sort[i-1] != sort[i]) v_arr[idx++] = sort[i];
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", binary_search(v_arr, idx, arr[i]));
	}
	free(arr);
	free(sort);
	free(v_arr);
	return 0;
}
