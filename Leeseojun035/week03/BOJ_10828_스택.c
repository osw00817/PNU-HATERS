#include <stdio.h>
#define MAX_SIZE 10000
#define _CRT_NO_SECURE_WARNINGS

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = value;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    else {
        return -1; // 스택이 비어있을 때
    }
}

int empty() {
    return top < 0; // 비어있으면 1, 아니면 0
}

int Top() {
    if (top >= 0) {
        return stack[top]; // 현재 top의 값 반환
    }
    else {
        return -1; // 스택이 비어있을 때
    }
}

int main() {
    int CmdCnt;
    char CMD[7]; // 명령어의 최대 길이
    scanf("%d", &CmdCnt);

    for (int i = 0; i < CmdCnt; i++) {
        // 명령어와 값을 한 줄에서 입력받음
        top = -1;
        scanf("%s", CMD);

        if (CMD[0] == 'p') {
            if (CMD[1] == 'u') {
                int value;
                scanf("%d", &value); // 푸시할 값 입력
                push(value);
            }
            else {
                int popvalue = pop();
                printf("%d\n", popvalue);
            }
        }
        else if (CMD[0] == 'e') {
            printf("%d\n", empty()); // 비어있으면 1, 아니면 0
        }
        else if (CMD[0] == 's') {
            printf("%d\n", top + 1); // 현재 스택의 크기
        }
        else {
            int topValue = Top();
            if (topValue != -1) {
                printf("%d\n", topValue); // 현재 top의 값 출력
            }
            else {
                printf("-1\n"); // 스택이 비어있을 때
            }
        }
    }

    return 0;
}
