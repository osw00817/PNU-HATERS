#include<stdio.h>
#include<string.h>
int main() {
	int dp[5001] = { 0 };
	char str[5001];
	scanf("%s", str);
	if (str[0] == '0') {
		printf("0");
		return 0;
	}
	dp[0] = dp[1] = 1;
	int i=2;
	for (i; i <= strlen(str); i++) {
		int one = str[i - 1] - '0';
		int two = (str[i - 2] - '0') * 10 + one;
		if (one >= 1 && one <= 9)
			dp[i] += dp[i - 1];
		if (two >= 10 && two <= 26)
			dp[i] += dp[i - 2];
		dp[i] %= 1000000;
	}
	printf("%d", dp[i-1]);
	return 0;
}
