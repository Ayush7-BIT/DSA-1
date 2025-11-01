#include <bits/stdc++.h>
using namespace std;
bool hasSameDigits(string s) {
    while (s.size() > 2) {
        string next = "";
        for (int i = 0; i < (int)s.size() - 1; i++) {
            int sum = (s[i] - '0' + s[i + 1] - '0') % 10;
            next += to_string(sum);
        }
        s = next;
    }
    return s[0] == s[1];
}
int main() {
    string s="3902";
    if (hasSameDigits(s)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}