#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100000
int stack[MAX_SIZE];
int top = -1;

int main() {
	char str[MAX_SIZE];
	scanf("%s", str);
	int size = strlen(str);
	int check = 0;//check 0일때 ')'을 받으면 레이저,1일때 ')'받으면 막대기
	int StickSum = 0;

	for (int i = 0; i < size; i++) {
		if (str[i] == '(') {
			top++;//push
			check = 0;//push할 때마다 초기화
		}
		else if(str[i] ==')')
		{
			if (0 == check) {
				StickSum += top;//top인덱스 값과 해당 레이저가 자르는 막대기의 수와 같음
				top--;//pop
				check = 1;
			}
			else {
				StickSum++;//자르고 남은 조각
				top--;//pop
			}
		}
	}

	printf("%d", StickSum);
	return 0;
}
