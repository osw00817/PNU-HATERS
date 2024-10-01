#include <stdio.h>
#include <math.h>
#define MAX 10000

int main(void)
{
	int T, n, n_sqr, G_p1, idx; //p1과 골드바흐 파티션 중 하나

	scanf("%d", &T);
	
	for (int j = 0; j < T; j++)
	{
		scanf("%d", &n);
		if (n == 4)
		{
			printf("2 2\n");
			continue;
		}
	
		int prime_list[MAX + 1] = { 0 }; //소수이면 0, 소수가 아니면 1
		prime_list[0] = prime_list[1] = 1;
		int new_list[MAX / 2];

		//에라토스테네스의 체 -- 소수판별
		n_sqr = sqrt(n);
		for (int p_num = 2; p_num <= n_sqr; p_num++)
		{
			while (prime_list[p_num] > 0 && p_num <= n) p_num++;
			for (int i = p_num * p_num; i <= n; i += p_num) prime_list[i] = 1;
		}
		//2 부터 n 까지 소수이면
		idx = 0;
		for (int i = 2; i < n; i++)
		{
			if (prime_list[i] == 0) new_list[idx++] = i; //소수이면 값 저장, 이때 최종 idx 값은 새리스트(소수들의 리스트)의 길이가 됨.
		}
		if (idx % 2 != 0) idx--; //길이가 짝수가 아닌경우 짝수로 맞추기
		idx = idx / 2; // 소수의 리스트 중앙 인덱스
		while (prime_list[n - new_list[idx]] > 0) idx++; //n에서 해당 소수를 뺀 값이 소수가 될때까지 인덱스 증가
		G_p1 = (new_list[idx] > n - new_list[idx] ? new_list[idx] : n - new_list[idx]);
		
		printf("%d %d\n", n - G_p1, G_p1);
	}
}
--다시 푼 코드
#include <stdio.h>
#include <math.h>
#define MAX 10000

int main(void)
{
	int T, n, n_sqr, G_p1; //p1과 골드바흐 파티션 중 하나
	int prime_list[MAX + 1] = { 0 }; //소수이면 0, 소수가 아니면 1

	scanf("%d", &T);
	
	for (int j = 0; j < T; j++)
	{
		scanf("%d", &n);
		if (n == 4)
		{
			printf("2 2\n");
			continue;
		}
	
		prime_list[0] = prime_list[1] = 1;

		//에라토스테네스의 체 -- 소수판별
		n_sqr = sqrt(n);
		for (int p_num = 2; p_num <= n_sqr; p_num++)
		{
			while (prime_list[p_num] > 0 && p_num <= n) p_num++;
			for (int i = p_num * p_num; i <= n; i += p_num) prime_list[i] = 1;
		}
		
		for (int i = n / 2; i < n; i++) {
			if (prime_list[i] == 0 && prime_list[n - i] == 0) {
				printf("%d %d\n", n - i, i);
				break;
			}
		}
	}
}
