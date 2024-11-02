#include<stdio.h>
#include<string.h>

void main() {
	int t, i;
	scanf("%d", &t);
	while (t--) {
		char animal[100][101], sounds[10001], name[101], goes[5], sound[101];
		char* fox;
		while (getchar() != '\n');
		gets(sounds);
		i = 0;
		while (1) {
			scanf("%s %s %s", name, goes, sound);
			if (strcmp(goes, "goes")) break;
			strcpy(animal[i++], sound);
		}
		fox = strtok(sounds, " ");
		while (fox != NULL) {
			
			int is_fox = 1;
			for (int k = 0; k < i; k++)
				if (!strcmp(fox, animal[k])) {
					is_fox = 0; break;
				}
			if (is_fox) printf("%s ", fox);
			fox = strtok(NULL, " ");
		}
		puts("");
	}
}
