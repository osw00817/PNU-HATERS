/*오른쪽으로만 이동하기 때문에 우선 순위를 오른쪽이동이 작은 순 1,4,2,3으로 두고 dx,dy 를 배열로 만듦
체스의 좌표를 x,y 라고 하고 초기 위치를 0,0 으로 둠
만약 체스의 이동횟수가 4보다 적지 않은 경우는 초기위치를 6,0 으로 시작함 - 4가지 방법으로 모두 사용한 후 dx = 6, dy = 0 이기 때문*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N, M, x = 0, y = 0, check = 0, cnt = 1;
	int dx[4] = { 1,1,2,2 };
	int dy[4] = { 2,-2,1,-1 };

	scanf("%d %d", &N, &M);

	if (M > 6 && N > 2) {
		cnt += 4;
		x = 6;
	}

	while (1) {
		check = 0;
		for (int i = 0; i < 4; i++) {
			//이동한 후의 좌표가 체스판 범위를 넘는지 확인하기
			if (x+dx[i] < M && y+dy[i] < N && y+dy[i] >= 0) {
				x += dx[i];
				y += dy[i];
				cnt++;
				check = 1; // 이동을 했는지 확인
				break;
			}
		}
		if (!check) break; // 4가지 경우 모두 이동하지 않았다면 이동할 수 없다는것, 반복을 끝냄
	}

	printf("%d", cnt);
}
