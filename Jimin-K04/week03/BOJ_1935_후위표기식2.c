//성공
#include <stdio.h>
#include <string.h>

char Postfix[101];
int operands[26], top = -1;
float num1, num2, stack[100];

void push(float X);
float pop(void);

int main(void)
{
	int N;
	scanf("%d", &N);
	scanf("%s", &Postfix);
	int len = strlen(Postfix);

	for (int i = 0; i < N; i++) {
		scanf("%d", &operands[i]);
	}

	for (int i = 0; i < len; i++) {
		if (Postfix[i] <= 'Z' && Postfix[i] >= 'A') {
			push(operands[Postfix[i] - 65]);
		}
		else {
			num2 = pop();
			num1 = pop();
			switch (Postfix[i]) {
			case '+':
				push(num1 + num2);
				break;
			case '-':
				push(num1 - num2);
				break;
			case '*':
				push(num1 * num2);
				break;
			case '/':
				push(num1 / num2);
				break;
			}
		}
	}
	printf("%.2f", stack[top]);
}

void push(float X)
{
	stack[++top] = X;
}

float pop(void)
{
	return stack[top--];
}
