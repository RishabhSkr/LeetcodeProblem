class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>> pq; // max heap (we will use it as min heap)
        dist[0][0]=0;
        pq.push({0, 0, 0});
        // 4 dirn
       int dirn[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  // Changed direction order to match grid values
        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();
            int currCost = -1 * top[0];
            int x = top[1];
            int y = top[2];
            if (currCost > dist[x][y])
                continue; // Skip if we found a better path
            if (x == m - 1 && y == n - 1)
                return currCost;
            int currDir = grid[x][y] - 1; // Convert 1-based to 0-based direction
            for (int i = 0; i < 4; i++) {
                int nx = x + dirn[i][0];
                int ny = y + dirn[i][1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                int newCost = currCost + (i == currDir ? 0 : 1);

                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({-1*newCost, nx, ny});
                }
            }
        }
        return dist[m-1][n-1];
    }
};