/*중복된 값은 빼야 하므로 set 을 사용 ->  set은 자동으로 중복된 값을 제거한다
하지만 set은 삽입할 때 자동정렬되므로 삽입 이후 내 방식대로 정렬하고 싶다면 다른 컨테이너로
옮겨서 정렬해야 한다. -> 벡터로 옮기기*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool sort_compare(const string& str1, const string& str2) { //bool 타입 반환
	if (str1.length() == str2.length()) {
		return str1 < str2; //사전식 정렬
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
	//set 을 vector 로 변환
	vector<string> word_vec(word_set.begin(), word_set.end());
	sort(word_vec.begin(), word_vec.end(), sort_compare);

	for (string w : word_vec) {
		cout << w << "\n";
	}
}