/*두 수의 합이 측정 값이 되는지 확인하면 되니까 포인터를 양쪽 끝에서 시작해
중간으로 모이는 식으로,, 정렬 후 사용*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, num, cnt = 0;
	vector<int>::iterator point1, point2;
	vector<int> arr;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	
	sort(arr.begin(), arr.end());
	point1 = arr.begin();
	point2 = arr.end() - 1;

	while (point1 < point2) {
		if (*point1 + *point2 == M) {
			cnt++;
			point1++;
		}
		else if (*point1 + *point2 < M) point1++;
		else point2--;
	}

	cout << cnt;

}*/