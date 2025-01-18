class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        priority_queue<vector<int>> pq; // max heap (we will use it as min heap)
        pq.push({0, 0, 0});
        // 4 dirn
        int dirn[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();
            int currCost = -1 * top[0];
            int x = top[1];
            int y = top[2];
            if (x >= m || x < 0 || y < 0 || y >= n || vis[x][y])
                continue;
            vis[x][y] = 1;
            if (x == m - 1 && y == n - 1)
                return currCost;

            if (grid[x][y] == 1) {
                pq.push({-1 * currCost, x, y + 1});
                pq.push({-1 * (currCost + 1), x, y - 1});
                pq.push({-1 * (currCost + 1), x + 1, y});
                pq.push({-1 * (currCost + 1), x - 1, y});
            } else if (grid[x][y] == 2) {
                pq.push({-1 * (currCost + 1), x, y + 1});
                pq.push({-1 * currCost, x, y - 1});
                pq.push({-1 * (currCost + 1), x + 1, y});
                pq.push({-1 * (currCost + 1), x - 1, y});
            } else if (grid[x][y] == 3) {
                pq.push({-1 * (currCost + 1), x, y + 1});
                pq.push({-1 * (currCost + 1), x, y - 1});
                pq.push({-1 * currCost, x + 1, y});
                pq.push({-1 * (currCost + 1), x - 1, y});
            } else if (grid[x][y] == 4) {
                pq.push({-1 * (currCost + 1), x, y + 1});
                pq.push({-1 * (currCost + 1), x, y - 1});
                pq.push({-1 * (currCost + 1), x + 1, y});
                pq.push({-1 * currCost, x - 1, y});
            }
        }
        return 0;
    }
};