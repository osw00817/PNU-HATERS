#include <stdio.h>
#include <string.h>
#define MAX 100000
/*스택의 크기는 현재 레이저에 영향을 받는 막대기의 개수를 뜻함, 즉 레이저를 쏘면 스택의 크기만큼 막대기 개수가 늘어남*/

char input[MAX]; //입력받은 괄호 배열 저장
int main(void)
{
	int top = -1, cnt = 0; //스택의 top 과 최종 개수 변수 선언
	scanf("%s", input);
	int input_len = strlen(input);

	for (int i = 0; i < input_len; i++) {
		if (input[i] == '(') {
			if (input[i + 1] == ')') {
				cnt += (top + 1); //레이저일 경우 스택 크기를 더하기
				i++; //레이저 다음으로 넘기기
			}
			else {//막대기 추가일 경우
				top++; //막대기 더할때 마다 스택에 저장됨
				cnt++; //총 막대기 수가 늘어남
			}
		}
		else top--; //막대기의 끝을 나타냄
	}

	printf("%d", cnt);
}
