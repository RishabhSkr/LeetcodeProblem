class Solution {
public:
    vector<vector<vector<int>>>dp;
    int n ;
    int solve(int i,int day,int buy,vector<int>&prices){
        if(day==0)return 0;
        if(i>=n)return 0;
        if(dp[i][day][buy]!=-1)return dp[i][day][buy];
        //buy
        int profit = 0;
        if(buy){
            profit = max(-prices[i]+solve(i+1,day,0,prices),solve(i+1,day,1,prices));
        }
        else{
            profit =max(prices[i]+solve(i+1,day-1,1,prices),solve(i+1,day,0,prices));
        }
        return dp[i][day][buy]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        dp.resize(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return solve(0,k,1,prices);
    }
};