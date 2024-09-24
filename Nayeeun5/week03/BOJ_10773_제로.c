#include<stdio.h>
#include<stdlib.h>
int sum = 0, cnt = 0, K, num;
int main() {
    scanf("%d", &K);
    int* str = (int*)malloc(K * sizeof(int));
    for (int i = 0; i < K; i++) {
        scanf("%d", &num);
        if (num == 0) {
            sum -= str[cnt - 1];
            cnt--;
        }
        else {
            str[cnt] = num;
            cnt++;
            sum += num;
        }
    }
    printf("%d\n", sum);
    free(str);
    return 0;
}
