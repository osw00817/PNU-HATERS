/*중복을 체크하는 배열을 따로 만들어서.. 근데 마음에 안드네*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, num;
	int check_dup[2001] = { 0 }; //음수도 다뤄야 하기 때문에 배열 크기를 2001 으로,, -1000~1000 -> 0 ~ 2000
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