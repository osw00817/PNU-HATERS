#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int search_detail(int* ar, int index, int target, int size, int* visited) {
	if (index == -1 || visited[index] || ar[index] != target)
	{
		return 0;
	}
	visited[index] = 1;
	int cnt = 1;

	if (index - 1 >= 0) {
		cnt += search_detail(ar, index - 1, target, size, visited);
	}
	if (index + 1 < size) {
		cnt += search_detail(ar, index + 1, target, size, visited);
	}
	return cnt;
}
int search(int* ar, int start, int end, int target) {
	if (start > end)
		return -1;
	int mid = (start + end) / 2;
	if (ar[mid] == target)
		return mid;
	else if (ar[mid] > target)
		return search(ar, start, mid - 1, target);
	else
		return search(ar, mid + 1, end, target);
}
int comapre(const int* a, const int* b) {
	return (*a - *b);
}
int main() {
	int loop;
	scanf("%d", &loop);
	int* nigga_list = (int*)malloc(sizeof(int) * loop);
	for (int i = 0; i < loop; i++) {
		scanf("%d", &nigga_list[i]);
	}
	qsort(nigga_list, loop, sizeof(int), comapre);

	int loop2;
	scanf("%d", &loop2);
	int* ching_chang_chong = (int*)malloc(sizeof(int) * loop2);
	for (int i = 0; i < loop2; i++) {
		scanf("%d", &ching_chang_chong[i]);
	}
	for (int i = 0; i < loop2; i++) {
		int index = search(nigga_list, 0, loop - 1, ching_chang_chong[i]);

		int* visited = (int*)calloc(loop, sizeof(int));
		printf("%d ", search_detail(nigga_list, index, ching_chang_chong[i], loop, visited));
	}
	free(nigga_list);
	free(ching_chang_chong);
	return 0;
}