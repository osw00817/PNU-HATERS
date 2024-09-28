#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 500001 // 한자리 비워둘거임

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
    front = (front + 1) % MAX_SIZE; // 인덱스 순환
    return value;
}

int size() {
    return (rear - front + MAX_SIZE) % MAX_SIZE; // 큐의 크기를 반환하는 함수
}

int main() {
    int N;
    scanf("%d", &N);

    // 1부터 N까지 큐에 넣기
    for (int i = 1; i <= N; i++) {
        push(i);
    }

    // 큐에서 마지막 남은 요소 찾기
    while (size() > 1) { // 큐의 크기가 1이 아닐 때까지 반복
        pop(); // 가장 앞의 요소 제거
        int n = pop(); // 다음 요소를 제거하고
        push(n); // 그것을 큐의 뒤에 추가
    }

    // 마지막 남은 요소 출력
    printf("%d\n", queue[front]); // 큐의 앞에 남아 있는 요소 출력

    return 0;
}
