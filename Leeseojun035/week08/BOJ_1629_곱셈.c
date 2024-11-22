#include <stdio.h>

int main() {
    unsigned long long a, result = 1;
    int b, c;
    scanf("%llu %d %d", &a, &b, &c);
    a %= c;  // a를 c로 쳐주고 시작

    while (b) {
        if (b % 2 == 1) {
            result = (result * a) % c;  
        }
        a = (a * a) % c;  // 합동,분할정복
        b /= 2;
    }

    printf("%llu", result);  
    return 0;
}
