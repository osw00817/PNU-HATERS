#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 10000

typedef int element;
typedef struct {
	element data[SIZE];
	int front, rear;
} DequeType;

void init_deque(DequeType* dq) {
	dq->front = 0;
	dq->rear = 0;
}
int is_empty(DequeType* dq) {
	if (dq->front == dq->rear)
		return 1;
	else
		return 0;
}
int is_full(DequeType* dq) {
	if (dq->front == (dq->rear + 1) % SIZE)
		return 1;
	else
		return 0;
}

void add_front(DequeType* dq, element item) {
	if (!is_full(dq)) {
		dq->data[dq->front] = item;
		dq->front = (dq->front - 1 + SIZE) % SIZE;
	}
}

void add_rear(DequeType* dq, element item) {
	if (!is_full(dq)) {
		dq->rear = (dq->rear + 1) % SIZE;
		dq->data[dq->rear] = item;
	}
}

int delete_front(DequeType* dq) {
	if (!is_empty(dq)) {
		dq->front = (dq->front + 1) % SIZE;
		return dq->data[dq->front];
	}
	else {
		return -1;
	}
}

int delete_rear(DequeType* dq) {
	if (!is_empty(dq)) {
		element item = dq->data[dq->rear];
		dq->rear = (dq->rear - 1 + SIZE) % SIZE;
		return item;
	}
	else {
		return -1;
	}
}

void print_deque(DequeType* dq) {
	printf("(front = %d rear = %d) = ", dq->front, dq->rear);
	if (!is_empty(dq)) {
		int i = dq->front;
		do {
			i = (i + 1) % SIZE;
			printf("%d | ", dq->data[i]);
			if (i == dq->rear)
				break;
		} while (i != dq->front);
		printf("\n");
	}
}
int main() {
	DequeType dq;
	init_deque(&dq);
	int num, loop = 0;
	scanf("%d", &loop);
	while (loop > 0) {
		loop--;
		char command[20];
		scanf("%s", command);
		switch (command[0])
		{
		case 'p':
			if (!strcmp(command, "push_front")) {
				scanf("%d", &num);
				add_front(&dq, num);
			}
			else if (!strcmp(command, "push_back")) {
				scanf("%d", &num);
				add_rear(&dq, num);
			}
			else if (!strcmp(command, "pop_front")) {
				printf("%d\n", delete_front(&dq));
			}
			else if (!strcmp(command, "pop_back")) {
				printf("%d\n", delete_rear(&dq));
			}
			break;
		case 's':
			printf("%d\n", (dq.front <= dq.rear) ? (dq.rear - dq.front) : (SIZE - dq.front + dq.rear));
			break;
		case 'e':
			printf("%d\n", is_empty(&dq));
			break;
		case 'f':
			printf("%d\n", (is_empty(&dq)) ? -1 : dq.data[(dq.front + 1) % SIZE]);
			break;
		case 'b':
			printf("%d\n", (is_empty(&dq)) ? -1 : dq.data[dq.rear]);
			break;
		}
	}
	return 0;
}
