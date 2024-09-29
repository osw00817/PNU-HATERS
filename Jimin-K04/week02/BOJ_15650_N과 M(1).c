#include <stdio.h>

int N, M, nums[10] = { 0 }, ans[10] = {0}; // 전역변수

int BT(int cnt); //백트레킹 함수
int main(void)
{
	scanf("%d %d", &N, &M);
	BT(0);
}

int BT(int cnt) // 현재 ans 에 담긴 수의 개수를 인자로 받음(ans 는 프린트할 숫자를 값으로 하는 배열)
{
	if (cnt == M) { // 한번에 M 개만 프린트 해야함
		for (int i = 0; i < M; i++) {
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
