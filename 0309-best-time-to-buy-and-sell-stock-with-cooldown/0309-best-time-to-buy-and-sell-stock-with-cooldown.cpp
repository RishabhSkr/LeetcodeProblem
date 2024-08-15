class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.resize(n+2,vector<int>(2,0));
        dp[0][1]=prices[0];
        for(int i =n-1;i>=0;--i){
            for(int buy =0;buy<2;++buy){
                 int profit = 0;
                if(buy){
                    profit = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    profit =max(prices[i]+dp[i+2][1],0+dp[i+1][0]);
                }
                dp[i][buy]=profit;
            }
        }
        return dp[0][1];
    }
};