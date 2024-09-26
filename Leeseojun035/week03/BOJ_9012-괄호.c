#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50

int stack[MAX_SIZE];
int top;

void push() {
    if (top < MAX_SIZE - 1) {
        top++;
    }
}

void pop() {
        top--;
    }
}

int isEmpty() {
    return top == -1;
}

int main() {
    int n;
    scanf("%d", &n); // 문자열 개수 입력

    for (int j = 0; j < n; j++) {
        char str[MAX_SIZE];
        scanf("%s", str);
        
        top = -1; // 스택 초기화
        int check = 1; // VPS 여부를 나타내는 변수

        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == '(') {
                push(); // 여는 괄호를 스택에 푸시
            } else {
                if (isEmpty()) {
                    check = 0; // 닫는 괄호가 있지만 여는 괄호가 없음
                    break; 
                }
                pop(); 
            }
        }

        // 스택이 비어있다면 모든 괄호가 매칭됨
        if (check && isEmpty()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
