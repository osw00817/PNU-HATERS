/*substr(pos, len) À» ÀÌ¿כ*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	vector<string> suffix;

	cin >> str;
	int str_len = str.length();

	for (int i = 0; i < str_len; i++) {
		suffix.push_back(str.substr(i, str_len - i));
	}
	sort(suffix.begin(), suffix.end());

	for (string word : suffix) {
		cout << word << "\n";
	}
}