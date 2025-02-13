#include <iostream>

using namespace std;

int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int n;
	long long a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		int g = gcd(a, b);
		cout << a * b / g << endl;
	}
}
