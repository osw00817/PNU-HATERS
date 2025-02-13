#include <iostream>

using namespace std;

long long koong[68];

void fibo() {
    koong[0] = 1;
    koong[1] = 1;
    koong[2] = 2;
    koong[3] = 4;

    for (int i = 4; i <= 67; i++) {
        koong[i] = koong[i - 1] + koong[i - 2] + koong[i - 3] + koong[i - 4];
    }
}

int main() {
    fibo();

    int T, K;
    cin >> T;
    while (T--) {
        cin >> K;
        cout << koong[K] << '\n';
    }

    return 0;
}
