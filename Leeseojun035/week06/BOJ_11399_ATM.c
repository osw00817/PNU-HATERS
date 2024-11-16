#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int int_a = *(int*)a;
    int int_b = *(int*)b;

    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}



int main()
{
    int *time,*ptr;
    int n,result=0;;
    scanf("%d",&n);
    time = (int*)malloc(sizeof(int)*n);
    ptr = time;


    for(int i = 0; i<n; i++){
        scanf("%d",ptr++);
    }
    qsort(time, n, sizeof(int), compare);

    for(int i = 1; i<n; i++)
    {
       time[i] = time[i-1] + time[i];
    }

    for(int i=0;i<n;i++) result+=time[i];

    printf("%d",result);

    free(time);
    return 0;
}
