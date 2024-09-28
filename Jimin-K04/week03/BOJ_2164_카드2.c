#include <stdio.h>
#define MAX 1000000

int queue[MAX], front = 0, rear = -1;

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) { //1부터 N 까지 큐에 저장
		queue[++rear] = i + 1;
	}
	while (front != rear) { //front == rear 이면 반복을 멈춤 --> 수가 하나만 남은것
		front++; //가장 위의 카드 버림
		queue[++rear] = queue[front++]; //가장 위 카드를 꼬리로 옮김
	}

	printf("%d", queue[rear]); //마지막 남는 카드 출력
}
