#include<stdio.h>
#include<string.h>

int main() {
    int num, cnt;
    char str[51];
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%s", str);
        cnt = 0;
        for (int j = 0; j < strlen(str); j++) {
            if (str[j] == '(') cnt++;
            else if (str[j] == ')') {
                cnt--;
                if (cnt < 0) {
                    break;
                }
            }
        }
        if (cnt == 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
