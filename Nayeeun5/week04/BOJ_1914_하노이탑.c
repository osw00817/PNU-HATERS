#include<stdio.h>
int N;
int Power(int x, int a, int arr[]) {
    int last = 0, cnt = 0;
    arr[0] = 1;
    for (int i = 1; i <= a; i++) {
        for (int j = 0; j <= last; j++) {
            int temp = arr[j] * x + cnt;
            arr[j] = temp % 10;
            cnt = temp / 10;
        }
        while (cnt > 0) {
            arr[++last] = cnt % 10;
            cnt /= 10;
        }
    }
    arr[0] -= 1;
    for (int i = last; i >= 0; i--)
        printf("%d", arr[i]);
    printf("\n");
    return last + 1;
}

void hanoi(int n, int from, int md, int to) {
    if (n == 1)
        printf("%d %d\n", from, to);
    else {
        hanoi(n - 1, from, to, md);
        printf("%d %d\n", from, to);
        hanoi(n - 1, md, from, to);
    }
}

int main() {
    int arr[35];
    scanf("%d", &N);
    Power(2, N, arr);
    if (N <= 20)
        hanoi(N, 1, 2, 3);

    return 0;
}
