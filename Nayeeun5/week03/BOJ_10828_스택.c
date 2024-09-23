#include<stdio.h>
#include<string.h>
int cnt = 0, num, x[100001];
void push(int n) {
	x[cnt] = n;
	cnt++;
}
void pop() {
	if (cnt != 0) {
		cnt--;
		printf("%d\n", x[cnt]);
		x[cnt] = 0;
	}
	else printf("%d\n", -1);
}
void size() {
	printf("%d\n", cnt);
}
void empty() {
	if (cnt != 0) printf("%d\n", 0);
	else printf("%d\n", 1);
}
void top() {
	if (cnt != 0) printf("%d\n", x[cnt - 1]);
	else printf("%d\n", -1);
}
int main() {
	int n=0, str[6] = {0};
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%s", str);
		if (!strcmp(str, "push")) {
			scanf("%d", &n);
			push(n);
		}
		else if (!strcmp(str, "pop")) pop();
		else if (!strcmp(str, "size")) size();
		else if (!strcmp(str, "empty")) empty();
		else if (!strcmp(str, "top")) top();
	}
}
