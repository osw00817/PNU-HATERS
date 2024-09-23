#include<stdio.h>

int main() {
	int str[101] = { 0 };
	int N, pos, cnt = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &pos);
		if (str [pos] == 0)
			str[pos]++;
		else
			cnt++;
	}
	printf("%d", cnt);
}
