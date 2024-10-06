#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int* votes = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &votes[i]);
    }

    // 다솜
    int dasom = votes[0];

    // 매수
    int count = 0;

    //  비교
    while (1) {
        int maxIndex = 1;
        for (int i = 2; i < N; i++) {
            if (votes[i] > votes[maxIndex]) {
                maxIndex = i;
            }
        }

        if (dasom > votes[maxIndex]) {
            break;
        }

        // 매수
        votes[maxIndex]--;
        dasom++;
        count++;
    }

    printf("%d\n", count);
    return 0;
}
