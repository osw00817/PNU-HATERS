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

		fgets(Sound, MAX, stdin); // 동물들의 울음소리 입력 받음
		Sound[strcspn(Sound, "\n")] = '\0';

		word = strtok(Sound, " ");
		while (word != NULL) {
			strncpy(foxSay[idx++], word, 100); //foxSay 배열에 동물들의 울음소리를 공백 기준 나눠서 저장함
			word = strtok(NULL, " ");
		}
    //각 동물의 울음소리를 하나씩 입력받는데, 입력받은 문장을 anySay 에 저장
		while (1) {
			fgets(anySay, 210, stdin);
			anySay[strcspn(anySay, "\n")] = '\0'; 
			word = strtok(anySay, " ");

			if (word != NULL && !strcmp(word, "what")) break;
      // 해당 문장의 마지막(동물의 울음소리) 만 word 에 저장
			while (word != NULL) {
				say = word;
				word = strtok(NULL, " ");
			}
      //foxSay 배열에서 word 에 저장된 울음소리를 삭제함.-->"0" 으로 대체
			for (int i = 0; i < idx; i++) {
				if (say != NULL && strcmp(foxSay[i], say)== 0) strcpy(foxSay[i], "0");
			}
		}
    //마지막에 "0" 이 아닌것만 출력함
		for (int i = 0; i < idx; i++) {
			if (strcmp(foxSay[i], "0") != 0) printf("%s ", foxSay[i]);
		}
	}

}
