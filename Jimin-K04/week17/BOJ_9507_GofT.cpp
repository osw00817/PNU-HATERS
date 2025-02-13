#include <iostream>
using namespace std;

long long memo[70] = { 1, 1, 2, 3, 0, };

long long fibo(int n) {
	if (n < 2) return 1;
	else if (n == 2) return 2;
	else if (n == 3) return 4;
	else {
		if (memo[n]) return memo[n];
		else {
			memo[n] = fibo(n - 1) + fibo(n - 2) + fibo(n - 3) + fibo(n - 4);
			return memo[n];
		}
	}
}

/*int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << fibo(n) << "\n";
	}
}*/