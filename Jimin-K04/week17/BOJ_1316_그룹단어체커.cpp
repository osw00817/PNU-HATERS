/*char �� ���ڸ� �ϳ��� �޴´�
���ڸ� ���������� ���ڷ� ��ȯ���� üũ �迭�� ���� (a-z) -> (0-25)
���� ���� ���� ���ڰ� üũ �迭�� �����Ѵٸ� ���� �ܾ� �ޱ�
������ ��ȸ�ص� �ߺ��� ���ٸ� cout ++*/
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