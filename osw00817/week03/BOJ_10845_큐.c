#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 10000

/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다.
만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

typedef struct {
	int data[SIZE];
	int front, rear;
}Queue;

void init(Queue* Q) {
	Q->front = Q->rear = -1;
}
int isEmpty(Queue* Q) {
	if (Q->front == Q->rear)
		return 1;
	return 0;
}
int isFull(Queue* Q) {
	if (Q->rear == SIZE - 1)
		return 1;
	return 0;
}
void enqueue(Queue* Q, int e) {
	if (!isFull(Q)) {
		Q->rear++;
		Q->data[Q->rear] = e;
	}
}
int dequeue(Queue* Q) {
	if (!isEmpty(Q)) {
		Q->front++;
		return Q->data[Q->front];
	}
	else {
		return -1;
	}
}

int front(Queue* Q) {
	if (!isEmpty(Q)) {
		return Q->data[Q->front + 1];
	}
	else {
		return -1;
	}
}

int back(Queue* Q) {
	if (!isEmpty(Q)) {
		return Q->data[Q->rear];
	}
	else {
		return -1;
	}
}

int main() {
	int loop = 0;
	scanf("%d", &loop);

	Queue Queue;
	init(&Queue);

	while (loop > 0) {
		loop--;
		char command[10];
		scanf("%s", command);
		if (!strcmp(command, "push")) {
			//정수 X를 큐에 넣는 연산이다.
			int num = 0;
			scanf("%d", &num);
			enqueue(&Queue, num);
		}
		else if (!strcmp(command, "pop")) {
			printf("%d\n", dequeue(&Queue));
		}
		else if (!strcmp(command, "size")) {
			printf("%d\n", Queue.rear - Queue.front);
		}
		else if (!strcmp(command, "empty")) {
			printf("%d\n", isEmpty(&Queue));
			// 큐가 비어있으면 1, 아니면 0을 출력한다.
		}
		else if (!strcmp(command, "front")) {
			printf("%d\n", front(&Queue));
			//큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		}
		else if (!strcmp(command, "back")) {
			printf("%d\n", back(&Queue));
			//큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		}
	}
}