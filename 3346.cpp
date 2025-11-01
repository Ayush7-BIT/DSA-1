#include <bits/stdc++.h>
using namespace std;
int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<long long> L(n), R(n);
    unordered_map<long long,int> freq; 
    freq.reserve(n*2);
    for (int i = 0; i < n; ++i) {
        long long val = nums[i];
        L[i] = val - (long long)k;
        R[i] = val + (long long)k;
        freq[val]++; 
    }
    vector<long long> candidates;
    candidates.reserve(3*n);
    for (int i = 0; i < n; ++i) {
        candidates.push_back(L[i]);
        candidates.push_back(R[i]);
        candidates.push_back((long long)nums[i]);
    }
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    map<long long, int> events;
    for (int i = 0; i < n; ++i) {
        events[L[i]] += 1;
        events[R[i] + 1] -= 1;
    }
    int maxFreq = 1;
    long long currCover = 0;
    auto evIt = events.begin();
    for (long long t : candidates) {
        while (evIt != events.end() && evIt->first <= t) {
            currCover += evIt->second;
            ++evIt;
        }
        int coverT = (int)currCover;
        int equalT = 0;
        auto itf = freq.find(t);
        if (itf != freq.end()) equalT = itf->second;
        int achievable = min(coverT, equalT + numOperations);
        if (achievable > maxFreq) maxFreq = achievable;
    }

    return maxFreq;
}
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 1;
    int numOperations = 2;
    int result = maxFrequency(nums, k, numOperations);
    cout << "Max Frequency: " << result << endl;
    return 0;
}