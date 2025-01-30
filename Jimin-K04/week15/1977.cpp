/*��Ʈ M���� ��Ʈ N ���� �˻�*/

#include <iostream>
#include <cmath>

int main() {
	int M, N, start, end, sum = 0, min;
	std::cin >> M >> N;

	start = ceil(sqrt(M)); //�ø�
	end = floor(sqrt(N)); //����
	min = start*start;
	
	for (int st = start; st <= end; st++) {
		sum += st * st;
	}

	if (!sum) std::cout << "-1";
	else std::cout << sum << '\n' << min;
}
