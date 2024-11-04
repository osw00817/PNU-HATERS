#include<stdio.h>
#include<string.h>
//len을 먼저 지정하는지 안하는지에 따라 생각보다 시간 차이가 크다는걸 알게됨
//strlen 함수는 문자열 길이를 계산할 때마다 반복해서 문자열 전체를 탐색하기 때문
int LCS[1001][1001], i, j, len1, len2;
char str1[1001], str2[1001];

int main() {
	scanf("%s", str1);
	scanf("%s", str2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	for (i = 0; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			if (str1[i] == str2[j])
				LCS[i + 1][j + 1] = LCS[i][j] + 1;
			else
				LCS[i + 1][j + 1] = (LCS[i][j + 1] > LCS[i + 1][j]) ? LCS[i][j + 1] : LCS[i + 1][j];
		}
	}
	printf("%d", LCS[i][j]);
}
