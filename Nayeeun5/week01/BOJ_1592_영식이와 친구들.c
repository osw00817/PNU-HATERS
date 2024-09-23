#include <stdio.h>

int main() {
    int N, M, L;
    scanf("%d %d %d", &N, &M, &L);

    int cnt[1001] = { 0 };
    int loc = 1, ans = 0;
    cnt[1] = 1;

    while (1) {
        if (cnt[loc] >= M) {
            printf("%d\n", ans);
            return 0;
        }

        if (cnt[loc] % 2 == 0) {
            loc = (loc - L + N - 1) % N + 1;
        }
        else {
            loc = (loc + L - 1) % N + 1;
        }

        cnt[loc]++;
        ans++;
    }
}
