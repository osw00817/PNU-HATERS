#include <stdio.h>
#define MAX 500000
//메모리를 많이 잡아먹고 시간도 오래걸려서 아쉽..
int main() {
    int N, P, i, p_num, cnt = 0;
    int st[7][MAX];
    int num[7] = { 0 };//줄이 몇번 눌러져있는지 확인
    scanf("%d%d", &N, &P);
    while (N--) {
        scanf("%d%d", &i, &p_num);
        if (num[i] > 0) {//i번째 줄이 눌러져있음
            while (num[i] > 0 && st[i][num[i] - 1] > p_num) {//그 전에 눌러졌던 P가 입력된 P보다 클때까지 반복
                num[i]--;
                cnt++;
            }
            if (num[i] == 0 || st[i][num[i] - 1] != p_num) {
                st[i][num[i]++] = p_num;
                cnt++;
            }
        }
        else {//줄에 아무것도 눌러져 있지 않을때
            st[i][num[i]++] = p_num;
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
