#include<stdio.h>
#include<string.h>

int main(void) {
	int res[8], n = 1, sum = 0;
	char str[15];
	while (1) {
		scanf("%s", str);
		if (str[0] == '#') break;
		for(int i=0;i<strlen(str);i++)
			switch (str[i]) {
				case '-':
					res[i] = 0;
					break;
				case '\\':
					res[i] = 1;
					break;
				case '(':
					res[i] = 2;
					break;
				case '@':
					res[i] = 3;
					break;
				case '?':
					res[i] = 4;
					break;
				case '>':
					res[i] = 5;
					break;
				case '&':
					res[i] = 6;
					break;
				case '%':
					res[i] = 7;
					break;
				case '/':
					res[i] = -1;
					break;
				default:
					break;
			}
		for (int j = strlen(str) - 1; j >= 0; j--){
			sum += res[j] * n;
			n *= 8;
		}
		printf("%d\n", sum);
		sum = 0;
		n = 1;
	}
	return 0;
}
