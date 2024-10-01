#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

#define MAX_SIZE 100000 

int stack[MAX_SIZE]; 
int top = -1;
char ans[MAX_SIZE * 2];
int a_index = 0;


void push(int value) {
    ans[a_index] = '+';
    a_index++;
    stack[++top] = value;
}


void pop() {
    ans[a_index] = '-';
    a_index++;
    top--;
    
}

int main() {
    int N;//N은 user가 넣을 값, n은 실제 stack에서 사용될 값
    int n = 1, Num_index = 0;
    int Numbers_user[MAX_SIZE];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &Numbers_user[i]);
    while (Num_index < N) {

        if ((top != -1) && (stack[top] == Numbers_user[Num_index])) {
            pop();
            Num_index++;

        }
        else {
            if (n <= N) {
                push(n);
                n++;
            }
            else {
                printf("NO\n");
                return 0;

            }

        }
    }
    for (int j = 0; j < a_index; j++)printf("%c\n", ans[j]);


    return 0;
}

