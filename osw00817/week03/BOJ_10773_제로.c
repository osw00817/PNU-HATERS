#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int data[100001];
int top = -1;

int main(void) {
	int loop;
	scanf("%d", &loop);
	while (loop > 0) {
		loop--;
		int num;
		scanf("%d", &num);
		if (num != 0) {
			data[++top] = num;

		}
		else {
			top--;
		}
	}
	if (top == -1) {
		printf("%d", 0);
		return 0;
	}

	int sum = 0;
	for (int i = 0; i <= top; i++) {
		sum += data[i];
	}

	printf("%d", sum);
	return 0;
}