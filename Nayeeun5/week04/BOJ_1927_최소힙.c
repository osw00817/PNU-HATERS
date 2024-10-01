#include <stdio.h>

int heap[100001];
int size = 0;
void push(int value) {
    int idx = ++size;
    while (idx != 1 && value < heap[idx / 2]) {
        heap[idx] = heap[idx / 2];
        idx /= 2;
    }
    heap[idx] = value;
}

int pop() {
    if (size == 0) return 0;

    int res = heap[1];
    int leaf = heap[size--];
    int parent = 1, child = 2;

    while (child <= size) {
        if (child < size && heap[child] > heap[child + 1])
            child++;
        if (leaf <= heap[child]) break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }

    heap[parent] = leaf;
    return res;
}

int main() {
    int T, N;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);
        N > 0 ? push(N) : printf("%d\n", pop());
    }
    return 0;
}
