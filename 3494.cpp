#include <bits/stdc++.h>
using namespace std;
long long minTime(vector<int>& skill, vector<int>& mana) {
    int n = (int)skill.size();
    int m = (int)mana.size();
    if (n == 0 || m == 0) return 0LL;
    vector<long long> prevPref(n+1, 0), currPref(n+1, 0);
    for (int i = 0; i < n; ++i) prevPref[i+1] = prevPref[i] + (long long)skill[i] * mana[0];

    long long s = 0;

    for (int j = 1; j < m; ++j) {
        currPref[0] = 0;
        for (int i = 0; i < n; ++i){
            currPref[i+1] = currPref[i] + (long long)skill[i] * mana[j];
        }
        long long delta = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            long long val = prevPref[i+1] - currPref[i];
            if (val > delta) delta = val;
        }
        s += delta;
        swap(prevPref, currPref);
    }
    
    long long totalLast = prevPref[n];
    return s + totalLast;
}
int main() {
    vector<int> skill = {1, 2, 3};
    vector<int> mana = {4, 5, 6};
    cout << minTime(skill, mana) << endl;
    return 0;
}