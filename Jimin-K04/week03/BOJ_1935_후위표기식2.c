#include <stdio.h>
#include <string.h>
#include <ctype.h> //알파벳인지 판단하는 isalpha() 함수 사용, 알파벳이 아닐 경우 0을 반환
//다음이 연산자인데 변수를 받는 경우(postfix 알파벳)와 다음이 연산자 이지만 변수를 받지 않는 경우(postfix 연산자) 두개로 나뉨
int main(void)
{
	int N, top = -1, last_num;
	float stack[26], tmp; //나누기 계산을 위해 임시로 입력된 수를 저장하는 tmp 와 stack 은 float 타입
	char Postfix[101], last_char = '#'; //후위 표기식 저장하는 배열
	scanf("%d", &N);
	scanf("%s", Postfix);

	int postfix_len = strlen(Postfix);
	for (int i = 0; i < postfix_len - 1; i++) { //인덱스 초과 방지 위해 -1
		if (Postfix[i + 1] == '*') { // 다음 인덱스 값이 연산자인지 판단
			if (isalpha(Postfix[i])) {// 만약 현재 postfix 값이 알파벳일 경우
				if (Postfix[i] != last_char) { //이전 알파벳과 다르면 입력받고
					scanf("%f", &tmp);
					last_num = tmp; //마지막으로 입력받은 수를 변수에 넣기
				}
				else tmp = last_num; //같으면 tmp 에 이전에 입력받은 수를 저장
				stack[top] = stack[top] * tmp; // top 에 계산한 값을 저장함
				last_char = Postfix[i];
			}
			else {
				tmp = stack[top] * stack[top - 1]; //새로 받은 숫자가 없을 경우 스택에 저장된 가장 최근 두 수로 계산
				stack[--top] = tmp; //새로 계산한 값을 스택의 top 에 저장. 이때 스택의 가장 최근 2수를 계산 했으므로 top--
			}
		}

		else if (Postfix[i + 1] == '+') {
			if (isalpha(Postfix[i])) {
				if (Postfix[i] != last_char) {
					scanf("%f", &tmp);
					last_num = tmp;
				}
				else tmp = last_num;
				stack[top] = stack[top] + tmp;
				last_char = Postfix[i];
			}
			else {
				tmp = stack[top] + stack[top - 1];
				stack[--top] = tmp;
			}
		}

		else if (Postfix[i + 1] == '-') {
			if (isalpha(Postfix[i])) {
				if (Postfix[i] != last_char) {
					scanf("%f", &tmp);
					last_num = tmp;
				}
				else tmp = last_num;
				stack[top] = stack[top] - tmp;
				last_char = Postfix[i];
			}
			else {
				tmp = stack[top - 1] - stack[top];
				stack[--top] = tmp;
			}
		}

		else if (Postfix[i + 1] == '/') {
			if (isalpha(Postfix[i])) {
				if (Postfix[i] != last_char) {
					scanf("%f", &tmp);
					last_num = tmp;
				}
				else tmp = last_num;
				stack[top] = stack[top] / tmp;
				last_char = Postfix[i];
			}
			else {
				tmp = (float)stack[top] / stack[top - 1];
				stack[--top] = tmp;
			}
		}

		else if (isalpha(Postfix[i + 1]) && isalpha(Postfix[i])) { //현재와 다음 모두 알파벳일 경우 입력받고 top에 저장
				if (Postfix[i] != last_char) {
					scanf("%f", &tmp);
					last_num = tmp;
				}
				else tmp = last_num;
				stack[++top] = tmp;
				last_char = Postfix[i];
		}
	}

	printf("%.2f", stack[top]); //stack의 top 에 최종 계산 결과가 저장됨
}
