class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int n,vector<int>&prices,int buy){
        // base case
        if(i>=n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit = 0;
        if(buy){
                // max(take,notTake)
            profit = max(-prices[i] +solve(i+1,n,prices,0),0+solve(i+1,n,prices,1));
        }else{
            profit = max(prices[i]+solve(i+1,n,prices,1),0+ solve(i+1,n,prices,0));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n+1,vector<int>(2,-1));
        return solve(0,n,prices,1);   
    }
};