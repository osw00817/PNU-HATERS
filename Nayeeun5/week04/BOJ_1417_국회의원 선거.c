#include<stdio.h>
int main() {
	int N, Da, cnt = 0;
	int M[51];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &M[i]);
	if (N == 1) {
		printf("0");
		return 0;
	}
	Da = M[0];
	while (1) {
		int max = 0, index = 0;
		for (int i = 1; i < N; i++) {
			if (M[i] > max) {
				max = M[i];
				index = i;
			}
		}
		if (Da > max)
			break;
		M[index]--;
		Da++;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}
