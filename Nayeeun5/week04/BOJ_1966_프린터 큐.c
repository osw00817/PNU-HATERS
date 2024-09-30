#include <stdio.h>

int main() {
    int T, N, M;
    int i, front;
    int arr[100] = { 0 };
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        int ans = 1;
        front = 0;
        for (i = 0; i < N; i++)
            scanf("%d", &arr[i]);
        while (1) {
            int max_index = front;
            for (i = 1; i < N; i++) {
                if (arr[(front + i) % N] > arr[max_index])
                    max_index = (front + i) % N;
            }
            if (max_index == front) {
                if (front == M) break;
                arr[front] = 0;
                ans++;
            }
            front = (front + 1) % N;
        }
        printf("%d\n", ans);
    }
    return 0;
}
