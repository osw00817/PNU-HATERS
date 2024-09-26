#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int nums[27];
char operands[100];
int top = -1;

int main() {
	int loop, cnt = -1;
	float tmp = 0.00;
	char data[101];
	scanf("%d", &loop);
	scanf("%s", data);

	for (int i = 0; i < loop; i++) {
		int tmp;
		scanf("%d", &tmp);
		nums[i] = tmp;
	}

	for (int i = 0; i < strlen(data); i++) {
		printf("%s의%d번째값: %c %d | %d \n", data, i, data[i], data[i], tmp);
		if (65 <= data[i] && data[i] <= 90) {
			++cnt;	
			operands[++top] = nums[cnt];
		}
		else {
			if (data[i] == '+') {
				//더하기
				tmp = atof(operands[top - 1]) + atof(operands[top]);
				top--;
				operands[top] = tmp;
			}
			else if (data[i] == '-') {
				tmp = atof(operands[top - 1]) - atof(operands[top]);
				top--;
				operands[top] = tmp;
			}
			else if (data[i] == '/') {
				//나누기
				tmp = atof(operands[top - 1]) / atof(operands[top]);
				top--;
				operands[top] = tmp;
			}
			else {
				//곱하기
				tmp = atof(operands[top - 1]) * atof(operands[top]);
				top--;
				operands[top] = tmp;
			}
		}
		for (int i = 0; i < strlen(operands); i++) {
			printf("%.2f ", (float)(operands[i]));
		}
		printf("\n");
	}
	printf("%.2f", (float)operands[0]);
}