#include <bits/stdc++.h>
using namespace std;
int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<long long> dp(n, 0);
        long long result = LLONG_MIN;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = energy[i] + ( (i + k < n) ? dp[i + k] : 0LL );
            result = max(result, dp[i]);
        }
        return result;
    }
int main() {
    vector<int> energy = {1, 2, 3, 4, 5};
    int k = 2;
    cout << maximumEnergy(energy, k) << endl;
    return 0;
}