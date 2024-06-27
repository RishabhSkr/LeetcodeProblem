class Solution {
public:
int dp[101][101];
    int cnt=0;
int solve(int i,int j ,int m,int n){
        if(i==m-1 && j==n-1){
            // dp[i][j]=cnt++;
            return 1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int right =0,down =0;
        if(i+1<m && j<n)right =solve(i+1,j,m,n);
        if(i<m && j+1<n )down =solve(i,j+1,m,n);
        return dp[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,n);
        // return cnt;
    }
};