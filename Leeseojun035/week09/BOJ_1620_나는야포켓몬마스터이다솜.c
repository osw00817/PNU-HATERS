#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Po {
    int key;
    char name[21];
} Po;

int Compare(const void *fr, const void *se) {
    Po* first = (Po*)fr;
    Po* second = (Po*)se;
    return strcmp(first->name, second->name);
}

int Bsearch(Po* arr, int Len, char* input) {
    int first = 0;
    int Last = Len - 1;

    while (first <= Last) {
        int mid = (first + Last) / 2;
        int cmp = strcmp(arr[mid].name, input);

        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            first = mid + 1;
        } else {
            Last = mid - 1;
        }
    }
}

int isNumeric(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int Len, Quiz;
    scanf("%d %d", &Len, &Quiz);

    Po* IntArr = (Po*)malloc(sizeof(Po) * Len);  
    Po* CharArr = (Po*)malloc(sizeof(Po) * Len);  

    for (int i = 0; i < Len; i++) {
        scanf("%s", IntArr[i].name);
        IntArr[i].key = i + 1;
        CharArr[i].key = i + 1;
        strcpy(CharArr[i].name, IntArr[i].name);
    }

    qsort(CharArr, Len, sizeof(Po), Compare);  

    for (int i = 0; i < Quiz; i++) {
        char input[21];
        scanf("%s", input);

        if (isNumeric(input)) {
            int index = atoi(input) - 1;
            printf("%s\n", IntArr[index].name);  
        } else {
            int index = Bsearch(CharArr, Len, input);
            if (index != -1) {
                printf("%d\n", CharArr[index].key);  
            }
        }
    }

    free(IntArr);
    free(CharArr);
    return 0;
}
