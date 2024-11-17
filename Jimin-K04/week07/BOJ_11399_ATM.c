#include <stdio.h>
#define MAX 1000

int main(void)
{
	int N, max_num = 0, max_idx, tmp_idx, sum = 0;
	int times[MAX];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &times[i]);
	}
  //배열에서 최댓값을 찾아서 마지막 인덱스 값이랑 교환해서 정렬함(매 반복마다 마지막 인덱스 값을 하나씩 줄여간다)
	max_idx = N - 1;
	while (max_idx >= 0) {
		max_num = 0;
		for (int i = 0; i <= max_idx; i++) {
			if (times[i] > max_num) {
				max_num = times[i];
				tmp_idx = i;
			}
		}
		times[tmp_idx] = times[max_idx];
		times[max_idx] = max_num;
		max_idx--;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			sum += times[j];
		}
	}
	printf("%d", sum);
}
