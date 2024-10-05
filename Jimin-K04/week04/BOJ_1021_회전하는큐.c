/*원형 덱 구현, 덱이 꽉차있는지 아닌지 고려 안해도 됨
1은 front_pop
2는 front_pop, 해당수를 rear_push
3은 rear_pop, 해당수를 front_push 
덱에 저장되는 값은 처음 큐에서의 위치.
뽑아내려고 하는 원소가 front에 위치해야함
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	int front;
	int rear;
	element* data;
}DEQUE;


int front_pop(DEQUE* d, int size)
{
	int tmp = d->data[d->front];
	d->front = (d->front + 1) % size;
	return tmp;
}
void front_push(DEQUE* d, int size, int X)
{
	d->front = (d->front - 1 + size) % size;
	d->data[d->front] = X;
}
int rear_pop(DEQUE* d, int size)
{
	int tmp = d->data[d->rear];
	d->rear = (d->rear - 1 + size) % size;
	return tmp;
}
void rear_push(DEQUE* d, int size, int X)
{
	d->rear = (d->rear + 1) % size;
	d->data[d->rear] = X;
}


int main(void)
{
	int N, M, loc, ans = 0;
	scanf("%d %d", &N, &M);
	//덱에 메모리 할당 및 초기화
	DEQUE* deque = malloc(sizeof(DEQUE));
	deque->data = malloc(sizeof(element) * N);

	deque->front = 0, deque->rear = N - 1;
	//1부터 N까지 값을 덱에 저장
	for (int i = 0; i < N; i++) {
		deque->data[i] = i + 1;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d", &loc);

		// 뽑으려는 수가 front 에 있으면 아래연산 수행 X 새로운 수 받음
		if (deque->data[deque->front] == loc) {
			front_pop(deque, N);
			continue;
		}
		//연산 2, 3중에 더 빠른것을 선택
		int start = deque->front, end = deque->rear, cnt2 = 0, cnt3 = 0;
		while (deque->data[start] != loc) {
			cnt2++;
			start = (start + 1) % N;
		}
		while (deque->data[end] != loc) {-
			cnt3++;
			end = (end - 1 + N) % N;
		}
		cnt3++;// 3번 연산은 한번 더해야 목표수가 front 로 감 

		if (cnt2 <= cnt3) {
			for (int j = 0; j < cnt2; j++) rear_push(deque, N, front_pop(deque, N));
			front_pop(deque, N);
			ans += cnt2;
		}
		else {
			for (int j = 0; j < cnt3; j++) front_push(deque, N, rear_pop(deque, N));
			front_pop(deque, N);
			ans += cnt3;
		}

	}
	printf("%d", ans);
}
