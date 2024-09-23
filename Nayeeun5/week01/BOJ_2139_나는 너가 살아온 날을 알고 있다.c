#include <stdio.h>

int main(void) {
	int d, m, y;
	while (1) {
		scanf_s("%d %d %d", &d, &m, & y);
		if (d == 0 && m == 0 && y == 0) break;
		for (int i = 1; i < m; i++) {
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				d += 31;
			else if (i == 2) {
				if (y % 4 == 0) {
					if (y % 400 == 0)
						d += 29;
					else if (y % 100 == 0)
						d += 28;
					else
						d += 29;
				}
				else
					d += 28;
			}
			else
				d += 30;
		}
		printf("%d\n", d);
	}
}
