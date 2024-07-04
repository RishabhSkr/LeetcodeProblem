class Solution {
public:
int dp[71][71][71];
int n;
int solve(int i,int j1,int j2,int n,int m,vector<vector<int>>& grid){
      // base case
      if(i>=n || i<0 || j1<0 || j1>=m || j2<0 || j2>=m)return -1e8;
      if(i==n-1){
          if(j1==j2){
              return grid[i][j1];
          }else return grid[i][j1] + grid[i][j2];
      }
      if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
      int maxi =0;
      // expplore paths
      // for one pos of any robo ->3 choices available i.e total 9 poss dirn possible
      for(int delj1=-1;delj1<=1;delj1++){
          for(int delj2=-1 ;delj2<=1;delj2++){
              if(j1!=j2){
                  maxi= max(maxi,grid[i][j1]+grid[i][j2]+solve(i+1,j1+delj1,j2+delj2,n,m,grid));
              }else{
                  maxi= max(maxi,grid[i][j1]+solve(i+1,j1+delj1,j2+delj2,n,m,grid));
              }
          }
      }
      return dp[i][j1][j2]=maxi;
  }
    int cherryPickup(vector<vector<int>>& grid) {
        n= grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m-1,n,m,grid);
    }
};