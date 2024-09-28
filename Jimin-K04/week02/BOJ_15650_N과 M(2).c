#include <stdio.h>

int N, M, nums[10] = { 0 }, ans[10] = {0}; // 전역변수

int BT(int cnt, int pre_num); //백트레킹 함수
int main(void)
{
	scanf("%d %d", &N, &M);
	BT(0, 1);
}

int BT(int cnt, int pre_num) // 이전 출력 숫자를 인자로 더 받음
{
	if (cnt == M) { // 한번에 M 개만 프린트 해야함
		for (int i = 0; i < M; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return 0;
	}

	for (int j = pre_num; j <= N; j++) { //직전수 다음부터 시작
		if (nums[j] == 0) {
			nums[j] = 1; //1 이면 현재 출력되고 있는 수를 인덱스로 가짐
			ans[cnt] = j; //ans 에 프린트할 수를 저장
			BT(cnt + 1, j + 1); //다음수를 저장하기 위해 cnt 를 올려서 재귀, 직전에 출력된 수 바로 다음부터 시작
			nums[j] = 0; // 바뀌는 수 프린트 후 다시 0으로 초기화
			ans[cnt] = 0; //제거
		}
		else continue;
	}
}
