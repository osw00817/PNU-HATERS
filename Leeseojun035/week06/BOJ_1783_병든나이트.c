#include <stdio.h>
#include <stdlib.h>


int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int result;

    if (n == 1) {
        result = 1;
    } else if (n == 2) {
        result = (m + 1) / 2;
        if (result > 4) result = 4; // 최대 이동 횟수는 4번으로 제한
    } else {
        if (m < 7) {
            result = m;
            if (result > 4) result = 4; 
        } else {
            // 다 한번씩 쓰고 한 쌍의 움직임만 쓰기
            result = m - 2;
        }
    }

    printf("%d\n", result);
    return 0;
}
