#include <bits/stdc++.h>
using namespace std;
int triangularSum(vector<int>& nums) {
    int n = nums.size();
    for (int len = n; len > 1; --len) {
        for (int i = 0; i < len - 1; ++i) {
            nums[i] = (nums[i] + nums[i + 1]) % 10;
        }
    }
    return nums[0];
}
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> nums2 = {5};
    cout << triangularSum(nums) << endl;
    cout << triangularSum(nums2) << endl;
    return 0;
}