#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 2000000

typedef struct {
	long data[SIZE];
	int front, rear;
} Queue;

void init(Queue* Q) {
	Q->front = Q->rear = -1;
}

int isEmpty(Queue* Q) {
	if (Q->front == Q->rear) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFull(Queue* Q) {
	return Q->rear == SIZE - 1;
}

int enqueue(Queue* Q, int e) {
	if (!isFull(Q)) {
		Q->rear = (Q->rear + 1) % SIZE;
		Q->data[Q->rear] = e;
	}
}

int dequeue(Queue* Q) {
	if (isEmpty(Q)) {
		return -1;
	}
	else {
		Q->front = (Q->front + 1) % SIZE;
		return Q->data[Q->front];
	}
}

int size(Queue* Q) {
	return (Q->rear > Q->front) ? Q->rear - Q->front : Q->front - Q->rear;
}

int front(Queue* Q) {
	if (isEmpty(Q)) {
		return -1;
	}
	return Q->data[(Q->front + 1) % SIZE];
}

int back(Queue* Q) {
	if (isEmpty(Q)) {
		return -1;
	}
	return Q->data[Q->rear];
}

int main() {
	int loop = 0;
	scanf("%d", &loop);
	Queue q;
	init(&q);
	while (loop > 0) {
		loop--;
		char command[20];
		scanf("%s", command);
		if (!strcmp(command, "push")) {
			int num;
			scanf("%d", &num);
			enqueue(&q, num);
		}
		else if (!strcmp(command, "pop")) {
			printf("%d\n", dequeue(&q));
		}
		else if (!strcmp(command, "size")) {
			printf("%d\n", size(&q));
		}
		else if (!strcmp(command, "empty")) {
			printf("%d\n", isEmpty(&q));
		}
		else if (!strcmp(command, "front")) {
			printf("%d\n", front(&q));
		}
		else if (!strcmp(command, "back")) {
			printf("%d\n", back(&q));
		}
	}
	return 0;
}
