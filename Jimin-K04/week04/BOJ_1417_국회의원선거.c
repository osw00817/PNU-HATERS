/*국회의원 선거

다솜이 득표수보다 작은 후보군은 삭제
득표수 큰 순서대로 정렬
다솜이의 득표수가 최대 득표수보다 커지면 되는데..
최대 득표수를 계속 갱신해주는게 문제->?
최대 득표수에서 다솜이 표로 하나씩 가져오기.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int* find_max(int* arr, int len);

int main(void)
{
    int N, dasom, vote, idx = 0, *max_vote, cnt = 0;
    int votes[50];
    scanf("%d %d", &N, &dasom);


    for (int i = 0; i < N - 1; i++) {
        scanf("%d", &vote);
        if (vote >= dasom) votes[idx++] = vote;
    }
  
    max_vote = find_max(votes, idx);
    while (*max_vote >= dasom) {
        dasom++;
        cnt++;
        --(*max_vote);
        max_vote = find_max(votes, idx);
    }
    printf("%d", cnt);

}
int* find_max(int* arr, int len) {
    int* max = arr;
    for (int* cur = arr; cur < arr + len; cur++) {
        if (*cur > *max) max = cur;
    }
    return max;
}
