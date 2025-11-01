#include <bits/stdc++.h>
using namespace std;
vector<int> getSneakyNumbers(vector<int>& nums) {
    int n = nums.size() - 2; 
    vector<int> freq(n, 0);
    vector<int> result;

    for (int num : nums) {
        freq[num]++;
        if (freq[num] == 2) {
            result.push_back(num);
        }
    }

    return result;
}
int main() {
    vector<int> nums={1,2,3,2,3,4,5};
    vector<int> result = getSneakyNumbers(nums);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}