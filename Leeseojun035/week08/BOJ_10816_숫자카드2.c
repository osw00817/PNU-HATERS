#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
    int int_a = *(int *)a;
    int int_b = *(int *)b;
    return int_a - int_b;
}


int first(int arr[], int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int end(int arr[], int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int m;
    scanf("%d", &m);

    
    int *arr = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr[i]);
    }

    
    qsort(arr, m, sizeof(int), compare);

    int count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int target;
        scanf("%d", &target);

        
        int lower = first(arr, m, target);
        int upper = end(arr, m, target);

        if (lower == upper) {
        
            printf("0 ");
        } else {
            
            printf("%d ", upper - lower);
        }
    }

    free(arr); 
    return 0;
}
