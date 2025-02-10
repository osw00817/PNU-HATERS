#include <iostream>
#include <deque>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int> DQ;
	string cmd;
	int num, N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cmd;

		if (cmd == "size") cout << DQ.size() << "\n";
		else if (cmd == "empty") cout << DQ.empty() << "\n";
		else if (cmd == "front") {
			if (DQ.empty()) cout << "-1\n";
			else cout << DQ.front() << "\n";
		}
		else if (cmd == "back") {
			if (DQ.empty()) cout << "-1\n";
			else cout << DQ.back() << "\n";
		}
		else if (cmd == "push_front") {
			cin >> num;
			DQ.push_front(num);
		}
		else if (cmd == "push_back") {
			cin >> num;
			DQ.push_back(num);
		}
		else if (cmd == "pop_front") {
			if (DQ.empty()) cout << "-1\n";
			else {
				cout << DQ.front() << "\n";
				DQ.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (DQ.empty()) cout << "-1\n";
			else {
				cout << DQ.back() << "\n";
				DQ.pop_back();
			}
		}
	}
}