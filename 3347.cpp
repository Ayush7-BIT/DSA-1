#include <bits/stdc++.h>
using namespace std;
int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int n = nums.size();
    if (n == 0) return 0;
    // Build frequency of exact values
    unordered_map<long long,int> freq;
    freq.reserve(n*2);
    for (int x : nums) ++freq[x];

    // Build start/end counts for intervals [nums[i]-k, nums[i]+k]
    unordered_map<long long,int> starts, ends;
    starts.reserve(n*2); ends.reserve(n*2);
    vector<long long> coords;
    coords.reserve(3*n);
    for (int x : nums) {
        long long L = (long long)x - k;
        long long R = (long long)x + k;
        ++starts[L];
        ++ends[R];
        coords.push_back(L);
        coords.push_back(R);
    }
    // Ensure we visit coordinates that are exact nums values (for freq recordings)
    for (auto &p : freq) coords.push_back(p.first);

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    long long curr = 0;
    int coverage_max_any = 0;
    unordered_map<long long,int> coverageAtValue; // coverage at points that are in coords (we only need at nums)
    coverageAtValue.reserve(freq.size()*2);

    for (long long x : coords) {
        // process all starts at x (intervals that begin at x include x)
        if (starts.count(x)) curr += starts[x];
        // record coverage at x (this is coverage of any point x)
        coverage_max_any = max(coverage_max_any, (int)curr);
        if (freq.count(x)) {
            coverageAtValue[x] = (int)curr;
        }
        // process ends at x AFTER recording so intervals ending at x still include x
        if (ends.count(x)) curr -= ends[x];
    }

    int ans = 1;
    // Case 1: best target anywhere (not necessarily an existing value)
    ans = max(ans, min(coverage_max_any, numOperations));

    // Case 2: best target equal to an existing value v
    for (auto &p : freq) {
        long long v = p.first;
        int cntEqual = p.second;
        int cov = 0;
        auto it = coverageAtValue.find(v);
        if (it != coverageAtValue.end()) cov = it->second;
        // achievable frequency when targeting v:
        int achievable = min(cov, cntEqual + numOperations);
        ans = max(ans, achievable);
    }

    // if no operations and array has duplicates, freq may be >1 already handled
    return ans;
}
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 1;
    int numOperations = 2;
    int result = maxFrequency(nums, k, numOperations);
    cout << "Max Frequency: " << result << endl;
    return 0;
}