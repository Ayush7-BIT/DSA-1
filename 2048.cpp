#include <bits/stdc++.h>
using namespace std;
bool isBalanced(int num) {
    string s = to_string(num);
    vector<int> count(10, 0);
    for (char c : s)
        count[c - '0']++;

    for (int d = 0; d < 10; ++d) {
        if (count[d] > 0 && count[d] != d)
            return false;
    }
    return true;
}
int nextBeautifulNumber(int n) {
    for (int i = n + 1; i <= 1224444; ++i) {
        if (isBalanced(i))
            return i;
    }
    return -1;
}
int main() {
    int n=10;
    cout << nextBeautifulNumber(n) << endl;
    return 0;
}