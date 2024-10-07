#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int age;
    char name[101];
    int order;
} Person;

int compare(const void* a, const void* b) {
    Person* p1 = (Person*)a;
    Person* p2 = (Person*)b;
    if (p1->age != p2->age)
        return p1->age - p2->age; //음수면 p1을 p2앞에 배열 양수면 p2를 p1에 배열
    return p1->order - p2->order; 
}

int main() {
    int N;
    scanf("%d", &N);
    Person* people = (Person*)malloc(N * sizeof(Person));
    for (int i = 0; i < N; i++) {
        scanf("%d %s", &people[i].age, people[i].name);
        people[i].order = i;
    }

    //qsort(정렬할 값의 주소, ﻿요소의 개수, ﻿요소의 크기, ﻿기준 함수)
    qsort(people, N, sizeof(Person), compare);
    for (int i = 0; i < N; i++) {
        printf("%d %s\n", people[i].age, people[i].name);
    }
    free(people);
    return 0;
}
