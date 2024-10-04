#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct {
    int data[MAX];
    int front, rear, size;
} Deque;

void initDeque(Deque* dq) {
    dq->front = dq->rear = 0;
    dq->size = 0;
}

void addrear(Deque* dq, int value) {
    dq->data[dq->rear] = value;
    dq->rear = (dq->rear + 1) % MAX;
    dq->size++;
}

int delfront(Deque* dq) {
    int value = dq->data[dq->front];
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
    return value;
}

void left(Deque* dq) {
    int temp = dq->data[dq->front];
    for (int i = 0; i < dq->size - 1; i++) {
        dq->data[(dq->front + i) % MAX] = dq->data[(dq->front + i + 1) % MAX];
    }
    dq->data[(dq->front + dq->size - 1) % MAX] = temp;
}

void right(Deque* dq) {
    int temp = dq->data[(dq->front + dq->size - 1) % MAX];
    for (int i = dq->size - 1; i > 0; i--) {
        dq->data[(dq->front + i) % MAX] = dq->data[(dq->front + i - 1) % MAX];
    }
    dq->data[dq->front] = temp;
}

int find(Deque* dq, int target) {
    for (int i = 0; i < dq->size; i++) {
        if (dq->data[(dq->front + i) % MAX] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Deque dq;
    initDeque(&dq);
    for (int i = 1; i <= n; i++) {
        addrear(&dq, i);
    }

    int cnt = 0;

    for (int i = 0; i < m; i++) {
        int target;
        scanf("%d", &target);
        int index = find(&dq, target);
        // 왼쪽과 오른쪽중 뭐가 빠른지
        if (index <= dq.size / 2) {
            // 왼쪽 회전
            for (int j = 0; j < index; j++) {
                left(&dq);
                cnt++;
            }
        }
        else {//오른쪽 회전
            for (int j = 0; j < dq.size - index; j++) {
                right(&dq);
                cnt++;
            }
        }
        delfront(&dq);
    }
    printf("%d", cnt);
    return 0;
}
