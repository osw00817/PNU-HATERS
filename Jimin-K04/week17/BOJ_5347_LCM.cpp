/*lcm  = a*b/gcd()*/
#include <iostream>
using namespace std;

long gcd(int a, int b) {
	while (b > 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}
long lcm(int a, int b) {
	return a/ gcd(a, b)*b; //오버플로우 방지 - 나눗셈 먼저
}
/*int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		cout << lcm(a, b) << "\n";
	}

}*/