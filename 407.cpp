#include <bits/stdc++.h>
using namespace std;
int trapRainWater(vector<vector<int>>& heightMap) {
    int m = heightMap.size();
    if (m == 0) return 0;
    int n = heightMap[0].size();
    if (n == 0) return 0;
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        pq.push({heightMap[i][0], i, 0});
        pq.push({heightMap[i][n - 1], i, n - 1});
        visited[i][0] = visited[i][n - 1] = true;
    }
    for (int j = 0; j < n; j++) {
        pq.push({heightMap[0][j], 0, j});
        pq.push({heightMap[m - 1][j], m - 1, j});
        visited[0][j] = visited[m - 1][j] = true;
    }
    int water = 0;
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int h = top[0], x = top[1], y = top[2];

        for (auto& d : dirs) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                visited[nx][ny] = true;
                if (heightMap[nx][ny] < h) {
                    water += h - heightMap[nx][ny];
                }

                pq.push({max(heightMap[nx][ny], h), nx, ny});
            }
        }
    }

    return water;
}
int main() {
    vector<vector<int>> heightMap = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 5},
        {6, 1, 2, 4, 1, 6},
        {5, 4, 5, 4, 4, 5}
    };
    cout << trapRainWater(heightMap) << endl;
    return 0;
}