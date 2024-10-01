#include <stdio.h>
#include <math.h>
#define Max 123456

int main(void)
{
	int N, cnt = 0;
	while (1)
	{
		int N, cnt = 0;
		scanf("%d", &N);
		if (N == 0) return 0;
		int prime_list[2 * Max + 1] = { 0 }; //인덱스가 소수이면 0, 아니면 1을 저장하는 배열

		prime_list[0] = prime_list[1] = 1; // 0과 1은 소수가 아님

		//에라토스테네스의 체 -- 소수판별
		for (int p_num = 2; p_num <= sqrt(2 * N); p_num++) //루트 n 까지만 판별
		{
			while (prime_list[p_num] > 0 && p_num <= 2 * N) p_num++; //소수가 아닌 수는 무시
			for (int i = p_num * p_num; i <= 2 * N; i += p_num) //한 소수의 배수가 i임.
			{
				prime_list[i] = 1; //소수의 배수는 소수가 아님
			}
		}
		//N 부터 2N 까지 소수이면 count++
		for (int i = N + 1; i <= 2 * N; i++)
		{
			if (prime_list[i] == 0) cnt++;
		}
		printf("%d\n", cnt);
	}
}
