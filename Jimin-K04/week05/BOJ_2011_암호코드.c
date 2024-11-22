#include <stdio.h>
#define MAX 5001

/*암호코드- 다이나믹 프로그래밍
점화식을 발견해야 하는데..
2 -> 1개
25 -> 1 + 1개
251 -> 2개 + 0
2511 -> 2 + 2 개
25114-> 4 + 2 개

*/
int main(void)
{
	int table[MAX] = { 1,1,1,0 }, i;
	char code[MAX];

	scanf("%s", code);

	for (i = 1; code[i]; i++) {
		if (code[0] == '0' || ((code[i - 1] > '2' || code[i - 1] == '0') && code[i] == '0')) {
			printf("0");
			return 0;
		}
		if (code[i - 1] > '2' || code[i] == '0') table[i + 1] = table[i];
		else table[i + 1] = table[i] + table[i - 1];
	}
	printf("%d", table[i] % 1000000);
}
