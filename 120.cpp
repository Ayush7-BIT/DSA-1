#include <bits/stdc++.h>
using namespace std;
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp = triangle.back(); 
    for (int row = n - 2; row >= 0; --row) {
        for (int col = 0; col <= row; ++col) {
            dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
        }
    }
    return dp[0];
}
int main() {
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    cout << minimumTotal(triangle) << endl;
    return 0;
}
    