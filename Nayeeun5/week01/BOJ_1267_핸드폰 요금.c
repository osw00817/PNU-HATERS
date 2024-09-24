#include <stdio.h>

int main(void) {
	int n, t, y=0, m=0;
	scanf_s("%d", &n);
	for (int i=0; i < n; i++) {
		scanf_s("%d", &t);
		y += (t / 30 + 1) * 10;
		m += (t / 60 + 1) * 15;
	}
	if (m > y)
		printf("Y %d", y);
	else if (m < y)
		printf("M %d", m);
	else
		printf("Y M %d", y);

	return 0;
}
