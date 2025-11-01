#include <bits/stdc++.h>
using namespace std;
int largestPerimeter(vector<int>& nums) {
    int ans=0;
    sort(nums.begin(), nums.end(), greater<int>());
    for (int i = 0; i < nums.size() - 2; i++) {
        if (nums[i + 1] + nums[i + 2] > nums[i]) {
            int q=nums[i] + nums[i + 1] + nums[i + 2];
            ans=max(ans,q);
        }
    }
    return ans;
}
int main() {
    vector<int> nums={2,1,2};
    cout<<largestPerimeter(nums);
    return 0;
}