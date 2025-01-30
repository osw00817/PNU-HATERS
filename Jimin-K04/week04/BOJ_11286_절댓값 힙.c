/* ���� �� - �ּڰ��� ����ϹǷ� �ּ� �� ����
������ �Է¹޾Ƶ� ����� �ִ´�, ������ ���� ��ȯ �Լ� abs ���*/
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
		// �θ� �ڽĺ��� ������ �� ũ�� ��ü �Ǵ� �θ�� �ڽ��� ���� 0�̰� �θ� ����̸� ��ü
		if ((abs(heap[i / 2]) > abs(heap[i])) || (heap[i / 2] + heap[i] == 0 && heap[i / 2] > 0)) swap(i / 2, i);
		else break;
	}
}

int delete_min_heap(void) {
	int min_idx;

	if (!heapsize) return 0;

	int min_item = heap[1];// ��Ʈ����� �� ����
	heap[1] = heap[heapsize]; //heap �� ������ ���� ��Ʈ�� ��������
	heap[heapsize--] = 0; // ������ ���� 0���� �ʱ�ȭ �� �� size ���̱�

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