#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define _CRT_SECURE_NO_WARNINGS

int* Deque;
int rear = 0, front = 0, DequeCount = 0, count = 0;
int isEmpty() {
    if (DequeCount == 0) {
        return 1;
    }
    else return 0;
}
int Front(int size) {
    if (isEmpty())return -1;
    else {
        return Deque[front];
    }
}
int Back(int size) {
    if (isEmpty())return -1;
    else {
        int Rear = (rear - 1+size) % size;
        return Deque[Rear];
    }
}

void push(int value, int check, int size) {//check =1 이면 front 0이면 back
    if (check) {  // front에 삽입
        front = (front - 1 + size) % size;
        Deque[front] = value;
    }
    else {  // back에 삽입
        Deque[rear] = value;
        rear = (rear + 1) % size;
    }
    DequeCount++;
}
int pop(int check, int size) {//push와 마찬가지
    if (isEmpty()) return -1;
    int value;
    if (check) {
        value = Deque[front];
        front = (front + 1) % size;
        DequeCount--;
        return value;

    }
    else {
        rear = (rear - 1 + size) % size;
        value = Deque[rear];
        DequeCount--;
        return value;
    }


}



int main() {
	int N;//N은 명령의 수
    scanf("%d", &N);
    int size = N + 1;
	Deque = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < N; i++) {
        char cmd[15];
        scanf("%s", cmd);
        if (strcmp(cmd, "push_front") == 0) {
            int value;
            scanf("%d", &value);
            push(value, 1, size);
        }
        else if (strcmp(cmd, "push_back") == 0) {
            int value;
            scanf("%d", &value);
            push(value, 0, size);
        }
        else if (strcmp(cmd, "pop_front") == 0) {
            printf("%d\n", pop(1, size));
        }
        else if (strcmp(cmd, "pop_back") == 0) {
            printf("%d\n", pop(0, size));
        }
        else if (strcmp(cmd, "front") == 0) {
            printf("%d\n", Front(size));
        }
        else if (strcmp(cmd, "back") == 0) {
            printf("%d\n", Back(size));
        }
        else if (strcmp(cmd, "empty") == 0) {
            printf("%d\n", isEmpty());
        }
        else {
            printf("%d\n", DequeCount);
        }
    }

    free(Deque);

	return 0;
}
