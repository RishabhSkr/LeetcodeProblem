class Solution {
public:   
    vector<vector<int>>dp;
    int n;
    int solve(int i,int buy,int fee,vector<int>&prices){
        if(i>=n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        //buy
        int profit = 0;
        if(buy){
            profit = max(-prices[i]+solve(i+1,0,fee,prices),solve(i+1,1,fee,prices));
        }
        else{
            profit =max(prices[i]-fee+solve(i+1,1,fee,prices),0+solve(i+1,0,fee,prices));
        }
        return dp[i][buy]=profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
         n = prices.size();
        dp.resize(n+1,vector<int>(2,0));

        dp[0][1]=prices[0];

        for(int i =n-1;i>=0;--i){
            for(int buy =0;buy<2;++buy){
                int profit = 0;
                if(buy){
                    profit = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    profit =max(prices[i]-fee+dp[i+1][1],dp[i+1][0]);
                }
                dp[i][buy]=profit;
            }
        }
        return dp[0][1];
    }
};