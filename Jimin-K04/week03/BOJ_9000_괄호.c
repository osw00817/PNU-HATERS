#include <stdio.h>
#include <string.h>

char arr[51];
int main(void)
{
	int T, arr_len, check, top;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		check = 0, top = -1;
		scanf("%s", arr);
		arr_len = strlen(arr);

		for (int j = 0; j < arr_len; j++) {
			if (arr[j] == '(') top++; //push
			else {
				if (top == -1) { //중간에 더이상 pop 할 수 없는 경우 no 출력하고 다시 배열을 입력받아야함
					printf("NO\n");
					check = 1; //예외처리
					break; //반복문 빠져나감
				}
				else top--; //pop
			}
		}
		if (check) continue; //예외일 경우 아래 코드 실행 x
		if (top == -1) printf("YES\n"); //stack 에 모든 문자가 소거 됐을경우
		else printf("NO\n"); //stack 에 문자가 남아있을 경우
	}
}
