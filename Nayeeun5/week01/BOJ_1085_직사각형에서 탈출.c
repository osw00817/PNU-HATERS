#include <stdio.h>
int main(void) {
	int x, y, w, h, dis;
	scanf_s("%d %d %d %d", &x, &y ,&w ,&h);
	dis = y;
	if (dis > h - y)
		dis = h - y;
	else if (dis > w - x)
		dis = w - x;
	else
		dis = x;
	printf("%d", dis);

	return 0;
}
