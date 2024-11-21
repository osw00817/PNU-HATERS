/*가장 높은 나무의 크기를 max 로 잡고 1과 max 사이 중간값을 h의 기준값으로 잡음.
이후 h 일때 자른 것들의 합이 가져가려는 나무보다 크면 오른쪽을 범위로 잡고 작으면 왼쪽을 범위로 잡음
만약 값들의 합이 가져가려는 나무의 길이와 정확히 떨어지지 않는다면 min > max 인 상황이 생기고 이때는 가장 근사값이 될것
 예를 들어 4 5 이렇게 남으면  min = 4, max = 5, mid = 9/2 = 4 가 되고 , 
 합이 답보다 작은 경우 max = 3 min = 4 가 되면서 종료,
 합이 답보다 큰 경우 min = 6, max = 5 가 되면서 종료
 답은 max 가 됨*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	long long M, max = 0, mid = 0, min = 1, sum = 0;
	scanf("%d %lld", &N, &M);
	long long* trees = malloc(sizeof(long long) * N);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &trees[i]);
		if (trees[i] > max) max = trees[i];
	}
	mid = max / 2;

	while (min <= max) {
		sum = 0;
		mid = (max + min) / 2;
		for (int i = 0; i < N; i++) {
			if (trees[i] - mid > 0) sum += (trees[i] - mid);
		}
		if (sum == M) {
			printf("%lld", mid);
			return 0;
		}
		if (sum > M) min = mid + 1;
		else max = mid - 1;
	}
	printf("%lld", max);
}
//일단 풀긴 했는데 왜 mid +1, mid-1 이렇게 하면 틀리는 건지 모르겟음
