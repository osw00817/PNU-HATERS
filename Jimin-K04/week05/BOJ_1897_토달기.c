#include <stdio.h>
#include <string.h>

int main(void)
{
	int d, max_len = 0, cnt = 0;
	char word[4], dic_word[81], max_word[81] = "";
	scanf("%d %s", &d, word);

	for (int i = 0; i < d; i++) {
		scanf("%s", dic_word);
		cnt = 0;
		for (int j = 0; j < 3; j++) {
			if (strchr(dic_word, word[j]) != NULL) { // strchr 포함 확인 포함되지 않으면 NULL 반환
				cnt++;
			}
		}

		if (cnt == 3) {
			if (strlen(dic_word) > max_len) {
				max_len = strlen(dic_word);
				strcpy(max_word, dic_word);
			}
		}
	}
	printf("%s", max_word);
}
