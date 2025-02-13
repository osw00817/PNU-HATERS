#include <iostream>
#include <queue> // 유선순위 큐

using namespace std;

/*int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int> max_heap;
	int N, x;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;

		if (!x) {
			if (!max_heap.size()) cout << "0\n";
			else {
				cout << max_heap.top() << "\n";
				max_heap.pop();
			}
		}
		else max_heap.push(x);
	}
}*/