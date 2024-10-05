#include <stdio.h>
#define MAX 10001

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX];
} Deque;

void init_deque(Deque* dq) {
    dq->front = 0;
    dq->rear = 0;
}

int is_empty(Deque* dq) {
    return dq->front == dq->rear;
}

void add_front(Deque* dq, element item) {
    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->data[dq->front] = item;
}

void add_rear(Deque* dq, element item) {
    dq->data[dq->rear] = item;
    dq->rear = (dq->rear + 1) % MAX;
}

int delete_front(Deque* dq) {
    if (is_empty(dq))
        return -1;
    else {
        int item = dq->data[dq->front];
        dq->front = (dq->front + 1) % MAX;
        return item;
    }
}

int delete_rear(Deque* dq) {
    if (is_empty(dq))
        return -1;
    else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
        return dq->data[dq->rear];
    }
}

int get_front(Deque* dq) {
    if (is_empty(dq))
        return -1;
    else {
        return dq->data[dq->front];
    }
}

int get_rear(Deque* dq) {
    if (is_empty(dq))
        return -1;
    else {
        return dq->data[(dq->rear - 1 + MAX) % MAX];
    }
}

int size(Deque* dq) {
    return (dq->rear - dq->front + MAX) % MAX;
}

int main(void) {
    Deque dq;
    init_deque(&dq);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "push_front") == 0) {
            int x;
            scanf("%d", &x);
            add_front(&dq, x);
        }
        else if (strcmp(command, "push_back") == 0) {
            int x;
            scanf("%d", &x);
            add_rear(&dq, x);
        }
        else if (strcmp(command, "pop_front") == 0) {
            printf("%d\n", delete_front(&dq));
        }
        else if (strcmp(command, "pop_back") == 0) {
            printf("%d\n", delete_rear(&dq));
        }
        else if (strcmp(command, "size") == 0) {
            printf("%d\n", size(&dq));
        }
        else if (strcmp(command, "empty") == 0) {
            printf("%d\n", is_empty(&dq));
        }
        else if (strcmp(command, "front") == 0) {
            printf("%d\n", get_front(&dq));
        }
        else if (strcmp(command, "back") == 0) {
            printf("%d\n", get_rear(&dq));
        }
    }

    return 0;
}
