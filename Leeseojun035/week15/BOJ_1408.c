#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string sNow, sMis;
    cin >> sNow >> sMis;

    int hourNow = stoi(sNow.substr(0,2));
    int minNow = stoi(sNow.substr(3,2));
    int secNow = stoi(sNow.substr(6,2));

    int hourMis = stoi(sMis.substr(0,2));
    int minMis = stoi(sMis.substr(3,2));
    int secMis = stoi(sMis.substr(6,2));

    if (secMis < secNow) {
        secMis += 60;
        minMis--;
    }
    secMis -= secNow;


    if (minMis < minNow) {
        minMis += 60;
        hourMis--;
    }
    minMis -= minNow;


    if (hourMis < hourNow) {
        hourMis += 24;
    }
    hourMis -= hourNow;


    cout <<setfill('0')<< setw(2) << hourMis << ":"
         << setw(2) << minMis << ":"
         << setw(2) << secMis << endl;

    return 0;
}
