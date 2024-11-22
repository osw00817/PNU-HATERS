#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500
//건물 구조체 : 짓는데 걸리는 시간, 건물 번호, 이 건물을 짓기 위해 선행되어야 하는 건물의 구조체 주소, 선행 건물의 개수
typedef struct Building {
	int time, number;
	struct Building* link_ls[MAX];
	int link_ls_len;
}Building;

int memo[MAX] = {0};
int total_time(Building* B);

int main(void)
{
	int N, tmp;
	scanf("%d", &N);

	Building** B_list = malloc(N * sizeof(Building*)); // 건물들을 저장하기 위한 배열 생성

	for (int i = 0; i < N; i++) {
		B_list[i] = malloc(sizeof(Building));
		B_list[i]->number = i;

		scanf("%d", &tmp);
		B_list[i]->time = tmp;
		memset(B_list[i]->link_ls, 0, sizeof(B_list[i]->link_ls));

		int idx = 0;
		B_list[i]->link_ls[idx] = NULL;//초기값 NULL
		while (1) {
			scanf("%d", &tmp);
			if (tmp == -1) break;
			B_list[i]->link_ls[idx++] = B_list[tmp - 1]; //선행 건물 리스트를 저장함
		}
		B_list[i]->link_ls_len = idx;
	}

	for (int j = 0; j < N; j++) {
		printf("%d\n", total_time(B_list[j]));
	}
	for (int j = 0; j < N; j++) free(B_list[j]);
	free(B_list);
}
//총 시간 계산하는 함수
int total_time(Building* B)
{
	int pre_time = 0; //선행건물을 짓기 위해 필요한 시간
	if (B->link_ls_len == 0) return B->time; //선행 건물이 없으면 해당 시간만 반환
	if (memo[B->number] == 0) { //메모에 값이 저장되지 않은 경우
		for (int k = 0; k < B->link_ls_len; k++) { //선행건물들의 짓는 시간중 최댓값을 구하는데, 중간에 메모에 기록하기
			if (memo[B->link_ls[k]->number] == 0) {
				memo[B->link_ls[k]->number] = total_time(B->link_ls[k]);
			}
			if (memo[B->link_ls[k]->number] > pre_time) pre_time = memo[B->link_ls[k]->number]; //최댓값을 pre_time 에 저장함
		}
		memo[B->number] = B->time + pre_time; //총 시간을 구하고 메모에 기록
		return memo[B->number]; //해당값을 반환
	}
	else return memo[B->number]; // 메모에 값이 저장되어 있을경우 값을 바로 반환함
}
