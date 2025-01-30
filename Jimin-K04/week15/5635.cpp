#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //std::sort 사용, 최적의 성능을 제공하는 정렬 함수
using namespace std;

class Person {
public:
	string _name;
	int _year;
	int _month;
	int _day;

	Person(string name, int year, int month, int day) {
		_name = name;
		_year = year;
		_month = month;
		_day = day;
	}
};

int main() {
	int n, year, month, day;
	string name;
	vector<Person> people;
	vector<Person> max_list;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> name >> day >> month >> year;
		people.emplace_back(name, year, month, day);
	}

	//년도 기준 정렬
	for (int i = 0; i < n; i++) {
		sort(people.begin(), people.end(), [](const Person& p1, const Person& p2) {
			if (p1._year == p2._year) {
				if (p1._month == p2._month) {
					return p1._day < p2._day;
				}
				else return p1._month < p2._month;
			}
			else return p1._year < p2._year;
		});
	}

	cout << people[n-1]._name << '\n' << people[0]._name;
}