#include <stdio.h>
#include <string.h>
#include <ctype.h> //알파벳인지 판단하는 isalpha() 함수 사용, 알파벳이 아닐 경우 0을 반환
/*다음이 연산자인데 변수를 받는 경우(postfix 알파벳)와 다음이 연산자 이지만 변수를 받지 않는 경우(postfix 연산자) 두개로 나뉨*/
int main(void)
{
	int N, top = -1, same_check[27] = { 0 }; // 앞서 같은 알파벳이 나왔는지 체크하는 배열(A == 1,B == 2...)
	float stack[26], tmp; //나누기 계산을 위해 임시로 입력된 수를 저장하는 tmp 와 stack 은 float 타입
	char Postfix[101]; //후위 표기식 저장하는 배열
	scanf("%d", &N);
	scanf("%s", Postfix);

	int postfix_len = strlen(Postfix);
	for (int i = 0; i < postfix_len - 1; i++) { //인덱스 초과 방지 위해 -1
		if (Postfix[i + 1] == '*') { // 다음 인덱스 값이 연산자인지 판단
			if (isalpha(Postfix[i])) { // 현재가 알파벳일 경우
				if (!same_check[Postfix[i] - 64]) { //앞서 같은 알파벳이 없으면
					scanf("%f", &tmp); // 만약 현재 postfix 값이 알파벳일 경우 숫자를 입력 받음
					stack[top] = stack[top] * tmp; // top 에 계산한 값을 저장함
				}
				else { //같은 알파벳이 있으면
					stack[top] *= stack[top]; //그전 수를 지금 들어온 수로 취급
				}
			}
			else {
				tmp = stack[top] * stack[top - 1]; //새로 받은 숫자가 없을 경우 스택에 저장된 가장 최근 두 수로 계산
				stack[--top] = tmp; //새로 계산한 값을 스택의 top 에 저장. 이때 스택의 가장 최근 2수를 계산 했으므로 top--
			}
		}

		else if (Postfix[i + 1] == '+') {
			if (isalpha(Postfix[i])) {
				if (!same_check[Postfix[i] - 64]) {
					scanf("%f", &tmp);
					stack[top] = stack[top] + tmp;
				}
				else {
					stack[top] += stack[top];
				}
			}
			else {
				tmp = stack[top] + stack[top - 1];
				stack[--top] = tmp;
			}
		}

		else if (Postfix[i + 1] == '-') {
			if (isalpha(Postfix[i])) {
				if (!same_check[Postfix[i] - 64]) {
					scanf("%f", &tmp);
					stack[top] = stack[top] - tmp;
				}
				else {
					stack[top] -= stack[top];
				}
			}
			else {
				tmp = stack[top - 1] - stack[top];
				stack[--top] = tmp;
			}
		}

		else if (Postfix[i + 1] == '/') {
			if (isalpha(Postfix[i])) {
				if (!same_check[Postfix[i] - 64]) {
					scanf("%f", &tmp);
					stack[top] = stack[top] / tmp;
				}
				else {
					stack[top] /= stack[top];
				}
			}
			else {
				tmp = (float)stack[top] / stack[top - 1];
				stack[--top] = tmp;
			}
		}

		else if (isalpha(Postfix[i + 1]) && isalpha(Postfix[i])) { //현재와 다음 모두 알파벳일 경우 입력받고 top에 저장
			if (!same_check[Postfix[i] - 64]) { //앞서 같은 알파벳이 없으면
				scanf("%f", &tmp);
				stack[++top] = tmp;
			}
			else { //같은 알파벳이면
				stack[top + 1] = stack[top];
				top++;
			}
		}

		if (isalpha(Postfix[i])) same_check[Postfix[i] - 64] = 1;

	}

	printf("%.2f", stack[top]); //stack의 top 에 최종 계산 결과가 저장됨
}
