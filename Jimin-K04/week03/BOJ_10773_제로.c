#include <stdio.h>
#define MAX 100000

int main(void)
{
	int K, tmp, stack[MAX], top = -1, sum = 0;
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		scanf("%d", &tmp);
		if (!tmp) top--;
		else stack[++top] = tmp;
	}

	for (int i = 0; i <= top; i++) {
		sum += stack[i];
	}
	printf("%d", sum);
}
