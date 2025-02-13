#include <iostream>

using namespace std;

int main() {
	int K;
	cin >> K;

	int A = 1, B = 0;
	for (int i = 0; i < K;i++) {
		int next_A = B;
		int next_B = A + B;
		A = next_A;
		B = next_B;
	}
	cout << A << " " << B;
}
