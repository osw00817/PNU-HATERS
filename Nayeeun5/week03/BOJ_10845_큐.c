#include <stdio.h>
#include <string.h>
#define MAX 10001

typedef struct { //큐
    int data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue* q, int x) {
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = x;
}

int dequeue(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        return -1;
    }
    int res = q->data[q->front];
    q->front++;
    return res;
}

int size(Queue* q) {
    if (q->front == -1) return 0;
    return q->rear - q->front + 1;
}

int empty(Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

int front(Queue* q) {
    if (empty(q)) return -1;
    return q->data[q->front];
}

int back(Queue* q) {
    if (empty(q)) return -1;
    return q->data[q->rear];
}

int main() {
    int n;
    scanf("%d", &n);

    Queue q;
    initQueue(&q);

    for (int i = 0; i < n; i++) {
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "push") == 0) {
            int x;
            scanf("%d", &x);
            enqueue(&q, x);
        }
        else if (strcmp(command, "pop") == 0) {
            int result = dequeue(&q);
            printf("%d\n", result);
        }
        else if (strcmp(command, "size") == 0) {
            printf("%d\n", size(&q));
        }
        else if (strcmp(command, "empty") == 0) {
            printf("%d\n", empty(&q));
        }
        else if (strcmp(command, "front") == 0) {
            printf("%d\n", front(&q));
        }
        else if (strcmp(command, "back") == 0) {
            printf("%d\n", back(&q));
        }
    }

    return 0;
}
