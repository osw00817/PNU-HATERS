/*char 로 문자를 하나씩 받는다
문자를 받을때마다 숫자로 변환에서 체크 배열에 저장 (a-z) -> (0-25)
만약 새로 받은 문자가 체크 배열에 존재한다면 다음 단어 받기
끝까지 순회해도 중복이 없다면 cout ++*/
#include <iostream>
using namespace std;

/*int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string word;
	int N, j, cnt = 0;
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		int check[26] = { 0 };
		cin >> word;
		for (j = 0; j < word.size(); j++) {
			if (!check[word[j] - 'a']) {
				check[word[j] - 'a'] = 1;
			}
			else if (word[j] != word[j - 1]) break;
		}
		
		if (j == word.size()) cnt++;
	}

	cout << cnt;
}*/