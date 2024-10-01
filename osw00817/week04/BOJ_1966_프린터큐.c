#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10000
//사이즈 임의 설정
// 대충 이정도면 되겠지 마인드

//FIFO - QUEUE
// 1. 문서의 중요도를 확인
// 2. 중요도가 높은 문서가 하나라도 있다면, 이 문서를 QUEUE 가장 뒤에 배치

typedef struct {
	int priority[SIZE];
	int front, rear, tindex;
}queue;

void init(queue* q, int target) {
	q->front = q->rear = -1;
	q->tindex = target;
}

void enqueue(queue* q, int e) {
	q->rear++;
	q->priority[q->rear] = e;
}

int dequeue(queue* q) {
	q->front++;
	return q->priority[q->front];
}

int main() {
	int loop = 0;
	scanf("%d", &loop);

	while (loop > 0) {
		loop--;
		int num, target, cnt = 0;
		queue q;
		scanf("%d", &num); //문서의 갯수
		scanf("%d", &target); // 타겟 문서 인덱스
		init(&q, target);
		for (int i = 0; i < num; i++) {
			// 중요도 배치
			int tmp;
			scanf("%d", &tmp);
			enqueue(&q, tmp);
		}
		//반복문을 통해서 뒤에 있는 인덱스와 모두 중요도를 모두 비교하여 print
		for (int i = (q.front) + 1; i < q.rear + 1; i++) {
			int check = 1;
			for (int j = (q.front) + 2; j < q.rear + 1; j++) {
				if (q.priority[i] < q.priority[j]) {
					check = 0;
					if (i == q.tindex) {
						q.tindex = (q.rear + 1);
					}
					enqueue(&q, dequeue(&q));
					break;
				}
			}
			if (check) {
				dequeue(&q);
				cnt++;
				if (i == q.tindex) {
					printf("%d\n", cnt);
					break;
				}
			}
		}
	}
}
