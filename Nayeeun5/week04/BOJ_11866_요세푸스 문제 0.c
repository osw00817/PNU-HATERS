#include <stdio.h>
#define SIZE 1001
//큐 써서 풀기
int N, M;

typedef struct {
    int data[SIZE];
    int front, rear;
} Queue;

void init(Queue* Q) {
    Q->front = Q->rear = 0;
}

int isEmpty(Queue* Q) {
    return Q->front == Q->rear;
}

int isFull(Queue* Q) {
    return Q->front == (Q->rear + 1) % SIZE;
}

void enqueue(Queue* Q, int e) {
    if (isFull(Q)) {
        printf("Queue is Full!\n");
    }
    else {
        Q->rear = (Q->rear + 1) % SIZE;
        Q->data[Q->rear] = e;
    }
}

int dequeue(Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue is Empty!\n");
        return 0;
    }
    Q->front = (Q->front + 1) % SIZE;
    return Q->data[Q->front];
}

int main() {
    Queue Q;
    init(&Q);
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        enqueue(&Q, i);
    }
    printf("<");
    while (!isEmpty(&Q)) {
        for (int i = 1; i < M; i++) {
            int temp = dequeue(&Q);
            enqueue(&Q, temp);
        }
        printf("%d", dequeue(&Q));//M번째 사람 큐에서 제거하고 출력
        if (!isEmpty(&Q)) {
            printf(", ");  //마지막 사람이 아니라면 ','출력
        }
    }
    printf(">");
    return 0;
}

----
#include <stdio.h>
//배열써서 풀기
int main() {
    int N, M, idx = 0;
    scanf("%d %d", &N, &M);
    int arr[1001];
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }
    printf("<");
    int people = N;
    while (people > 0) {
        idx = (idx + M - 1) % people;

        printf("%d", arr[idx]);// M번째 사람 출력
        if (people > 1) {// 마지막 사람이 아니라면 ',' 출력
            printf(", ");
        }
        for (int i = idx; i < people - 1; i++) {
            arr[i] = arr[i + 1];//인덱스 값을 하나씩 줄이기
        }
        people--;
    }
    printf(">");
    return 0;
}

