class Solution {
public:
    vector<vector<int>>dp;
    // int solve(int start,int end){
    //     if(start>=end)return 0;
    //     if(dp[start][end]!=-1)return dp[start][end];
    //     int res = INT_MAX;
    //     for(int i =start;i<=end;i++){
    //         int ans = i+max(solve(start,i-1),solve(i+1,end)); // worst case n!
    //         res = min(res,ans);
    //     }
    //     return dp[start][end]=res;
    // }
    int getMoneyAmount(int n) {
        dp.resize(n+2,vector<int>(n+2,0));
        // return solve(1,n);
        for(int start =n;start>=1;--start){
              for(int end =start;end<=n;++end){  
                if(start==end)continue;
                int res = INT_MAX;
                for(int i =start;i<=end;i++){
                    int ans = i+max(dp[start][i-1],dp[i+1][end]); 
                    res = min(res,ans);
                }
                dp[start][end]=res;
              }
        }
        return dp[1][n];
    }
};