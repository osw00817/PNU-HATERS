#include <stdio.h>
#define MAX 100000
int stack[MAX], top = -1, ans_idx = 0; // ans의 인덱스
char ans[MAX * 2 + 1]; //출력할 문자를 저장

int main(void)
{
	int n, num, last_push = 0; //마지막으로 push 된 수를 저장
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num);

		if (num == stack[top]) { //입력받은 수가 스택의 탑 과 같으면 pop
			top--;
			ans[ans_idx++] = '-'; //pop 할때마다 배열에 저장
		}
		else if (num > stack[top] || top == -1) { //입력받은 수가 스택의 탑보다 크거나 처음 입력받는 경우
			for (int j = last_push + 1; j <= num; j++) { //마지막 push 수 다음 부터 입력받은 수 까지 push
				stack[++top] = j;
				ans[ans_idx++] = '+'; //push 할때마다 저장
			}
			last_push = num; // 마지막 push 한 수를 저장
			top--; //pop
			ans[ans_idx++] = '-';
		}
		// 위 두 경우를 제외하면 수열을 만들 수 없음
		else {
			printf("NO");
			return 0;
		}
	}
	

	for (int i = 0; i < ans_idx; i++) {
		printf("%c\n", ans[i]);
	}
}
