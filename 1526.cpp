#include <bits/stdc++.h>
using namespace std;
int minNumberOperations(vector<int>& target) {
    int n = target.size();
    int operations = target[0]; 
    for (int i = 1; i < n; ++i) {
        if (target[i] > target[i - 1]) {
            operations += target[i] - target[i - 1];
        }
    }
    return operations;
}
int main() {
    vector<int> target={1,2,3,2,1};
    cout<<minNumberOperations(target);
    return 0;
}