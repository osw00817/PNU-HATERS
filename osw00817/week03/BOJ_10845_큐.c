#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 10001

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
	return Q->front == Q->rear;
}
int isFull(Queue* Q) {
	return Q->rear == SIZE - 1;
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
}
int main() {
	int loop = 0;
	scanf("%d", &loop);

	Queue Queue;
	init(&Queue);

	while (loop > 0) {
		loop--;
		char command[6];
		scanf("%s", command);
		if (strcmp(command, "push") == 0) {
			//정수 X를 큐에 넣는 연산이다.
			int num = 0;
			scanf("%d", &num);
			enqueue(&Queue, num);
		}
		else if (strcmp(command, "pop") == 0) {
			//pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 
			//만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
			if (isEmpty(&Queue)) {
				printf("%d\n", -1);
			}
			else {
				printf("%d\n", dequeue(&Queue));
			}
		}
		else if (strcmp(command, "size") == 0) {
			printf("%d\n", Queue.rear - Queue.front);
		}
		else if (strcmp(command, "empty") == 0) {
			if (isEmpty(&Queue)) {
				printf("%d\n", 1);
			}
			else {
				printf("%d\n", 0);
			}
			// 큐가 비어있으면 1, 아니면 0을 출력한다.
		}
		else if (strcmp(command, "front") == 0) {
			if (isEmpty(&Queue)) {
				printf("%d\n", -1);
				break;
			}
			printf("%d\n", Queue.data[Queue.front + 1]);
			//큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		}
		else if (strcmp(command, "back") == 0) {
			if (isEmpty(&Queue)) {
				printf("%d\n", -1);
				break;
			}
			printf("%d\n", Queue.data[Queue.rear]);
			//큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		}
	}
}