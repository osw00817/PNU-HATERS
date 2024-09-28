#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 반례좀 찾아주세요..

typedef struct {
	int data[1000000];
	int front, rear;
}Queue;

void init(Queue* q) {
	q->front = q->rear = -1;
}

int isEmpty(Queue* q) {
	return q->front == q->rear;
}

int isFull(Queue* q) {
	return q->rear == 499999;
}

int enqueue(Queue* q, int e) {
	if (!isFull(q)) {
		q->rear++;
		q->data[q->rear] = e;
	}
}

int dequeue(Queue* q) {
	if (!isEmpty(q)) {
		q->front++;
		return q->data[q->front];
	}
}

int main() {
	int n = 0;
	scanf("%d", &n);
	Queue q;
	init(&q);
	if (n == 1) {
		printf("%d", 1);
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		enqueue(&q, i);
	}
	while (1) {
		dequeue(&q);
		if (q.front == q.rear - 1 && q.front != -1) {
			printf("%d", dequeue(&q));
			break;
		}
		enqueue(&q, dequeue(&q));
	}
	return 0;
}