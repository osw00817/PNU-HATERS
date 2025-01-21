/*
store bomb_string
use stack.

If the incoming char matches the first char of the bomb_sring, subsequent char are checked until they differ from the bomb_string.
If a different char appears, the check loop breaks.

When the string match the bomb_string completely, pop is executed for the length of the bomb_string

If the bomb_string is not found during a single cycle, the loop terminates.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000001

char* stack;
int top = -1;

void push(char x) {
	stack[++top] = x;
}

void pop(void) {
	top--;
}

int check_same_string(char* str_start, char* str, char* bomb_str) {

	for (char* bomb = bomb_str + strlen(bomb_str) - 1; bomb >= bomb_str;) {
		if (str < str_start || *str != *bomb) return 0;
		str--;
		bomb--;
	}
	return 1;
}
int main(void)
{
	char bomb_string[37];
	char input_string[MAX];

	scanf("%s %s", input_string, bomb_string);

	int string_len = strlen(input_string);
	int bomb_str_len = strlen(bomb_string);

	stack = malloc(sizeof(char) * (string_len + 1));

	for (int i = 0; i < string_len; i++) {
		push(input_string[i]);

		if (check_same_string(stack, &stack[top], bomb_string)) {
			for (int i = 0; i < bomb_str_len; i++) pop();
		}
	}
	push('\0');

	if (*stack == NULL) printf("FRULA");
	else printf("%s", stack);
}
