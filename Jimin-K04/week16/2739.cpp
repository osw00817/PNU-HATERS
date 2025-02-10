#include <iostream>

class nine {
	int n;
	int number;
public:

	nine(int _n, int _number) {
		n = _n;
		number = _number;
	}

	void nine_print() {
		std::cout << n << " * " << number << " = " << n * number << "\n";
	}
};

int main() {
	int N;
	std::cin >> N;

	for (int i = 1; i <= 9; i++) {
		nine nine1(N, i);
		nine1.nine_print();
	}
}