/*조합 문제, 대각선의 교점의 개수를 구하려면
4개의 꼭짓점을 선택하는 조합의 수와 같음*/

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