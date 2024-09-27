#include <stdio.h>
int main(void){
	char s[100001] = {};
	scanf("%s", s);
	int cnt = 0, ans = 0; //ans는 쇠막대기 개수
	
	for(int i=0; s[i] != 0; i++) {
		if(s[i] == '(') cnt++;
		else {
			--cnt;
			(s[i-1] == '(')?ans+=cnt:ans++;
		}
	}
	printf("%d", ans);
    return 0;
}
