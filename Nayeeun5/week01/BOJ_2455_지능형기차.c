#include <stdio.h>

int main(void) {
	int i, o, ans=0, sum=0;
	for (int n=0;n<4;n++){
		scanf("%d %d", &i, &o);
		sum -= i;
		sum += o;
		if (sum > ans)
			ans = sum;
	}
	printf("%d", ans);
}
