#include<stdio.h>
#include<stdlib.h>
int MAX(int x, int y) {
	return (x > y) ? x : y;
}

int main() {
	int N,t,p, _max=0,finish;
	scanf("%d", &N);
	int* dp = malloc(sizeof(int) * (N + 1));
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &t, &p);
		_max = MAX(_max, dp[i]);
		finish = i + t;
		if (finish <= N)
			dp[finish] = MAX(_max + p, dp[finish]);
	}
	printf("%d",MAX(_max,dp[N]));
	free(dp);
	return 0;
}
