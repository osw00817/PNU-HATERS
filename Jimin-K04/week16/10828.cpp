#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack<int> stack;
	string cmd;
	int N, num;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> num;
			stack.push(num);
		}
		else if (cmd == "size") cout << stack.size() << "\n";
		else if (cmd == "empty") cout << stack.empty() << "\n";
		else if (cmd == "top") {
			if (stack.empty()) cout << "-1\n";
			else cout << stack.top() << "\n";
		}
		else if (cmd == "pop") {
			if (stack.empty()) cout << "-1\n";
			else {
				cout << stack.top() << "\n";
				stack.pop();
			}
		}
	}

}