/*최소 힙 구현
  힙의 배열 크기는 N으로 잡음, 비어있는 배열에서 시작하므로 힙 구조체 선언해서 동적 메모리 할당 해줌*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//힙 구조체 선언
typedef int element;
typedef struct {
	element* heap;
	int size;
}Heaptype;

void init_heap(Heaptype* h, int size)
{
	h->heap = malloc(sizeof(element) * (size + 1)); //0 비워두기 위해 + 1
	h->size = 0;
	h->heap[0] = 0; //인덱스 1부터 사용함, 0은 비워두기
}
void add_heap(Heaptype* h, int X)
{
	int n_th = ++h->size; //노드의 최종 인덱스 저장
	while (n_th > 1) {
		if (h->heap[n_th / 2] > X) {
			h->heap[n_th] = h->heap[n_th / 2];
			n_th /= 2;
		}
		else break;
	}
	h->heap[n_th] = X; //노드 삽입
}

void del_heap(Heaptype* h)
{
	//배열이 비어있는 경우
	if (!h->size) {
		printf("0\n");
		return;
	}
	int tmp = h->heap[h->size--]; //힙의 마지막 노드에 저장된 값을 임시변수에 저장,힙의 크기 줄이기
	int root = 1;
	int child = root * 2;
	printf("%d\n", h->heap[root]);
	//root(1) 번째 노드의 값이 삭제되고 마지막 노드가 root 가 됨
	while (child <= h->size) {
		if (child < h->size && h->heap[child] > h->heap[child + 1]) child++;
		if (h->heap[child] < tmp) {
			h->heap[root] = h->heap[child];
			root = child;
			child = root * 2;
		}
		else break;
	}
	h->heap[root] = tmp;
}

//메인함수 시작
int main(void)
{
	Heaptype* Heap = (Heaptype*)malloc(sizeof(Heaptype));

	int N, num;
	scanf("%d", &N);

	init_heap(Heap, N);// 연산의 개수만큼 add 될 수 있으므로 size 를 N으로 잡기

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);

		if (!num) del_heap(Heap);
		else add_heap(Heap, num);
	}
}
