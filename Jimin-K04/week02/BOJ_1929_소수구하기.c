#include <stdio.h>
#include <math.h>
# define Max 1000000

int main(void)
{
	int M, N;
	scanf("%d %d", &M, &N);
	int prime_list[Max + 1] = { 0 }; //인덱스가 소수이면 0, 아니면 1을 저장하는 배열

	prime_list[0] = prime_list[1] = 1; // 0과 1은 소수가 아님

	//에라토스테네스의 체 -- 소수판별
	for (int p_num = 2; p_num <= sqrt(N); p_num++) //루트 n 까지만 판별
	{
		while (prime_list[p_num] > 0 && p_num <= N) p_num++; //소수가 아닌 수는 무시
		for (int i = p_num * p_num; i <= N; i += p_num) //한 소수의 배수가 i임.
		{
			prime_list[i] = 1; //소수의 배수는 소수가 아님
		}
	}
	//M 부터 N 까지 소수이면 출력
	for (int i = M; i <= N; i++)
	{
		if (prime_list[i] == 0) printf("%d\n", i);
	}
}
