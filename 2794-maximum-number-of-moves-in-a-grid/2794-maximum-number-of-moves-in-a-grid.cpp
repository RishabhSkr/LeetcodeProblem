class Solution {
public:
    int m ,n;
    int solve(int i,int j,vector<vector<int>>&mat,int prev){
        if( i<0 || j<0 || i>=m || j>=n || mat[i][j]<=prev) return 0;
        int val = mat[i][j];
        mat[i][j]=0;
        return 1+max({solve(i+1,j+1,mat,val),solve(i-1,j+1,mat,val),solve(i,j+1,mat,val)});
    }
    int maxMoves(vector<vector<int>>& grid) {
        // plan =>DFS TC = O(n^2)
            int ans = 0;
            m=grid.size();
            n = grid[0].size();
            for(int i =0;i<m;++i){
                ans = max(ans,solve(i,0,grid,-1e6));
            }
            return ans-1;
    }
};