#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int age;
	char name[101];
	int idx;
}JUDGE;
//qsort 함수 사용하기 위한 비교함수, 구조체 비교, 나이가 같을경우 인덱스 순서를 반환하게 수정함(예은이 코드 참고)
int compare(const void* a, const void* b) {
	JUDGE* j1 = (JUDGE*)a;
	JUDGE* j2 = (JUDGE*)b;

	if (j1->age == j2->age) return j1->idx - j2->idx;
	else return j1->age - j2->age;
}

int main(void)
{
	int N, idx, insert_idx, Age;
	scanf("%d", &N);

	JUDGE* judges = (JUDGE*)malloc(sizeof(JUDGE) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d %s", &judges[i].age, judges[i].name);
		judges[i].idx = i;
	}

	qsort(judges, N, sizeof(JUDGE), compare);
	for (int i = 0; i < N; i++) {
		printf("%d %s\n", judges[i].age, judges[i].name);
	}
	free(judges);
}
