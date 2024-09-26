#include <stdio.h>
#include <string.h>

int front = -1, rear = -1, queue[10000]; //front 와 rear 값 모두 증가만 함
void push(int X);
void pop(void);
int main(void)
{
	int N, X; //push 한 수를 X에 저장
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
			if (front == -1) printf("0\n"); //초기 상태
			else printf("%d\n", rear - front + 1); //큐의 크기 출력, front > rear 일 경우(큐 크기 0)에도 성립(front = rear + 1 이므로..)
			break;
		case 'e':
			if (front > rear || front == -1) printf("1\n");
			else printf("0\n");
			break;
		case 'f':
			if (front > rear || front == -1) printf("-1\n");
			else printf("%d\n", queue[front]);
			break;
		case 'b':
			if (front > rear || front == -1) printf("-1\n");
			else printf("%d\n", queue[rear]);
			break;
		}
	}
}

void push(int X)
{
	if (front == -1) ++front; //처음 수를 push 할때
	queue[++rear] = X; //받은 수를 rear 값을 증가시키면서 큐에 넣기
}

void pop(void)
{
	if (front > rear || front == -1) printf("-1\n"); // front 가 rear 보다 커지면 큐에 수가 존재 X && 초기상태
	else printf("%d\n", queue[front++]);
}
