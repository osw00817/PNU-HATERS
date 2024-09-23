#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다.
만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다.
만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

int data[10001] = { 0 };
int top = -1;

int main() {
	int loop;
	scanf("%d", &loop);
	while (loop > 0) {
		loop--;
		char command[20];
		scanf("%s", command);
		if (strcmp(command, "pop") == 0) {
			printf("%d\n", (top < 0) ? -1 : data[top--]);
		}
		else if (strcmp(command, "size") == 0) {
			printf("%d\n", top + 1);
		}
		else if (strcmp(command, "empty") == 0) {
			printf("%d\n", (top < 0) ? 1 : 0);
		}
		else if (strcmp(command, "top") == 0) {
			printf("%d\n", (top < 0) ? -1 : data[top]);
		}
		else {
			int num;
			scanf("%d", &num);
			data[++top] = num;
		}
	}
	return 0;
}