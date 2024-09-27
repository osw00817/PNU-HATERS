#include<stdio.h>
int main(){
    int N, result = 1;
    scanf("%d", &N);
    for(int i =1;i<N;i*=2)
        result = 2 * (N - i);
    printf("%d", result);
}
