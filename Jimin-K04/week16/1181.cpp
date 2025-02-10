/*�ߺ��� ���� ���� �ϹǷ� set �� ��� ->  set�� �ڵ����� �ߺ��� ���� �����Ѵ�
������ set�� ������ �� �ڵ����ĵǹǷ� ���� ���� �� ��Ĵ�� �����ϰ� �ʹٸ� �ٸ� �����̳ʷ�
�Űܼ� �����ؾ� �Ѵ�. -> ���ͷ� �ű��*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool sort_compare(const string& str1, const string& str2) { //bool Ÿ�� ��ȯ
	if (str1.length() == str2.length()) {
		return str1 < str2; //������ ����
	}
	else return str1.length() < str2.length();
}

int main() {
	int N;
	string word;
	set<string> word_set;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> word;
		//auto check = find(arr.begin(), arr.end(), word);
		//if (check == arr.end()) arr.push_back(word);
		word_set.insert(word);
	}
	//set �� vector �� ��ȯ
	vector<string> word_vec(word_set.begin(), word_set.end());
	sort(word_vec.begin(), word_vec.end(), sort_compare);

	for (string w : word_vec) {
		cout << w << "\n";
	}
}