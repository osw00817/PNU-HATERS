#include <stdio.h>
#include <stdlib.h>

int n;
int a[1000001];
int v[1000001];

int compare(const void *x, const void *y) {
    return (*(int*)x - *(int*)y);
}


int lower_bound(int arr[], int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main() {
    scanf("%d", &n);


    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        v[i] = a[i];
    }

    qsort(v, n, sizeof(int), compare);

    int size = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || v[i] != v[i-1]) {
            v[size++] = v[i];
        }
    }


    for (int i = 0; i < n; i++) {
        int idx = lower_bound(v,size, a[i]);
        printf("%d ", idx);
    }

    return 0;
}
