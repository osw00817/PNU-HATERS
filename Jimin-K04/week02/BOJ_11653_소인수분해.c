#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int N, idx = 0; // prime_nums 의 인덱스 값이 소수임.
	
	scanf("%d", &N);
	int* prime_nums = malloc(sizeof(int) * (N + 1));
	//에라스토테네스의 체 -- 소수판별
	prime_nums[0] = prime_nums[1] = 0; //0과 1은 소수가 아님
	for (int i = 2; i <= N; i++) //1부터 N까지 배열 만들기
	{
		prime_nums[i] = 1;//모두 소수로 초기화
	}
	for (int i = 2; i <= sqrt(N); i++) //
	{
		for (int j = i*i; j <= N; j += i)
		{
			prime_nums[j] = 0; //2부터 루트 N 까지의 자기자신이 아닌 배수들 모두 지우기
		}
	}
	//소인수 출력
	while (N != 1) //소수로 계속 나눠서 몫이 1이될때까지 반복
	{
		while (prime_nums[idx] < 1 && idx <= N) idx++; //소수가 아니고 인덱스 범위를 넘지 않을때까지 인덱스++
		if (N % idx == 0)
		{
			printf("%d\n", idx);
			N /= idx; //N 을 소수로 나눈 몫을 다시 N에 저장
		}
		else idx++;
	}
	free(prime_nums);
}
