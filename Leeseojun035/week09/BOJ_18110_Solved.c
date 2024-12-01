#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    int *si;
    scanf("%d", &n);
    if(n==0) {
        printf("0");
        return 0;
    }

    si = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &si[i]);
    }

    qsort(si, n, sizeof(int), compare); 

    int tak = (int)((n * 3.0) / 20 + 0.5);

    double hmm = 0.0;

    
    for (int ki = tak; ki < n - tak; ki++) {
        hmm += si[ki];
    }

    
    int result = (int)(hmm / (n - 2 * tak) + 0.5);

    printf("%d\n", result);

    free(si);  

    return 0;
}
