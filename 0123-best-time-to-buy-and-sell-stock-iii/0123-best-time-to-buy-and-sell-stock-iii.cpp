class Solution {
public:
int n;
vector<vector<vector<int>>>dp;
    int solve(int i,vector<int>&prices,int buy,int day){
        // base case 
        if(day==0)return 0;
        if(i>=n)return 0;
        if(dp[i][day][buy]!=-1)return dp[i][day][buy];
        long profit=0;
        if(buy){
            profit = max(-prices[i]+solve(i+1,prices,0,day),0+solve(i+1,prices,1,day));
        }
        else{
              profit = max(prices[i]+solve(i+1,prices,1,day-1),0+solve(i+1,prices,0,day));
        }
        return dp[i][day][buy]=profit;   
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
         // Initialize dp array: n days, up to 2 transactions, and 2 states (buy/sell)
        dp.resize(n, vector<vector<int>>(3, vector<int>(2, -1)));
        return solve(0,prices,1,2); // buy,day
    }
};