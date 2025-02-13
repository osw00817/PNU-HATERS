#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> arr(N);
	for (int i = 0;i < N;i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	int front = 0, rear = N - 1, ans = 0;
	while (front < rear) {
		if (arr[front] + arr[rear] == M) {
			ans++;
			front++;
			rear--;
		}
		else if (arr[front] + arr[rear] > M) rear--;
		else front++;
	}
	cout << ans;
}
