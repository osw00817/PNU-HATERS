#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

int main() {
    int T;
    scanf("%d", &T);
    getchar();  // 입력 버퍼에 남아있는 개행 문자 제거

    while (T--) {
        char recorded_sounds[MAX_WORDS][MAX_LENGTH];
        char sound[MAX_LENGTH];
        int num_recorded = 0;

        // 녹음된 소리 입력
        fgets(sound, sizeof(sound), stdin) ;

        sound[strcspn(sound, "\n")] = '\0';

        // 문자열 토큰화
        char *token = strtok(sound, " ");
        while (token != NULL) {
            if (num_recorded < MAX_WORDS) {
                strcpy(recorded_sounds[num_recorded++], token);
            }
            token = strtok(NULL, " ");
        }

        int is_fox_sound[MAX_WORDS];
        for (int i = 0; i < num_recorded; i++) {
            is_fox_sound[i] = 1;  // 모든 소리를 여우 소리로 가정
        }

        // 동물 소리 입력
        while (1) {
            fgets(sound, sizeof(sound), stdin);

            sound[strcspn(sound, "\n")] = '\0';

            if (strcmp(sound, "what does the fox say?") == 0) {
                break;
            }

            strtok(sound, " ");  // 동물 이름 제거
            strtok(NULL, " ");   // "goes" 제거
            char *animal_sound = strtok(NULL, " ");

            // 녹음된 소리에서 동물 소리를 찾고, 여우 소리가 아님을 표시
            for (int i = 0; i < num_recorded; i++) {
                if (strcmp(recorded_sounds[i], animal_sound) == 0) {
                    is_fox_sound[i] = 0;
                }
            }
        }

        // 여우의 소리 출력
        int is_first = 1;
        for (int i = 0; i < num_recorded; i++) {
            if (is_fox_sound[i]) {
                if (!is_first) {
                    printf(" ");
                }
                printf("%s", recorded_sounds[i]);
                is_first = 0;
            }
        }
        if (!is_first) {
            printf("\n");
        }
    }

    return 0;
}
