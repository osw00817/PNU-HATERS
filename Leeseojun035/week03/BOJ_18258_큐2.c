#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 2000001//한자리 비워둘거임

int queue[MAX_SIZE];  
int front = 0;        
int rear = 0;         

int isEmpty() {
    return front == rear; 
}

void push(int value) {
    queue[rear] = value;
    rear = (rear + 1) % MAX_SIZE; // 인덱스 순환
}

int pop() {
    if (isEmpty()) return -1; 
    int value = queue[front];
    front = (front + 1) % MAX_SIZE;  // 인덱스 순환
    return value; 
}

int size() {
    return (rear - front + MAX_SIZE) % MAX_SIZE; 
}

int Front() {
    if (isEmpty()) return -1; 
    return queue[front]; 
}

int back() {
    if (isEmpty()) return -1; 
    return queue[(rear - 1 + MAX_SIZE) % MAX_SIZE]; 
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char cmd[6];
        scanf("%s", cmd);

        if (strcmp(cmd, "push") == 0) {
            int value;
            scanf("%d", &value);
            push(value);
        }
        else if (strcmp(cmd, "pop") == 0) {
            printf("%d\n", pop()); 
        }
        else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(cmd, "empty") == 0) {
            printf("%d\n", isEmpty());
        }
        else if (strcmp(cmd, "front") == 0) {
            printf("%d\n", Front());
        }
        else if (strcmp(cmd, "back") == 0) {
            printf("%d\n", back());
        }
    }

    return 0;
}
