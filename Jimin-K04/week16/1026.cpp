/*a는 오름차순,, b는 내림차순으로 정렬 후 곱하기.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;
int main() {
	int N, num, result = 0;
	vector<int> A;
	vector<int> B;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		A.push_back(num);
	}
	for (int i = 0; i < N; i++) {
		cin >> num;
		B.push_back(num);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	for (int i = 0; i < N; i++) {
		result += A[i] * B[i];
	}

	cout << result;
}