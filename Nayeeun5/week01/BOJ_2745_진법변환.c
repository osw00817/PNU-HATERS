#include <stdio.h>
#include <string.h>

int main(void) {
    char N[1000];
    int B, asc, n = 1, ans = 0;
    scanf("%s %d", N, &B);

    for (int i = strlen(N) - 1; i >= 0; i--) {
        if (N[i] >= 'A' && N[i] <= 'Z')
            asc = N[i] - 'A' + 10;
        else if (N[i] >= '0' && N[i] <= '9')
            asc = N[i] - '0';

        ans += asc * n;
        n *= B;
    }
    printf("%d\n", ans);

    return 0;
}
