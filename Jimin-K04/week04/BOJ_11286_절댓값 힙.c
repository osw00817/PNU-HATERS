/* 절댓값 힙 - 최솟값을 출력하므로 최소 힙 구현
음수를 입력받아도 양수를 넣는다, 정수형 절댓값 반환 함수 abs 사용*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int heapsize = 0;
int* heap;

void swap(int idx1, int idx2) {
	int tmp = heap[idx1];
	heap[idx1] = heap[idx2];
	heap[idx2] = tmp;
}

void insert_heap(int num) {
	heap[++heapsize] = num;

	for (int i = heapsize; i > 1; i /= 2) {
		// 부모가 자식보다 절댓값이 더 크면 교체 또는 부모와 자식의 합이 0이고 부모가 양수이면 교체
		if ((abs(heap[i / 2]) > abs(heap[i])) || (heap[i / 2] + heap[i] == 0 && heap[i / 2] > 0)) swap(i / 2, i);
		else break;
	}
}

int delete_min_heap(void) {
	int min_idx;

	if (!heapsize) return 0;

	int min_item = heap[1];// 루트노드의 값 저장
	heap[1] = heap[heapsize]; //heap 의 마지막 값을 루트로 가져오기
	heap[heapsize--] = 0; // 마지막 값을 0으로 초기화 한 후 size 줄이기

	for (int i = 1; i * 2 <= heapsize;) {
		if (!heap[i * 2 + 1]) min_idx = i * 2;
		else if (heap[i * 2] + heap[i * 2 + 1] == 0) min_idx = (heap[i * 2] < 0 ? i * 2 : i * 2 + 1);
		else min_idx = (abs(heap[i * 2]) < abs(heap[i * 2 + 1]) ? i * 2 : i * 2 + 1);

		if ((abs(heap[i]) < abs(heap[min_idx])) || (heap[i] + heap[min_idx] == 0 && heap[i] < 0)) break;
		else {
			swap(min_idx, i);
			i = min_idx;
		}
	}

	return min_item;
}
int main(void) {
	int N, operation;
	scanf("%d", &N);

	heap = malloc(sizeof(int) * N);
	heap[0] = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &operation);
		if (operation) insert_heap(operation);
		else printf("%d\n", delete_min_heap());
		for (int i = 0; i <= heapsize; i++) printf("%d ", heap[i]);
		printf("\n");
	}
}