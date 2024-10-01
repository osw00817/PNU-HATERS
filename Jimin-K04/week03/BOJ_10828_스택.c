#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10000

void push(int X);
void pop(void);
int top = -1, stack[MAX]; //top : 스택의 top 값이 저장되어있는 인덱스

int main(void)
{
	char cmd[20], *num_X; //명령을 저장할 배열, push 에서 삽입할 수를 저장할 배열의 포인터 주소
	int N; //명령 수
	scanf("%d", &N);
	getchar(); //fgets 함수가 버퍼에 남아있는 개행문자를 받지 않게 개행문자 제거

	for (int i = 0; i < N; i++) {
		fgets(cmd, 20, stdin);
		cmd[strcspn(cmd, "\n")] = '\0'; // fgets 함수는 문자열 끝에 개행문자를 추가, 이를 제거해야 아래 strcmp 가 작동 

		switch (cmd[0]) {
		case 'p':
			if (!strcmp(cmd, "pop")) pop();
			else {
				num_X = cmd + 5; // 아래설명
				push(atoi(num_X)); //문자열을 정수로 형변환
			}
			break;

		case 's':
			printf("%d\n", top + 1); //현재 저장된 수의 개수는 top + 1임. (top 이 0부터 1개 저장된것이기 때문)
			break;
		case 'e':
			if (top == -1) printf("1\n");
			else printf("0\n");
			break;
		case 't':
			if (top == -1) printf("-1\n");
			else printf("%d\n", stack[top]);
			break;
		}
	}
}

void push(int X) //stack 에 수를 push 했을때 top 을 1씩 늘려가면서 해당 인덱스에 저장
{
	stack[++top] = X;
}

void pop(void)
{
	if (top == -1) printf("-1\n");
	else {
		printf("%d\n", stack[top]);
		--top;
	}
}

/*strcmp 함수는 두 문자열을 비교하고 다음과 같은 값을 반환합니다 :
string compare
0: 두 문자열이 같을 때.
양수 : 첫 번째 문자열이 두 번째 문자열보다 사전 순으로 클 때.
음수 : 첫 번째 문자열이 두 번째 문자열보다 사전 순으로 작을 때.


배열은 포인터임 따라서 cmd 는 입력받은 배열의 맨 처음 문자의 주소이고, 
거기에 5를 더하면 수가 시작하는 문자의 주소가 num_X배열의 첫번째 문자 주소로 저장되는 것,,,,


strcspn(str1, str2) 함수는 str1 에서 str2 가 처음으로 등장하는 인덱스를 반환함

*/
