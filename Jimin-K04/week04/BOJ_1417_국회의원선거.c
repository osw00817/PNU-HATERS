/* 2번후보 투표수 부터 크기순으로 정렬함,
1번후보 투표수가 더 커질때가지 투표를 나눠주기(투표수가 가장 큰 사람부터 나눠주기 시작)
다음 후보 투표수로 넘어가기
정렬 : 최소 힙 --> 최소힙으로 만들고 root 노드(가장작은값)을 찾고 이를 맨 뒤에 저장하는 방식을 반복해서 내림차순으로 정렬하게 됨*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void heap_sort(int size);
int* heap, cur_node;
int main(void)
{
	int N, dasom, voteCount, ans = 0, idx;
	scanf("%d %d", &N, &dasom); //후보수랑 다솜이 득표수 먼저 받기

	if (N == 1) { //후보수가 1명일 경우 예외처리
		printf("0");
		return 0;
	}

	heap = malloc(sizeof(int) * N);
	heap[0] = 0; // 힙에서 0번째는 사용하지 않음

	//최소힙 구현
	for (int i = 1; i < N; i++) {
		scanf("%d", &voteCount);
		cur_node = i;

		while (cur_node != 1 && heap[cur_node / 2] > voteCount) {
				heap[cur_node] = heap[cur_node / 2];
				cur_node /= 2;
		}
		heap[cur_node] = voteCount;
	}
	heap_sort(N - 1);//힙정렬--> 내림차순 정렬 만들기(투표수 가장 큰사람부터 시작하기 위해서)

	while (1) {
		idx = 1;
		while (idx < N && dasom <= heap[idx]) { //다솜 득표수보다 큰것들만 돌면서 1씩 빼주고 더하기
			dasom++;
			heap[idx]--;
			ans++;
			idx++;
		}
		if (idx == 1) break; //첫번째 후보(가장 많은 득표) 가 다솜 득표보다 작아지면 반복문을 끝냄
	}
	printf("%d", ans);
	free(heap);
}

//힙의 크기를 인자로 받는 재귀함수 -- 힙정렬 알고리즘
void heap_sort(int size)
{
	if (size == 1) return; //힙의 크기가 1이면 정렬 종료.

	int parent = 1, child = 2;
	int tmp = heap[size]; //마지막 값을 parent로 올리기 위해 임시 변수에 저장
	heap[size--] = heap[parent]; //힙의 크기를 줄이기 전 가장 마지막 노드에 처음 윈소(정렬 후 가장 작은 수)를 넣음.
	while (child <= size) {
		if (child < size && heap[child + 1] < heap[child]) child++;
		if (heap[tmp] > heap[child]) {
			heap[parent] = heap[child];
			parent = child;
			child = parent * 2;
		}
		else break;
	}
	heap[parent] = tmp;
	heap_sort(size);
}
