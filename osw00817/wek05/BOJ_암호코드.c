#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int memorization[5001];
int decode(char* s) {
    int n = 0;
    int len = strlen(s);
    if (memorization[len] != NULL) {
        return memorization[len];
    }
    int unit = ((len >= 1) ? s[len - 1] - '0' : 0);
    int ten = ((len >= 2) ? s[len - 2] - '0' : 0);
    int sum = ten * 10 + unit;
    if (len <= 2) {
        if (len == 2 && ten == 0) {
            return 0;
        }
        n = sum;
        //printf("%d 반환 검사중\n", n);
        if (n < 1) {
            return 0;
        }
        if ((1 <= n && n < 10)) {
            return 1;
        }
        if (10 <= n && n <= 26) {
            if (n % 10 == 0) {
                return 1;
            }
            return 2;
        }
    }
    n = sum;
    if (n >= 10 && n <= 26) {
        s[len - 1] = '\0';
        char tmp[5001];
        strcpy(tmp, s);
        tmp[len - 2] = '\0';
        //printf("%s %s\n", s, tmp);
        if (n == 10 || n == 20) {
            return memorization[len] = decode(tmp) % 1000000;
        }
        return memorization[len] = (decode(s) + decode(tmp)) % 1000000;
    }
    else {
        if (n%10 == 0) {
            return 0;
        }
        s[len - 1] = '\0';
        //printf("%s\n", s);
        return memorization[len] = decode(s) % 1000000;
    }
}

int main() {
        char s[5001];
        scanf("%s", s);
        printf("%d\n", decode(s) % 1000000);
}