#include <stdio.h>

int main(void)
{
	int A, B, max_num, min_num, tmp, Gcd, Lcm;
	scanf("%d %d", &A, &B);

	max_num = (A > B) ? A : B;  //대소비교
	min_num = (A < B) ? A : B;

	while (min_num != 0)
	{
		tmp = min_num; // min_num 값을 임시변수에 저장
		min_num = max_num % min_num; //두수의 나머지가 작은수가 됨
		max_num = tmp; //tmp 에 저장된 작은수가 큰수가 됨
	}
	Gcd = max_num, Lcm = A * B / Gcd;
	printf("%d\n%d", Gcd, Lcm);
}
