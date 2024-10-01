#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 6개의 줄, P개의 프렛
// 가장 높은 프렛의 음이 발생하다
// (1 ≤ N ≤ 500,000, 2 ≤ P ≤ 300,000)

/*
	구상
	- 라인별 top 배열
	- 라인별 fret 2차원 배열 만들어서 stack처럼 활용하기
	- while문을 통해서 조건에 맞추어서 손붙이고 떼기
*/

int main() {
	int N, P, cnt = 0;
	scanf("%d", &N);
	scanf("%d", &P);
	int top[6] = { -1 };
	// 각 줄별 top 초기값 할당
	int* fret[6];
	for (int i = 0; i < 6; i++) {
		fret[i] = (int*)malloc(sizeof(int));
	}
	// 각 프렛별 stack 할당
	while (N > 0) {
		N--;
		int line, fretnum;
		scanf("%d", &line);
		scanf("%d", &fretnum);
		line--;
		//인덱스로 사용하기 쉽게 -1 해주기
		while (1) {
			if (top[line] == -1) {
				//스택이 비어있다면
				top[line]++;
				fret[line] = (int*)realloc(fret[line], sizeof(int) * (top[line] + 1));
				fret[line][top[line]] = fretnum;
				cnt++;
				break;
			}
			else {
				//스택이 비어있지 않다면
				if (fret[line][top[line]] < fretnum) {
					// 높은 프렛이면 손 붙이기
					top[line]++;
					fret[line] = (int*)realloc(fret[line], sizeof(int) * (top[line] + 1));
					fret[line][top[line]] = fretnum;
					cnt++;
					break;

				}
				else if (fret[line][top[line]] == fretnum) {
					//같은 프렛이면 행동 x
					break;
				}
				else {
					//더 작은 프렛이면 손떼기
					top[line]--;
					cnt++;
				}
			}
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < 6; i++) {
		free(fret[i]);
	}
	return 0;
}