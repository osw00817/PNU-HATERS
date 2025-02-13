#include <iostream>
#include <vector>
#include <set>
#include <algorithm> 

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<string> hear;
    string name;
    for (int i = 0; i < N; i++) {
        cin >> name;
        hear.insert(name);
    }

    vector<string> ans;
    for (int i = 0; i < M; i++) {
        cin >> name;
        if (hear.find(name) != hear.end()) ans.push_back(name);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;

    for (string person : ans) {
        cout << person << endl;
    }
    return 0;
}
