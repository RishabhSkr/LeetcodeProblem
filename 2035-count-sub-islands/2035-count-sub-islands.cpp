class Solution {
public:
    vector<vector<int>> vis;
    int n, m;
    int dirn[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

    bool isSafe(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        return (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] == 1 || grid2[i][j] == 0);
    }

    bool dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vis[i][j] = 1;
        bool isSubIsland = true;
        if (grid1[i][j] == 0) {
            isSubIsland = false;
        }
        
        for (auto& dir : dirn) {
            int x = i + dir[0];
            int y = j + dir[1];
            if (!isSafe(x, y, grid1, grid2)) {
                if (grid2[x][y] == 1) {
                    if (!dfs(x, y, grid1, grid2)) {
                        isSubIsland = false;
                    }
                }
            }
        }
        return isSubIsland;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid2.size();
        m = grid2[0].size();
        int cnt = 0;
        vis.resize(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid2[i][j] == 1 && !vis[i][j]) {
                    if (dfs(i, j, grid1, grid2)) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
