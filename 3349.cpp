#include <bits/stdc++.h>
using namespace std;
bool isIncreasing(const vector<int>& nums, int start, int k) {
    for (int i = start; i < start + k - 1; i++) {
        if (nums[i] >= nums[i + 1]) {
            return false;
        }
    }
    return true;
}
bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    for (int a = 0; a + 2 * k <= n; a++) {
        if (isIncreasing(nums, a, k) && isIncreasing(nums, a + k, k)) {
            return true;
        }
    }
    
    return false;
}
int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 2;
    if (hasIncreasingSubarrays(nums, k)) {
        cout << "Yes, there are two increasing subarrays of length " << k << endl;
    } else {
        cout << "No, there are no two increasing subarrays of length " << k << endl;
    }
    return 0;
}