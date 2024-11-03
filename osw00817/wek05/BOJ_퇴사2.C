#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* day;
int* prize;
int memorization[1500001] = { 0 };
int cal(int i, int finish) {
	if (memorization[i] != 0) {
		return memorization[i];
	}
	if (i + day[i] < finish) {
		memorization[i] = prize[i] + cal(i + day[i], finish);
		return memorization[i];
	}
	else if (i + day[i] == finish) {
		memorization[i] = prize[i];
		return memorization[i];
	}
	return 0;
}

int main() {
	int loop = 0;
	scanf("%d", &loop);
	day = malloc(sizeof(int) * (loop + 1));
	prize = malloc(sizeof(int) * (loop + 1));
	for (int i = 0; i < loop; i++) {
		int tmp1 = 0;
		int tmp2 = 0;
		scanf("%d %d", &tmp1, &tmp2);
		day[i] = tmp1;
		prize[i] = tmp2;
	}

	int max = 0;
	for (int i = 0; i < loop; i++) {
		int tmp = cal(i, loop);
		max = (tmp > max) ? tmp : max;
	}
	printf("%d", max);

	free(day);
	free(prize);
}

