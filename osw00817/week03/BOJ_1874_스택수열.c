#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char result[200002];
	int loop, data[100001], cnt = 0, top = -1, tmp = 0, error = 0;
	scanf("%d", &loop);

	while (loop > 0) {
		loop--;
		int num;
		scanf("%d", &num);
		if (cnt < num) {
			while (num != cnt) {
				data[++top] = ++cnt;
				result[tmp++] = '+';
			}
			result[tmp++] = '-';
			top--;
		}
		else if (cnt > num) {
			if (data[top] == num) {
				top--;
				result[tmp++] = '-';
			}
			else {
				error = 1;
			}
		}
		else {
			error = 1;
		}
	}
	if (error != 1) {
		for (int i = 0; i < tmp; i++) {
			printf("%c\n", result[i]);
		}
	}
	else {
		printf("NO");
	}

	return 0;
}