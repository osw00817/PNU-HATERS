#include <stdio.h>
int c;
int mul(int a, int b) {
    if (b == 0) return 1;
    else if (b == 1) return a;
    else {
        long long ans = mul(a, b / 2);
        if (b % 2 == 1) return (a * ((ans * ans) % c)) % c;
        else return (ans * ans) % c;
    }
}

int main() {
    int a, b;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", mul(a % c, b));
}
