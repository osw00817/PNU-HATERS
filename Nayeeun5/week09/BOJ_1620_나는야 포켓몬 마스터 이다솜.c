#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[21];
    int num;
} Poket;

int compare(void* a, void* b) {
    Poket* pa = (Poket*)a;
    Poket* pb = (Poket*)b;
    return strcmp(pa->name, pb->name);
}

int binary_search(Poket* arr, int size, char* name) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(arr[mid].name, name);
        if (cmp == 0) return arr[mid].num;
        else if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Poket* poket = (Poket*)malloc(sizeof(Poket) * N);

    // 이중포인터 사용하여 2차원 배열처럼
    char** names = (char**)malloc((N + 1) * sizeof(char*));

    for (int i = 1; i <= N; i++) {
        names[i] = (char*)malloc(21 * sizeof(char));
        scanf("%s", poket[i - 1].name);
        poket[i - 1].num = i;
        strcpy(names[i], poket[i - 1].name);
    }

    qsort(poket, N, sizeof(Poket), compare);

    char query[21];
    for (int i = 0; i < M; i++) {
        scanf("%s", query);
        if (query[0] >= '0' && query[0] <= '9') {
            int idx = atoi(query); // 문자형인 숫자를 숫자로 변환
            printf("%s\n", names[idx]);
        }
        else {
            printf("%d\n", search(poket, N, query));
        }
    }
    for (int i = 1; i <= N; i++) {
        free(names[i]);
    }
    free(names);
    free(poket);

    return 0;
}
