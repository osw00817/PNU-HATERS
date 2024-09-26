#include <stdio.h>

#define MAX_SIZE 100000


int main() {
    int k,result = 0;
    int stack[MAX_SIZE];
    int top = -1;
    scanf("%d", &k); // 정수 개수 입력

    for (int i = 0; i < k; i++) {
        int p;//정수 입력
        scanf("%d", &p);
        if(p>0){
            stack[++top]=p;

        }
        else{
            top--;
        }



    }
    for(int j = 0; j<=top;j++){//topindex까지 다더하기
     result+=stack[j];
    }
    printf("%d",result);

    return 0;
}
