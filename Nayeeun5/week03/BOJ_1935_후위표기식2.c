#include <stdio.h>
#include <string.h>

double stack[100];
int top = 0;

void push(double x) {
    stack[top++] = x;
}

double pop() {
    return stack[--top];
}

int main() {
    int N;
    char str[100];
    double num[26];
    scanf("%d", &N);
    scanf("%s", str);
    for (int i = 0; i < N; i++) {
        scanf("%lf", &num[i]);
    }
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            push(num[str[i] - 'A']);
        }
        else {
            double b = pop();
            double a = pop();
            switch (str[i]) {
            case '+': push(a + b); break;
            case '-': push(a - b); break;
            case '*': push(a * b); break;
            case '/': push(a / b); break;
            }
        }
    }
    printf("%.2lf\n", pop());
    return 0;
}
