#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 2000001

//구현 실패

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
		Q->rear++;
		Q->data[Q->rear] = e;
	}
}

int dequeue(Queue* Q) {
	if (isEmpty(Q) == 0) {
		return -1;
	}
	else {
		Q->front++;
		return Q->data[Q->front];
	}
}

int size(Queue* Q) {
	return Q->rear - Q->front;
}

int front(Queue* Q) {
	if (isEmpty(Q) == 0) {
		return -1;
	}
	return Q->data[Q->front + 1];
}

int back(Queue* Q) {
	if (isEmpty(Q) == 0) {
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
		if (strcmp(command, "push")) {
			int num;
			scanf("%d", &num);
			enqueue(&q, num);
		}
		else if (strcmp(command, "pop")) {
			printf("%d\n", dequeue(&q));
		}
		else if (strcmp(command, "size")) {
			printf("%d\n", size(&q));
		}
		else if (strcmp(command, "empty")) {
			printf("%d\n", isEmpty(&q));
		}
		else if (strcmp(command, "front")) {
			printf("%d\n", front(&q));
		}
		else if (strcmp(command, "back")) {
			printf("%d\n", back(&q));
		}
	}
	return 0;
}
