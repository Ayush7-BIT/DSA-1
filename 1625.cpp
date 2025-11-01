#include <bits/stdc++.h>
using namespace std;
string addOperation(string s, int a) {
    for (int i = 1; i < s.size(); i += 2) {
        s[i] = (s[i] - '0' + a) % 10 + '0';
    }
    return s;
}

string rotateOperation(string s, int b) {
    int n = s.size();
    b = b % n;
    return s.substr(n - b) + s.substr(0, n - b);
}

string findLexSmallestString(string s, int a, int b) {
    queue<string> q;
    unordered_set<string> visited;
    string ans = s;

    q.push(s);
    visited.insert(s);

    while (!q.empty()) {
        string curr = q.front(); q.pop();
        ans = min(ans, curr);

        // Operation 1: Add
        string addStr = addOperation(curr, a);
        if (!visited.count(addStr)) {
            visited.insert(addStr);
            q.push(addStr);
        }

        // Operation 2: Rotate
        string rotateStr = rotateOperation(curr, b);
        if (!visited.count(rotateStr)) {
            visited.insert(rotateStr);
            q.push(rotateStr);
        }
    }

    return ans;
}
int main() {
    string s = "cba";
    int a = 1;
    int b = 1;
    string result = findLexSmallestString(s, a, b);
    cout << "Lexicographically Smallest String: " << result << endl;
    return 0;
}