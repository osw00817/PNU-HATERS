#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int lower_bound(int* N_card, int N, int a) {
    int low = 0, high = N;
    while (low < high) {
        int mid = (low + high) / 2;
        if (N_card[mid] < a)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int upper_bound(int* N_card, int N, int a) {
    int low = 0, high = N;
    while (low < high) {
        int mid = (low + high) / 2;
        if (N_card[mid] <= a)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main() {
    int N, M;
    scanf("%d", &N);

    int* N_card = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &N_card[i]);
    }
    qsort(N_card, N, sizeof(int), compare);

    scanf("%d", &M);
    while (M--) {
        int a;
        scanf("%d", &a);

        int lower = lower_bound(N_card, N, a);
        int upper = upper_bound(N_card, N, a);
        printf("%d ", upper - lower);
    }

    free(N_card);
    return 0;
}
