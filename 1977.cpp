#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, M;
	cin >> M >> N;
	int start = ceil(sqrt(M));
	int end = floor(sqrt(N));
	int sum = 0, min = start*start;
	
	for (int i = start;i <= end;i++) {
		sum += (i * i);
	}
	if (sum == 0) {
		cout << "-1";
		return 0;
	}
	cout << sum << endl;
	cout << min << endl;
	return 0;
}