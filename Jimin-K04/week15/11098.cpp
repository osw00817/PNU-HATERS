#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player {
private:
	vector<int> price_list;
	vector<string> name_list;
public:
	void add_new_player(int _price, string _name) {
		price_list.push_back(_price);
		name_list.push_back(_name);
	}
	string find_max_price(int cnt) {
		int max_idx = 0;
		int i;
		for (i = 0; i < cnt; i++) {
			if (price_list[max_idx] < price_list[i]) max_idx = i;
		}
		return name_list[max_idx];
	}
};

int main() {
	int T, player_num, price;
	string name;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> player_num;
		Player players;
		for (int j = 0; j < player_num; j++) {
			cin >> price >> name;
			players.add_new_player(price, name);
		}
		cout << players.find_max_price(player_num) << '\n';
	}
}