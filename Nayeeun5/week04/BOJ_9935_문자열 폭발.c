#include <stdio.h>
#include <string.h>

#define MAX 1000001

char str[MAX];
char pop[37];
char result[MAX];
int main() {
    scanf("%s", str);
    scanf("%s", pop);
    int strLen = strlen(str);
    int popLen = strlen(pop);
    int idx = 0; // result 인덱스
    for (int i = 0; i < strLen; i++) {
        result[idx++] = str[i];
        if (idx >= popLen) {
            int match = 1;
            for (int j = 0; j < popLen; j++) {
                if (result[idx - popLen + j] != pop[j]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                idx -= popLen;
            }
        }
    }
    if (idx == 0) {
        printf("FRULA");
    }
    else {
        for (int i = 0; i < idx; i++)
            printf("%c", result[i]);
    }
    return 0;
}
