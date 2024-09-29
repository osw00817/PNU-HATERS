#include <stdio.h>
#include <math.h> // 제곱근 반환하는 함수 sqrt 사용하기 위한 헤더파일

int main(void)
{
	int N, prime_num, prime_cnt = 0; // N :주어질 수의 개수
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int check = 1; //소수인지 아닌지 체크
		scanf("%d", &prime_num);
		
		if (prime_num == 1) check = 0;

		int s_root = sqrt(prime_num);
		for (int j = 2; j <= s_root; j++) //2부터 루트prime_num 까지 prime_num 의 약수가 있는지 판단
		{
			if (prime_num % j == 0) //prime_num 을 j 로 나눠서 나누어 떨어지면 j 는 prime_num 의 약수
			{
				check = 0; //소수가 아님
				break; //하나라도 약수가 있으면 소수가 아니므로 다음수로 넘어가기
			}
		}
		if (check == 1) prime_cnt++;
	}
	printf("%d", prime_cnt);
}
