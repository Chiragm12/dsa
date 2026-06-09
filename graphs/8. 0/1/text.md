# solution
``` cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        // 2-d dynamic visited array
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // this is to store the ans aka the distance
        vector<vector<int>> dist(n, vector<int>(m, 0));
        // {{row,col},dist}
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        vector<int> delrow = {+1, 0, -1, 0};
        vector<int> delcol = {0, -1, 0, +1};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            // updating the dist matrix one by one
            dist[r][c] = steps;
            for (int i = 0; i < 4; i++) {
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    vis[nr][nc] == 0) {
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, steps + 1});
                }
            }
        }
        return dist;
    }
};
``` 