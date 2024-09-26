#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int* stack = (int*)malloc(n * sizeof(int));
    char* ans = (char*)malloc(2 * n * sizeof(char));
    int top = -1, ans_idx = 0;
    int now = 1;
    int find = 1;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        while (now <= num) {
            stack[++top] = now++;//stack에 push 하는 과정
            ans[ans_idx++] = '+';
        }
        if (stack[top] == num) {//만약 넣는중 top과 num이 같다면 pop
            top--;
            ans[ans_idx++] = '-';
        }
        else {
            find = 0;
            break;
        }
    }
    if (!find) {
        printf("NO\n");
    }
    else {
        for (int i = 0; i < ans_idx; i++) {
            printf("%c\n", ans[i]);
        }
    }
    free(stack);
    free(ans);
    return 0;
}
