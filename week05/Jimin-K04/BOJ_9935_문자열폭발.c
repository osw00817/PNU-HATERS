#include <stdio.h>
#define MAX 10001
int main(void)
{
	int idx = 0;
	char str[MAX], bomb[37], result[MAX];

	scanf("%s %s", str, bomb);

	for (int i = 0; str[i]; i++) {
		result[idx++] = str[i]; //result 스택에 값 넣고
		for (int j = 0; bomb[j]; j++) {
			if (result[idx-1] == bomb[j]) {
				idx--; //폭발 문자이면 pop 하기
				break;
			}
		}
	}
	result[idx] = '\0';
	if (idx > 0) printf("%s", result);
	else printf("FRULA");
}
