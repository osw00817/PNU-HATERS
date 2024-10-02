#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10000
//덱 구조체 선언
typedef int element;
typedef struct {
	int front;
	int rear;
	element* data; //동적 할당 배열
	
}Deque;

void init_duque(Deque* q)
{
	q->data = (element*)malloc(sizeof(element) * MAX);
	q->front = 0;
	q->rear = 0;
}
int empty(Deque* q)
{
	if (q->front == q->rear) return 1;
	else return 0;
}
void push_front(Deque* q, element data)
{
	q->front = (q->front - 1 + MAX) % MAX;
	q->data[q->front] = data;
}
void push_back(Deque* q, element data)
{
	q->data[q->rear] = data;
	q->rear = (q->rear + 1) % MAX;
}

void pop_front(Deque* q)
{
	if (empty(q)) printf("-1\n");
	else{
		printf("%d\n", q->data[q->front]);
		q->front = (q->front + 1) % MAX;
	}
}
void pop_back(Deque* q)
{
	if (empty(q)) printf("-1\n");
	else {
		q->rear = (q->rear - 1 + MAX) % MAX;
		printf("%d\n", q->data[q->rear]);
	}
}

//메인함수
int main(void)
{
	int cmd[20], N, tmp;
	Deque* deque = (Deque*)malloc(sizeof(Deque));
	init_duque(deque);

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", cmd);

		if (!strcmp(cmd, "push_front")) {
			scanf("%d", &tmp);
			push_front(deque, tmp);
		}
		else if (!strcmp(cmd, "push_back")) {
			scanf("%d", &tmp);
			push_back(deque, tmp);
		}
		else if (!strcmp(cmd, "pop_front")) pop_front(deque);
		else if (!strcmp(cmd, "pop_back")) pop_back(deque);
		else if (!strcmp(cmd, "size")) printf("%d\n", (deque->rear - deque->front + MAX) % MAX);
		else if (!strcmp(cmd, "empty")) empty(deque) ? printf("1\n") : printf("0\n");
		else if (!strcmp(cmd, "front")) empty(deque) ? printf("-1\n") : printf("%d\n", deque->data[deque->front]);
		else if (!strcmp(cmd, "back")) empty(deque) ? printf("-1\n") : printf("%d\n", deque->data[(deque->rear - 1 + MAX) % MAX]);
	}
}
