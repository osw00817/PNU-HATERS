#include <stdio.h>

int main(void) {
	int n, a, b, c, res = 0, ans=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == b && b == c)
			res = 10000 + a * 1000;
		else if (a == b || a == c)
			res = 1000 + a * 100;
		else if (b == c)
			res = 1000 + b * 100;
		else
			if (a > b && a > c)
				res = a * 100;
			else if (b > a && b > c)
				res = b * 100;
			else
				res = c * 100;
		if (res > ans)
			ans = res;
	}
	printf("%d", ans);
}
