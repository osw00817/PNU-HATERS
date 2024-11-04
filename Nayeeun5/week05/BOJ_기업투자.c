#include <stdio.h>
#include <string.h>

int N, M;
int profit[302][22], dp[302][22], x[302][22];

int max_profit(int money, int comp) {
    if (comp > M) return 0;
    if (dp[money][comp] != -1)
        return dp[money][comp];

    dp[money][comp]=0;
    for (int i = 0; i <= money; i++) {
        int n = profit[i][comp] + max_profit(money - i, comp + 1);
        if (dp[money][comp] < n) {
            dp[money][comp] = n;
            x[money][comp] = i;
        }
    }
    return dp[money][comp];
}

int main() {
    scanf("%d %d", &N, &M);

    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; i++) {
        for (int t = 0; t <= M; t++) {
            scanf("%d", &profit[i][t]);
        }
    }

    printf("%d\n", max_profit(N, 1));
    for (int i = 1; i <= M; i++) {
        printf("%d ", x[N][i]);
        N -= x[N][i];
    }
    printf("\n");
    return 0;
}
