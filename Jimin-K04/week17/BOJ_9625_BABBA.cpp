/*규칙찾아서 푸는 dp 문제*/
#include <iostream>
#include <vector>

using namespace std;
/*int main() {
	int K;

	cin >> K;
	vector<pair<int, int>> dp(K+1);
	dp[0] = { 1,0 };
	dp[1] = { 0,1 };


	if (K > 2) {
		for (int i = 2; i <= K; i++) {
			dp[i].first = dp[i - 1].first + dp[i - 2].first;
			dp[i].second = dp[i - 1].second + dp[i - 2].second;
		}
	}
	cout << dp[K].first << " " << dp[K].second;
}*/