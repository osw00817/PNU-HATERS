#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, time, sum = 0;
	vector<int> time_arr;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> time;
		time_arr.push_back(time);
	}
	sort(time_arr.begin(), time_arr.end());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			sum += time_arr[j];
		}
	}
	cout << sum;
}