#include <stdio.h>
#include <stdlib.h>

int compare(void* a, void* b) {
    return *(int*)a - *(int*)b;
}

int cut(int* tree, int N, int M, int height) {
    long long total = 0;
    for (int i = 0; i < N; i++) {
        if (tree[i] > height) {
            total += tree[i] - height;
        }
        if (total >= M) return 1;
    }
    return 0;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int* tree = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &tree[i]);
    }
    qsort(tree, N, sizeof(int), compare);

    int low = 0;
    int high = tree[N - 1];
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (cut(tree, N, M, mid)) {
            result = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    printf("%d", result);

    free(tree);
    return 0;
}
