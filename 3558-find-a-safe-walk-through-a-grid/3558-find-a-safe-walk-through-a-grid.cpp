class Solution {
public:
    int dirn[4][2] = {{0,-1}, {0,1}, {1,0}, {-1,0}};
    int m, n;
    vector<vector<vector<int>>> dp;
    vector<vector<int>>vis;

    bool isSafe(int i, int j, vector<vector<int>>& grid, int h) {
        return (i >= 0 && i < m && j >= 0 && j < n && h > 0 && grid[i][j] != 2); 
    }

    int solve(int i, int j, vector<vector<int>>& grid, int h) {
        if (i == m - 1 && j == n - 1) {
            if (grid[i][j] == 1) h -= 1;  
            return h > 0;  
        }

        if(h <= 0) return dp[i][j][h] = 0;
        if (dp[i][j][h] != -1) return dp[i][j][h];

        if(vis[i][j]>=h)return false;
        vis[i][j]=h;
        if (grid[i][j] == 1) h--;  

        int res = 0;
        for (int d = 0; d < 4; d++) {
            int x = i + dirn[d][0];
            int y = j + dirn[d][1];
            if (isSafe(x, y, grid, h)) {
                res = res || solve(x, y, grid, h);
            }
        }

        return dp[i][j][h] = res; 
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();
        n = grid[0].size();

        dp.resize(m, vector<vector<int>>(n, vector<int>(health + 1, -1)));
        vis.resize(m,vector<int>(n,0));
        
        return solve(0, 0, grid, health);
    }
};
