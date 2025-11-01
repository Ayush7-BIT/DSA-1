#include <bits/stdc++.h>
using namespace std;
int maxDistinctElements(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    long long prev = LLONG_MIN / 4;
    int distinct = 0;
    
    for (long long x : nums) {
        long long low = x - k;
        long long high = x + k;
        long long candidate = max(prev + 1, low);
        if (candidate <= high) {
            ++distinct;
            prev = candidate;
        }
    }
    return distinct;
}
int main() {
    vector<int> nums = {1, 3, 4, 5, 7};
    int k = 2;
    cout << maxDistinctElements(nums, k) << endl;
    return 0;
}