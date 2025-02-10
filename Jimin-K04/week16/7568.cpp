/*정렬함수를 사용하면서 덩치 등수를 같이 계산,,*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Person {
public:
	int wei, hei;
	int score = 1;

	Person(int x, int y) {
		wei = x;
		hei = y;
	}
};

int main() {
	int N, x, y;

	cin >> N;
	vector<Person> people;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		Person person(x, y);
		people.push_back(person);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j != i) {
				if (people[j].wei > people[i].wei && people[j].hei > people[i].hei) people[i].score++;
			}
		}
	}

	for (Person p : people) {
		cout << p.score << " ";
	}
}