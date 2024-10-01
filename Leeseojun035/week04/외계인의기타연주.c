#include <stdio.h>
#include <stdlib.h>

int n, k, count;  // n 음의 수이자 몇 줄 받을건지, k 프렛, count 손가락 
int **stack;      // 2차원 동적 배열
int *topindex;    // 각 줄의 top 인덱스 저장

// push 동적으로 구현
void push(int Gstring, int pratt) {
   
    stack[Gstring] = (int *)realloc(stack[Gstring], (topindex[Gstring] + 2) * sizeof(int));
   //index+2->1칸 확장
    stack[Gstring][++topindex[Gstring]] = pratt;
    count++;
}


void pop(int Gstring) {
    if (topindex[Gstring] > -1) {
        topindex[Gstring]--;  
        count++;
    }
}

void freeArray() {
    for (int i = 1; i <= n; i++) {
        free(stack[i]);
    }
    free(stack);
}

int main() {
    scanf("%d %d", &n, &k);

    
    stack = (int **)malloc((n + 1) * sizeof(int*));  // 각 줄에 대한 포인터 배열
    topindex = (int*)malloc((n + 1) * sizeof(int));
    
    //  초기화
    for (int i = 1; i <= n; i++) {
        stack[i] = NULL;  // 초기화하돼, 메모리 안 차지하게
        topindex[i] = -1; 
    }

    // 입력 
    for (int j = 0; j < n; j++) {
        int Gstring, pratt;
        scanf("%d %d", &Gstring, &pratt);

        //스택 채워져있음
        if (topindex[Gstring] > -1) {
            
            while (topindex[Gstring] > -1 && stack[Gstring][topindex[Gstring]] > pratt) {
                pop(Gstring);
            }

            
            if (topindex[Gstring] == -1 || stack[Gstring][topindex[Gstring]] != pratt) {
                push(Gstring, pratt);
            }
        } else {
            
            push(Gstring, pratt);
        }
    }

    printf("%d\n", count);  

    
    freeArray();
    free(topindex);

    return 0;
}
