#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define _CRT_SECURE_NO_WARNINGS

int* queue;
int rear = 0, front = 0, DocIndex = 0, QueueCount = 0, count = 0;

void enqueue(int value, int size) {
	QueueCount++;
	queue[rear] = value;
	rear = (rear + 1) % size;
}
void dequeue(int size) {
	front = (front + 1) % size;
	QueueCount--;

}

int check(int size) {
	int check = 0; 
	for (int i = (front + 1)%size; i != rear; i = (i + 1) % size) {
		if (queue[front] < queue[i]) {
			check = 1;
			break;
		}
	}
	
	if (check) {
		dequeue(size);
		int PastFront = (front - 1 + size) % size;
		enqueue(queue[PastFront], size);
		if (PastFront == DocIndex) {
			DocIndex = (rear - 1 + size) % size;  // DocIndex가 큐의 끝으로 이동
		}
	
	
	}
	else {
		count++;
		if (front == DocIndex) {
			printf("%d\n", count);
			return 1;
		}
		dequeue(size);
		
	}
	return 0;
	
}

int main() {
	int TestCase;
	scanf("%d", &TestCase);
	for (int i = 0; i < TestCase; i++) {
		int N;//N은 문서의 개수
		count = 0;
		scanf("%d %d", &N, &DocIndex);
		int QueueSize = N;
		queue = (int*)malloc(QueueSize * sizeof(int));
		memset(queue, 0, QueueSize * sizeof(int));;//0로초기화,check 함수때문
		for (int j = 0; j < N; j++) {
			int value;
			scanf("%d", &value);//queue에 입력
			enqueue(value, QueueSize);
		}

		while (QueueCount > 0) {
			if(check(QueueSize)) break;
		}
			
		free(queue);
		rear = 0; front = 0; QueueCount = 0;
	}


	return 0;
}

