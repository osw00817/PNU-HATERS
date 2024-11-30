#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct pocketmon {
	char name[21];
	int cnt;
} pocketmon;

int compareByName(const void* a, const void* b) {
	return strcmp(((pocketmon*)a)->name, ((pocketmon*)b)->name);
}

int compareByCnt(const void* a, const void* b) {
	return ((pocketmon*)a)->cnt - ((pocketmon*)b)->cnt;
}

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	pocketmon* pocket = NULL;
	int size = 0;

	while (N--) {
		char tmp[21];
		scanf("%s", tmp);

		int check = 0;
		for (int i = 0; i < size; i++) {
			if (strcmp(tmp, pocket[i].name) == 0) {
				pocket[i].cnt++;
				check = 1;
				break;
			}
		}

		if (!check) {
			pocket = (pocketmon*)realloc(pocket, sizeof(pocketmon) * (size + 1));
			size++;
			pocket[size - 1].cnt = 1;
			strcpy(pocket[size - 1].name, tmp);
		}
	}

	pocketmon* nameSorted = (pocketmon*)malloc(size * sizeof(pocketmon));
	pocketmon* cntSorted = (pocketmon*)malloc(size * sizeof(pocketmon));

	memcpy(nameSorted, pocket, size * sizeof(pocketmon));
	memcpy(cntSorted, pocket, size * sizeof(pocketmon));

	qsort(nameSorted, size, sizeof(pocketmon), compareByName);
	qsort(cntSorted, size, sizeof(pocketmon), compareByCnt);

	while (M--) {
		char tmp[21];
		scanf("%s", tmp);

		if (isdigit(tmp[0])) {
			//숫자인 경우
			// 어케 하면 효율적으로 검색이 가능한가.
			// 어케 하면 효율적으로 검색이 가능한가.
			// 어케 하면 효율적으로 검색이 가능한가.
			// 어케 하면 효율적으로 검색이 가능한가.
			// 어케 하면 효율적으로 검색이 가능한가.
			int target = atoi(tmp);
			continue;
		}
		//포켓몬 이름인 경우	
		// 어떻게 하면 효율적인 검색이 가능한가.
		// 어떻게 하면 효율적인 검색이 가능한가.
		// 어떻게 하면 효율적인 검색이 가능한가.
		// 어떻게 하면 효율적인 검색이 가능한가.
		// 어떻게 하면 효율적인 검색이 가능한가.
		// 어떻게 하면 효율적인 검색이 가능한가.
	}

	free(nameSorted);
	free(cntSorted);
	free(pocket);

}