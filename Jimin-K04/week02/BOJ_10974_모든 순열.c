#include <stdio.h>

int N, nums[10] = { 0 }, ans[10] = { 0 };

int BT(int cnt); //백트레킹 함수
int main(void)
{
	scanf("%d", &N);
	BT(0);
}

int BT(int cnt)
{
	if (cnt == N) {
		for (int i = 0; i < N; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return 0;
	}

	for (int j = 1; j <= N; j++) {
		if (nums[j] == 0) {
			nums[j] = 1; //1 이면 현재 출력되고 있는 수를 인덱스로 가짐
			ans[cnt] = j; //ans 에 프린트할 수를 저장
			BT(cnt + 1); //다음수를 저장하기 위해 cnt 를 올려서 재귀
			nums[j] = 0; // 바뀌는 수 프린트 후 다시 0으로 초기화
			ans[cnt] = 0; //제거
		}
		else continue;
	}
}
