/*���� ����, �밢���� ������ ������ ���Ϸ���
4���� �������� �����ϴ� ������ ���� ����*/

#include <iostream>

int find_cross_point(int n) {
	int result = 1;
	for (int i = 0; i < 4; i++) {
		result *= (n - i);
	}
	return result / 24;
}
int main() {
	int N;
	std::cin >> N;

	std::cout << find_cross_point(N);
}