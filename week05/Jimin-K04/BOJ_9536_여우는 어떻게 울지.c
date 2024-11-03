#include <stdio.h>
#include <string.h>
#define MAX 10101
int main(void) 
{
	int T, idx = 0;
	char anySay[210], Sound[MAX], foxSay[101][101];
	char* word, *say = NULL;

	scanf("%d", &T);
	getchar();

	for (int i = 0; i < T; i++) {
		idx = 0;
		memset(foxSay, 0, sizeof(foxSay)); //초기화

		fgets(Sound, MAX, stdin);
		Sound[strcspn(Sound, "\n")] = '\0';

    //2차원 배열에 입력받은 울음소리를 단어별로 저장
		word = strtok(Sound, " "); // 문자열을 공백 기준으로 나눠주는 함수
		while (word != NULL) {
			strncpy(foxSay[idx++], word, 100);
			word = strtok(NULL, " ");
		}
    // 각 동물들의 울음소리를 계속 입력받음
		while (1) {
			fgets(anySay, 210, stdin);
			anySay[strcspn(anySay, "\n")] = '\0';
			word = strtok(anySay, " ");

			if (word != NULL && !strcmp(word, "what")) break; // what the fox say 나오면 종료

			while (word != NULL) {
				say = word;
				word = strtok(NULL, " ");
			} // say 에 특정 동물의 울음소리가 저장됨

			for (int i = 0; i < idx; i++) {
				if (say != NULL && strcmp(foxSay[i], say)== 0) strcpy(foxSay[i], "0");
			} // 처음에 입력받은 울음소리 배열에서 해당 동물의 울음소리를 0 으로 대체함
		}
		for (int i = 0; i < idx; i++) {
			if (strcmp(foxSay[i], "0") != 0) printf("%s ", foxSay[i]); // 0 으로 대체된 다른 동물들의 울음 소리를 제외한 나머지를 출력
		}
	}

}
