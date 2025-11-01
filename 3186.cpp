#include <bits/stdc++.h>
using namespace std;
long long maximumTotalDamage(vector<int>& power) {
    unordered_map<long long, long long> freq;
    for (int p : power) {
        freq[p] += p;
    }

    vector<long long> vals;
    for (auto &it : freq) {
        vals.push_back(it.first);
    }
    sort(vals.begin(), vals.end());

    int n = vals.size();
    vector<long long> dp(n, 0);

    dp[0] = freq[vals[0]];

    for (int i = 1; i < n; i++) {
        long long take = freq[vals[i]];
        int j = i - 1;

        while (j >= 0 && vals[i] - vals[j] <= 2) {
            j--;
        }

        if (j >= 0) take += dp[j];

        long long skip = dp[i - 1];
        dp[i] = max(skip, take);
    }

    return dp[n - 1];
}
int main() {
    vector<int> power = {1, 2, 3, 4, 5};
    cout << maximumTotalDamage(power) << endl;
    return 0;
}