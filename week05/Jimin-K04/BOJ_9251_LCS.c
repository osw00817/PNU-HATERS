#include <stdio.h>
#define MAX 1001
int memo[MAX][MAX] = { 0 }, i, j;

int main(void)
{
	char s1[MAX], s2[MAX];
	scanf("%s %s", s1, s2);


	for (i = 1; s1[i-1]; i++) {
		for (j = 1; s2[j-1]; j++) {
			if (s1[i - 1] == s2[j - 1]) memo[i][j] = memo[i - 1][j - 1] + 1;
			else {
				memo[i][j] = memo[i - 1][j] > memo[i][j - 1] ? memo[i-1][j] : memo[i][j - 1];
			}
		}
	}
	printf("%d", memo[i-1][j-1]);
}
