/*루트 M부터 루트 N 까지 검사*/

#include <iostream>
#include <cmath>

int main() {
	int M, N, start, end, sum = 0, min;
	std::cin >> M >> N;

	start = ceil(sqrt(M)); //올림
	end = floor(sqrt(N)); //내림
	min = start*start;
	
	for (int st = start; st <= end; st++) {
		sum += st * st;
	}

	if (!sum) std::cout << "-1";
	else std::cout << sum << '\n' << min;
}
