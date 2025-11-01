#include <bits/stdc++.h>
using namespace std;
bool simulate(vector<int> nums, int start, int dir) {
    int n = nums.size();
    int curr = start;
    int d = dir; 
    while (curr >= 0 && curr < n) {
        if (nums[curr] == 0) {
            curr += d; 
        } else {
            nums[curr]--;  
            d = -d;        
            curr += d;    
        }
    }


    for (int x : nums)
        if (x != 0)
            return false;
    return true;
}

int countValidSelections(vector<int>& nums) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            if (simulate(nums, i, 1)) count++;  
            if (simulate(nums, i, -1)) count++;  
        }
    }

    return count;
}
int main() {
    vector<int> nums = {1, 1, 0, 0, 1};
    cout << countValidSelections(nums);
    return 0;
}           