/*�ߺ��� üũ�ϴ� �迭�� ���� ����.. �ٵ� ������ �ȵ��*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, num;
	int check_dup[2001] = { 0 }; //������ �ٷ�� �ϱ� ������ �迭 ũ�⸦ 2001 ����,, -1000~1000 -> 0 ~ 2000
	vector<int> arr;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (check_dup[num + 1000]) continue;

		arr.push_back(num);
		check_dup[num + 1000] = 1;
	}

	sort(arr.begin(), arr.end());

	for (int x : arr) {
		cout << x << " ";
	}

}