#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000001

int top = -1;
char stack[SIZE];

void push(char value) {
    stack[++top] = value;
}

void BOOM(char *input, char *bomb) {
    int inputLen = strlen(input);
    int bombLen = strlen(bomb);
    
    for (int i = 0; i < inputLen; i++) {
        push(input[i]);  // 입력 문자를 스택에 푸시
        
        // 폭발 문자열 길이만큼 스택이 쌓였고, 폭발 문자열과 일치할 때 처리
        if (top + 1 >= bombLen && stack[top] == bomb[bombLen - 1]) {
            int match = 1;
            
            for (int j = 0; j < bombLen; j++) {
                if (stack[top - j] != bomb[bombLen - 1 - j]) {
                    match = 0;
                    break;
                }
            }
            
            if (match) {
                top -= bombLen;  // 폭발 문자열 길이만큼 스택에서 제거
            }
        }
    }
}

int main() {
    char input[SIZE];
    char bomb[37];

    fgets(input, SIZE, stdin);  // 첫 줄에 입력 문자열을 받음
    input[strcspn(input, "\n")] = '\0';  // 줄바꿈 제거

    scanf("%s", bomb);  // 폭발 문자열 입력

    BOOM(input, bomb);  // 폭발 문자열 처리

    stack[top + 1] = '\0';  // 스택을 문자열로 처리
    if (top != -1) {
        printf("%s\n", stack);  // 결과 출력
    } else {
        printf("FRULA");
    }

    return 0;
}

