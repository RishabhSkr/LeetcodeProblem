class Solution {
public:   
    vector<vector<int>>dp;
    int n;
    // int solve(int i,int buy,int fee,vector<int>&prices){
    //     if(i>=n)return 0;
    //     if(dp[i][buy]!=-1)return dp[i][buy];
    //     //buy
    //     int profit = 0;
    //     if(buy){
    //         profit = max(-prices[i]+solve(i+1,0,fee,prices),solve(i+1,1,fee,prices));
    //     }
    //     else{
    //         profit =max(prices[i]-fee+solve(i+1,1,fee,prices),0+solve(i+1,0,fee,prices));
    //     }
    //     return dp[i][buy]=profit;
    // }

    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        int cash = 0,hold = -prices[0];
        for(int i =1;i<n;++i){
            int prevCash = cash;
            hold = max(prevCash-prices[i],hold);
            cash =max(prices[i]-fee+hold,prevCash);
            
            
        }
        return cash;
    }
};