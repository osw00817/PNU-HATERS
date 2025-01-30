#include <iostream>
#include <sstream>
#include <string>
#include <iomanip> //setw, setfill 사용 setw: 출력너비 지정, setfill: 빈공간을 채울 문자 설정
using namespace std;

class CUT {
private:
	int hour_ = 0, min_ = 0, sec_ = 0;
	int st_total_time = 0, cur_total_time = 0;
public:
	void count_time() {
		int tmp;
		if (cur_total_time > st_total_time) tmp = 24*3600 - (cur_total_time - st_total_time);
		else tmp = st_total_time - cur_total_time;
		hour_ = tmp / 3600;
		tmp %= 3600;
		min_ = tmp / 60;
		sec_ = tmp % 60;
	}
	void print_time() {
		cout << setw(2) << setfill('0') << hour_ << ':';
		cout << setw(2) << setfill('0') << min_ << ':';
		cout << setw(2) << setfill('0') << sec_;
	}

	CUT(int st_time[], int cur_time[]) {
		st_total_time += st_time[0]* 3600;
		st_total_time += st_time[1] * 60;
		st_total_time += st_time[2];

		cur_total_time += cur_time[0] * 3600;
		cur_total_time += cur_time[1] * 60;
		cur_total_time += cur_time[2];
	}
};


int main(){
	int cur_time[3], st_time[3], idx = 0;
	string current_time, start_time, token;

	cin >> current_time >> start_time;

	stringstream ss1(current_time);
	stringstream ss2(start_time);

	while (getline(ss1, token, ':')){
		cur_time[idx++] = stoi(token);
	}
	idx = 0;
	while (getline(ss2, token, ':')) {
		st_time[idx++] = stoi(token);
	}
	CUT cut(st_time, cur_time);
	cut.count_time();
	cut.print_time();
}