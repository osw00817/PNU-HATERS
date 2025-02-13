#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    int N;
    string name, record;
    cin >> N;

    unordered_set<string> people;
    while (N--) {
        cin >> name >> record;
        if (record == "enter") people.insert(name);
        else people.erase(name);
    }

    vector<string> ans(people.begin(), people.end());
    sort(ans.begin(), ans.end(), greater<string>());

    for (string person : ans) {
        cout << person << '\n';
    }
    return 0;
}
