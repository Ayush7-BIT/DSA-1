#include <bits/stdc++.h>
using namespace std;
int findSmallestInteger(vector<int>& nums, int value) {
    unordered_map<int, int> freq;
    for(int num : nums){
        int mod = ((num % value) + value) % value;  
        freq[mod]++;
    }

    int mex = 0;
    while (freq[mex % value] > 0) {
        freq[mex % value]--; 
        mex++;
    }

    return mex;
}
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int value = 3;
    cout << findSmallestInteger(nums, value) << endl;
    return 0;
}