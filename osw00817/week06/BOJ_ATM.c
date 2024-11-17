#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int loop;
	scanf("%d", &loop);
	int max = loop;
	int list[1001];
	while (loop--) {
		int tmp;
		scanf("%d", &tmp);
		list[loop] = tmp;
	}
	int tmp = 0;
	int sum = 0;
	for (int i = max - 1; i >= 0; i--) {
		tmp += list[i];
		sum += tmp;
		//printf("%d %d\n", tmp, sum);
	}
	printf("%d", sum);
	return 0;
}