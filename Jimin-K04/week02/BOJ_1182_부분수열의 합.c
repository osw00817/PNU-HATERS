#include <stdio.h>
//15649 에서 가져옴

int N, M, nums[21] = {0}, given_list[20], new_list[21] = {0}, Sum, ans = 0, total = 0; // 전역변수

int BT(int cnt, int pre_num, int M); //백트레킹 함수
int main(void)
{
	scanf("%d %d", &N, &Sum);
	for (int i = 0; i < N; i++) {
		scanf("%d", &given_list[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		BT(0, 1, i);
	}
	printf("%d", ans);
}

int BT(int cnt, int pre_num, int M) //여기서 M 은 더하는 수의 개수
{
	if (cnt == M) { 
		total = 0; //총 합
		for (int i = 0; i < M; i++) {
			total += new_list[i];
		}
		if (total == Sum) ans++; //총합이 주어진 합과 같으면  + 1
		return 0;
	}

	for (int j = pre_num; j <= N; j++) { 
		if (nums[j] == 0) {
			nums[j] = 1; 
			new_list[cnt] = given_list[j - 1]; 
			BT(cnt + 1, j + 1, M);
			nums[j] = 0; 
			new_list[cnt] = 0;
		}
		else continue;
	}
}
