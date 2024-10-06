#include <stdio.h>
#include <math.h>
void hanoi(int n, char from, char temp, char to) {
	if (n == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	hanoi(n - 1, from, to, temp);
	printf("%d %d\n", from, to);
	hanoi(n - 1, temp, from, to);
}


unsigned long long hanoicount(int n) {
	unsigned long long N = 1;
	for (int i = 0; i < n ; i++) {
		N *= 2;
	}
	return N - 1;
	
} 


int main() {
	int n;
	scanf("%d", &n);
	unsigned long long arr[2] = { 0,0 };
	unsigned long long base = 100000000000000000LL; //19자리
	if (n >= 50) {
		long long count = hanoicount(60);
		arr[0] = count / base;
		arr[1] = count % base;
		for (int i = 60; i < n; i++) {
			arr[0] *= 2;
			arr[1] *= 2;
			if (arr[1] > base) {
				arr[0] += arr[1] / base;
				arr[1] = arr[1] % base;
			}			
			arr[1] -= 1;
		}
		printf("%llu%lld\n", arr[0], arr[1]);
	}
	else printf("%llu\n", hanoicount(n));

	if(n<=20) hanoi(n, '1','2', '3');


	return 0;
}
