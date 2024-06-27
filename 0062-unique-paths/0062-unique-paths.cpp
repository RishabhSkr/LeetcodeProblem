class Solution {
public:
int dp[101][101];
//     int cnt=0;
// int solve(int i,int j ,int m,int n){
//         if(i==m-1 && j==n-1){
//             // dp[i][j]=cnt++;
//             return 1;
//         }
//         if(dp[i][j]!=-1)return dp[i][j];
//         int right =0,down =0;
//         if(i+1<m && j<n)right =solve(i+1,j,m,n);
//         if(i<m && j+1<n )down =solve(i,j+1,m,n);
//         return dp[i][j]=right+down;
//     }
    int uniquePaths(int m, int n) {
        memset(dp,0,sizeof(dp));
        // return solve(0,0,m,n);

        // method -2 DP
         for(int i =m-1;i>=0;--i){
            for(int j =n-1;j>=0;--j){
                if(i==m-1 && j==n-1){
                    dp[i][j]=1;
                    continue;
                }
                int down =0,left =0;
                if(i+1<m){
                    left = dp[i+1][j];
                }
                if(j+1<n){
                    down = dp[i][j+1];
                }
                dp[i][j]=left+down;
            }
        }
        return dp[0][0];               
    }
};