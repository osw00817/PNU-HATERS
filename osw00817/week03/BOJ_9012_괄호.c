#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int top = -1;

int main(void) {
	int loop = 0;
	scanf("%d", &loop);
	while (loop > 0) {
		loop--;
		char VPS[51];
		scanf("%s", &VPS);
		int i, length = strlen(VPS);
		for (int i = 0; i < length; i++) {
			if (VPS[i] == '(') {
				++top;
			}
			else {
				if (top < 0) {
					printf("NO\n");
					break;
				}
				top--;
			}
			if (i == (length - 1)) {
				if (top == -1) {
					printf("YES\n");
				}
				else {
					printf("NO\n");
				}
			}
		}
		top = -1;
	}
}