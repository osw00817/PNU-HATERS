#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	map < string, bool > names; //존재하지 않는 키 값에 접근하면 자동으로 추가되며 bool 타입의 기본값은 false 임
	string name;
	vector<string> dbj;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> name;
		names.insert(make_pair(name, true));
	}
	for (int i = 0; i < M; i++) {
		cin >> name;
		if (names[name]) dbj.push_back(name);
	}

	sort(dbj.begin(), dbj.end());
	cout << dbj.size() << "\n";
	for (string x : dbj) {
		cout << x << "\n";
	}
}*/