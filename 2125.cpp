#include <bits/stdc++.h>
using namespace std;
int numberOfBeams(vector<string>& bank) {
    int prevCount = 0, totalBeams = 0;

    for (string row : bank) {
        int currCount = count(row.begin(), row.end(), '1');
        if (currCount > 0) {
            totalBeams += prevCount * currCount;
            prevCount = currCount;
        }
    }

    return totalBeams;
}
int main() {
    vector<string> bank = {"011001", "000000", "010100", "001000"};
    cout << numberOfBeams(bank);
    return 0;
}