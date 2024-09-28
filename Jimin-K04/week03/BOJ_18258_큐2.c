#include <stdio.h>
#include <string.h>
#define MAX 2000000

int front = 0, rear = 0, queue[MAX], N; //front 와 rear 값 모두 증가만 함
void push(int X);
void pop(void);
int main(void)
{
	int X; //push 한 수를 X에 저장
	scanf("%d", &N);
	char cmd[20]; //명령을 저장할 배열

	for (int i = 0; i < N; i++) {
		scanf("%s", cmd);

		switch (cmd[0]) {
		case 'p':
			if (!strcmp(cmd, "pop")) pop();
			else {
				scanf("%d", &X);
				push(X);
			}
			break;
		case 's':
			printf("%d\n", (rear - front + N) % N); //rear 가 범위를 넘어서 0으로 돌아갈 경우 큐의 크기는 rear - front + N 임
			break;
		case 'e':
			if (front == rear) printf("1\n");
			else printf("0\n");
			break;
		case 'f':
			if (front == rear) printf("-1\n");
			else printf("%d\n", queue[front]);
			break;
		case 'b':
			if (front == rear) printf("-1\n");
			else printf("%d\n", queue[rear - 1]);
			break;
		}
	}
}

void push(int X)
{
	queue[rear] = X;
	rear = (rear + 1) % N; //원형 큐 구현, 입력 명령개수가 N일때 최대 push 가능한 수는 N개임
}

void pop(void)
{
	if (front == rear) printf("-1\n"); // front와 rear 가 같으면 큐는 비어있음
	else {
		printf("%d\n", queue[front]);
		front = (front + 1) % N;
	}
}
