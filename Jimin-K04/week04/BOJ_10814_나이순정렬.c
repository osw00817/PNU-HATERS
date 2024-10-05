#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int age;
	char name[101];
}JUDGE;

int main(void)
{
	int N, idx, insert_idx, Age;
	scanf("%d", &N);

	JUDGE* judges = (JUDGE*)malloc(sizeof(JUDGE) * N);

	//한 요소를 입력받을때마다 정렬하면 앞의 요소들은 모두 정렬된 상태가 됨.
	for (int i = 0; i < N; i++) {
		scanf("%d", &Age);

		idx = i - 1; // 인덱스를 하나씩 줄여가기 (현재 삽입할 수보다 작거나 같아질때까지)
		while (idx >= 0 && judges[idx].age > Age) { //idx >= 0 조건을 먼저 검사해야함(segmentation fault 방지)
			idx--;
		}
		insert_idx = idx + 1; //입력받은 수를 삽입할 인덱스를 저장

		for (int j = i; j > insert_idx; j--) {
			judges[j] = judges[j - 1]; // 구조체의 모든 멤버(age, name) 복사됨, 삽입할 인덱스부터 끝까지 요소를 뒤로 미루기
		}
		judges[insert_idx].age = Age; //삽입할 곳에 나이 저장
		scanf("%s", &judges[insert_idx].name); //이후 이름 입력받고 해당 인덱스에 저장
	}

	for (int i = 0; i < N; i++) {
		printf("%d %s\n", judges[i].age, judges[i].name);
	}
	free(judges);
}
