class Solution {
public:
    int ans=0;
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dpx(n, vector<int>(m, 0));
        vector<vector<int>> dpy(n, vector<int>(m , 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
               dpx[i][j]=(grid[i][j]=='X')?1:0;
               dpy[i][j]=(grid[i][j]=='Y')?1:0;
                
                if (i > 0) {
                    dpx[i][j] += dpx[i-1][j];
                    dpy[i][j] += dpy[i-1][j];
                }
                if (j > 0) {
                    dpx[i][j] += dpx[i][j-1];
                    dpy[i][j] += dpy[i][j-1];
                }
                // remove the duplicate count submatrices i-1,j-1
                if (i > 0 && j > 0) {
                    dpx[i][j] -= dpx[i-1][j-1];
                    dpy[i][j] -= dpy[i-1][j-1];
                }
               
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i <n; ++i) {
            for (int j = 0; j < m; ++j) {
                int countX = dpx[i][j];
                int countY = dpy[i][j];
                if (countX > 0 && countX == countY) {
                    ans++;
                }
            }
        }
        
        return ans;
}

};