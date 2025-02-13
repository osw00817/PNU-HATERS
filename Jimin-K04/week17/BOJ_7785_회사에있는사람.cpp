#include <iostream>
#include <string>
#include <map>
using namespace std;

/*int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string name, state;
	map <string, bool, greater<string>> list; //map 은 key 값을 기준으로 자동으로 정렬 해줌

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> name >> state;
		if (state == "enter") {
			list.insert(make_pair(name, true));
		}
		else {
			list.erase(name);
		}
	}

	for (const auto& name : list) {
		cout << name.first << "\n";
	}
}*/