#include <stdio.h>
//1182 에서 가져옴

int N, nums[21] = {0}, given_list[20], new_list[21] = {0} ; // 전역변수

int BT(int cnt, int pre_num); //백트레킹 함수
int main(void)
{
	while (1) { //무한반복
		scanf("%d", &N);
		if (!N) return 0; //N 이 0일경우 종료
		for (int i = 0; i < N; i++) {
			scanf("%d", &given_list[i]);
		}
		BT(0, 1);
		printf("\n");
	}
}

int BT(int cnt, int pre_num)
{
	if (cnt == 6) { // 6개 까지만..
		for (int i = 0; i < 6; i++) {
			printf("%d ", new_list[i]);
		}
		printf("\n");
		return 0;
	}

	for (int j = pre_num; j <= N; j++) {
		if (nums[j] == 0) {
			nums[j] = 1;
			new_list[cnt] = given_list[j - 1]; // new list 에 주어진 수열의 해당 값을 저장
			BT(cnt + 1, j + 1);
			nums[j] = 0;
			new_list[cnt] = 0;
		}
		else continue;
	}
}
