#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct {
    int data[MAX];
    int front, rear, size;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
    q->size = 0;
}

void add(Queue* q, int value) {
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX;
    q->size++;
}

int del(Queue* q) {
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return value;
}

void left(Queue* q) {
    int temp = q->data[q->front];
    for (int i = 0; i < q->size - 1; i++) {
        q->data[(q->front + i) % MAX] = q->data[(q->front + i + 1) % MAX];
    }
    q->data[(q->front + q->size - 1) % MAX] = temp;
}

void right(Queue* q) {
    int temp = q->data[(q->front + q->size - 1) % MAX];
    for (int i = q->size - 1; i > 0; i--) {
        q->data[(q->front + i) % MAX] = q->data[(q->front + i - 1) % MAX];
    }
    q->data[q->front] = temp;
}

int find(Queue* q, int target) {
    for (int i = 0; i < q->size; i++) {
        if (q->data[(q->front + i) % MAX] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Queue q;
    initQueue(&q);
    for (int i = 1; i <= n; i++) {
        add(&q, i);
    }

    int cnt = 0;

    for (int i = 0; i < m; i++) {
        int target;
        scanf("%d", &target);
        int index = find(&q, target);
        // 왼쪽과 오른쪽중 뭐가 빠른지
        if (index <= q.size / 2) {
            // 왼쪽 회전
            for (int j = 0; j < index; j++) {
                left(&q);
                cnt++;
            }
        }
        else {//오른쪽 회전
            for (int j = 0; j < q.size - index; j++) {
                right(&q);
                cnt++;
            }
        }
        del(&q);
    }
    printf("%d", cnt);
    return 0;
}
