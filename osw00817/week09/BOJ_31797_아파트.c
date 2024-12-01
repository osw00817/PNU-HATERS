#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct apt {
	int person;
	int floor;
} apt;

int compare(const void* a, const void* b) {
	return (apt*)a->floor - (apt*)b->floor;
}

int main() {
	/*
	5 3
	1 6
	3 4
	2 5
	*/
	int N, M;
	scanf("%d %d", &N, &M);
	int size = M * 2;
	apt* list = (apt*)malloc(sizeof(apt) * (size));
	for (int i = 1; i <= size; i*=2) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		printf("%d ", i);
	}
	qsort(list,size+1,sizeof()

	int alchol = N % (M * 2);
	if (alchol == 0)
		alchol = N;
	printf("%d", list[alchol]);
	*/
	//예를들어 
	// 4 2
	// 1 2
	// 5 6
	// 이 들어온경우
	// list 배열에 1 1 null null
	// list 배열에 2 2 null null 이 되는 경우가 발생
	// 수학적으로 접근하면 예외 분기 처리에 대한 수학적 계산도 고려해야함
	// ==> 귀찮음 => 실패@@

	// 배열 받고, 정렬 한다음 , 하는게 그냥 나음
}

/*
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int size = M * 2;
	int* list = (int*)malloc(sizeof(int) * (size + 1));
	for (int i = 1; i <= M; i++) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		list[(tmp1%size != 0) ? tmp1%size : size] = i;
		list[(tmp2%size != 0) ? tmp2%size : size] = i;
	}
	int alchol = N % (M * 2);
	if (alchol == 0)
		alchol = N;
	printf("%d", list[alchol]);
}
*/