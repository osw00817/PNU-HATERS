#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* cal(char* txt, char* bomb) {
	static char buffer[1000001];
	char* pos;
	int len = strlen(bomb);

	buffer[0] = '\0';

	while ((pos = strstr(txt, bomb)) != NULL) {
		strncat(buffer, txt, pos - txt);
		txt = pos + len;
	}
	strcat(buffer, txt);
	return buffer;
}

int main() {
	char txt[1000001];
	char bomb[37];
	scanf("%s", txt);
	scanf("%s", bomb);
	while (strstr(txt, bomb) != NULL) {
		strcpy(txt, cal(txt, bomb));
	}
	printf("%s", (strlen(txt) != 0) ? txt : "FRULA");
}