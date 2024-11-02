#include <stdio.h>
#include <math.h>
void HanoiCnt(int n, char num[]);

int hanoi(int n, int from_x, int to_x, int tmp_x)
{
	if (n == 1) {
		printf("%d %d\n", from_x, to_x);
		return 0;
	}
	hanoi(n - 1, from_x, tmp_x, to_x);
	printf("%d %d\n", from_x, to_x);
	hanoi(n - 1, tmp_x, to_x, from_x);
}

int main(void)
{
	int n;
	char arr[100] = { 0 };
	scanf("%d", &n);
	HanoiCnt(n, arr);

	if (n <= 20) {
		hanoi(n, 1, 3, 2);
	}
}

void HanoiCnt(int n, char num[])
{
	int carry, i, size = 1; //올림, 인덱스, 현재 자릿수 개수
	num[0] = 1;

	for (int j = 0; j < n; j++) {
		carry = 0;
		for (i = 0; i < size; i++) {
			int tmp = num[i] * 2 + carry;
			num[i] = tmp % 10;
			carry = tmp / 10;
		}
		if (carry > 0) {
			num[size] = carry;
			size++;
		}
	}

	carry = -1;
	for (i = 0; i < size; i++) {
		num[i] += carry;
		if (num[i] < 0) {
			num[i] += 10;
			carry = -1;
		}
		else carry = 0;
	}

	for (int j = size - 1; j >= 0; j--) printf("%d", num[j]);
	printf("\n");
}
