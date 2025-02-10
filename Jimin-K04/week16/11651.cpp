#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//�ӵ� ����ȭ
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> items(N); //ũ�� �̸� ����, pair ���

	for (int i = 0; i < N; i++) {
		cin >> items[i].second >> items[i].first;
	}
	sort(items.begin(), items.end());

	for (pair<int, int> item : items) {
		cout << item.second << " " << item.first << "\n";
	}
}