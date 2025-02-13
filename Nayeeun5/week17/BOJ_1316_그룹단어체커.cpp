#include <iostream>
#include <string>

using namespace std;

int group(string& s) {
    int aph[26] = { 0 };
    char pre = 0;

    for (char c : s) {
        if (c != pre) {
            if (aph[c - 'a']) return 0;
            aph[c - 'a'] = 1;
        }
        pre = c;
    }
    return 1;
}

int main() {
    int n, cnt = 0;
    cin >> n;

    while (n--) {
        string word;
        cin >> word;
        if (group(word)) cnt++;
    }
    cout << cnt;
    return 0;
}
