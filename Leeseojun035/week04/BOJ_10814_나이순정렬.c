#include <stdio.h>
#include <stdlib.h>

typedef struct member {
    char name[100];
    int age;
} Member;

void BubbleSort(Member** arr, int size) {
    Member* temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j]->age > arr[j + 1]->age) {  // 버블 정렬: 나이 오름차순 정렬
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);

    // Member*에 대한 포인터 배열 생성
    Member** arr = (Member**)malloc(sizeof(Member*) * n);

    for (int i = 0; i < n; i++) {
        arr[i] = (Member*)malloc(sizeof(Member));  // Member 구조체에 메모리 할당

        scanf("%d", &arr[i]->age);
        scanf("%s", arr[i]->name);
    }

    BubbleSort(arr, n);  // 버블 정렬 실행

    for (int j = 0; j < n; j++) {
        printf("%d %s\n", arr[j]->age, arr[j]->name);
    }

    // 메모리 해제
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}//시간 초과 
