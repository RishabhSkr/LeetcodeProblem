class Solution {
public:
    vector<vector<int>>dp;
    int solve(int start,int end){
        if(start>=end)return 0;
        if(dp[start][end]!=-1)return dp[start][end];
        int res = INT_MAX;
        for(int i =start;i<=end;i++){
            int ans = i+max(solve(start,i-1),solve(i+1,end)); // worst case n!
            res = min(res,ans);
        }
        return dp[start][end]=res;
    }
    int getMoneyAmount(int n) {
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(1,n);
    }
};