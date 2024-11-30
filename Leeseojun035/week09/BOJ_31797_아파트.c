#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


int main()
{
    int n,m,*arr1,**arr2,k;
    scanf("%d %d",&n,&m);
    arr1 = (int*)malloc(sizeof(int)*(m*2));
    arr2 = (int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++){
        arr2[i] = (int*)malloc(sizeof(int)*2);
    }
    n = n%(m*2);
    if(n==0) n = m*2;
    for(int i = 0; i<m; i++){

        scanf("%d %d",&arr1[i*2],&arr1[i*2+1]);
        arr2[i][0] = arr1[i*2];
        arr2[i][1] = arr1[i*2+1];

    }
    qsort(arr1,(m*2),sizeof(int),compare);


    k = arr1[n-1];
    for(int i=0; i<m;i++){
        if(arr2[i][0]==k || arr2[i][1]==k){
            printf("%d",i+1);
            break;
        }
    }



    free(arr1);
    for(int i=0; i<m;i++)free(arr2[i]);
    free(arr2);
    return 0;
}
