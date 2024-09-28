#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char data[100001];
int top = -1;
int cnt = 0;
/*
(를 세면 push
()인경우 (갯수만큼 sum에 추가
)를 세면 pop
pop 하면서 1개 추가
*/
int main() {
	char input[100001];
	scanf("%s", input);
	for (int i = 0; i < strlen(input); i++) {
		//printf("%d %c %d\n", i, input[i], cnt);
		if (input[i] == '(') {
			if (input[i + 1] == ')') {
				// 레이저
				cnt += (top == -1) ? 0 : top + 1;
				i++;
			}
			else {
				// 쇠막대기 시작
				// push
				data[++top] = '(';
			}
		}
		else {
			// 쇠막대기 마무리
			// pop
			top--;
			cnt += 1;
		}
	}
	printf("%d", cnt);
}