#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;
    int front, rear, capacity;
} Queue;
//큐에 한걸로 하니까 런타임 에러나서 동적메모리로 근데 원형큐로 했었으면 될수도..?
void initQueue(Queue* q) {
    q->capacity = 10000;
    q->data = (int*)malloc(q->capacity * sizeof(int));
    q->front = 0;
    q->rear = -1;
}
void enqueue(Queue* q, int x) {
    if (q->rear == q->capacity - 1) {
        q->capacity *= 2;
        q->data = (int*)realloc(q->data, q->capacity * sizeof(int));
    }
    q->rear++;
    q->data[q->rear] = x;
}
int dequeue(Queue* q) {
    return (q->front > q->rear) ? -1 : q->data[q->front++];
}
int size(Queue* q) {
    return q->rear - q->front + 1;
}
int empty(Queue* q) {
    return (q->front > q->rear);
}
int front(Queue* q) {
    return (empty(q)) ? -1 : q->data[q->front];
}
int back(Queue* q) {
    return (empty(q)) ? -1 : q->data[q->rear];
}
void freeQueue(Queue* q) {
    free(q->data);
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
    freeQueue(&q);
    return 0;
}
