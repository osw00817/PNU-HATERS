#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

int sisters_loc[MAX];
int gcd(int a, int b);
int main(void)
{
	int sister_num, SB_loc, tmp;
	scanf("%d %d", &sister_num, &SB_loc);
	for (int i = 0; i < sister_num; i++)
	{
		scanf("%d", &sisters_loc[i]);
		sisters_loc[i] -= SB_loc;
		sisters_loc[i] = abs(sisters_loc[i]);//변위의 절댓값을 배열에 저장.(수빈이가 동생위치까지 이동했을 때 각 변위)
	}
	//배열에 저장된 값들의 최대공약수구하기
	tmp = sisters_loc[0];
	for (int i = 1; i < sister_num; i++)
	{
		tmp = gcd(tmp, sisters_loc[i]);
	}
	printf("%d", tmp);
}

 // a 와 b 의 최대공약수를 반환하는 함수, 유클리드 호제법
int gcd(int a, int b)
{
	int max = (a > b ? a : b);
	int min = (a < b ? a : b);
	int r = max % min;
	while (r > 0)
	{
		max = min;
		min = r;
		r = max % min;
	}
	return min;
}
