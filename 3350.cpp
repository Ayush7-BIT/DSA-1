#include <bits/stdc++.h>
using namespace std;

int maxIncreasingAdjacentSubarrays(vector<int>& nums) {
    int n = nums.size();
    vector<int> incL(n, 1), incR(n, 1);
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1])
            incL[i] = incL[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1])
            incR[i] = incR[i + 1] + 1;
    }

    int maxK = 0;

    for (int i = 1; i < n; i++) {
        maxK = max(maxK, min(incL[i - 1], incR[i]));
    }

    return maxK;
}

int main() {
    vector<int> nums1 = {2,5,7,8,9,2,3,4,3,1};
    cout << maxIncreasingAdjacentSubarrays(nums1) << endl;

    vector<int> nums2 = {1,2,3,4,4,4,4,5,6,7};
    cout << maxIncreasingAdjacentSubarrays(nums2) << endl;

    return 0;
}
