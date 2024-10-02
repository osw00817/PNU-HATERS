#include <stdio.h>
#include <stdlib.h>

int heap[100001];
int size = 0;

void push(int value) {
    int idx = ++size;
    while (idx != 1 && (abs(value) < abs(heap[idx / 2]) || (abs(value) == abs(heap[idx / 2]) && value < heap[idx / 2]))) {
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
        if (child < size && (abs(heap[child]) > abs(heap[child + 1]) || (abs(heap[child]) == abs(heap[child + 1]) && heap[child] > heap[child + 1])))
            child++;
        if (abs(leaf) < abs(heap[child]) || (abs(leaf) == abs(heap[child]) && leaf <= heap[child])) break;
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
        N != 0 ? push(N) : printf("%d\n", pop());
    }
    return 0;
}
