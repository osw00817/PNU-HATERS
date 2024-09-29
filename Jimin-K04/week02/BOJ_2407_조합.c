//구현실패..

#include <stdio.h>

int main(void)
{
	int n, m;
	long long numer = 1, denom = 1; //정답이 실수 형태로 나올 수 있기 때문에 자료형 맞추기, 정답, 분자, 분모
	scanf("%d %d", &n, &m);

	int n_count = ((m < (n - m)) ? m : n - m); // 분자 곱해지는 횟수
	for (int i = 0; i < n_count; i++)
	{
		numer *= n--;
	}
	while (n_count > 1)
	{
		denom *= (n_count--); //분모 펙토리얼 나눠주기
	}
	printf("%.lld\n", numer / denom);
}
