#include<stdio.h>
int main() {
	int N, M;
	int floor[10001] = { 0 };
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M;i++) {
		int left, right;
		scanf("%d %d", &left, &right);
		floor[left] = floor[right]= i;
	}
	N %= 2 * M;
	if (N == 0) N = 2 * M;
	int ans = 1;
	for (int i = 0; i < 10001; i++) {
		if (floor[i] != 0) {
			if (ans == N) {
				printf("%d", floor[i]);
				return 0;
			}
			else ans++;
		}
	}
}
