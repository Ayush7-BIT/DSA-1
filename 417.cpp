#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();

    vector<vector<int>> pacific(m, vector<int>(n, 0));
    vector<vector<int>> atlantic(m, vector<int>(n, 0));
    vector<vector<int>> result;

    // Directions: up, down, left, right
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    function<void(int,int,vector<vector<int>>&)> dfs = [&](int r, int c, vector<vector<int>>& ocean) {
        ocean[r][c] = 1;
        for (auto [dr,dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if (ocean[nr][nc]) continue;
            if (heights[nr][nc] < heights[r][c]) continue; // must be >=
            dfs(nr, nc, ocean);
        }
    };

    // Pacific edges (top row + left col)
    for (int c = 0; c < n; c++) dfs(0, c, pacific);
    for (int r = 0; r < m; r++) dfs(r, 0, pacific);

    // Atlantic edges (bottom row + right col)
    for (int c = 0; c < n; c++) dfs(m-1, c, atlantic);
    for (int r = 0; r < m; r++) dfs(r, n-1, atlantic);

    // Collect results
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (pacific[r][c] && atlantic[r][c]) {
                result.push_back({r, c});
            }
        }
    }
    return result;
}
int main() {
    vector<vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    vector<vector<int>> result = pacificAtlantic(heights);
    for (const auto& cell : result) {
        cout << "[" << cell[0] << ", " << cell[1] << "]\n";
    }
    return 0;
}