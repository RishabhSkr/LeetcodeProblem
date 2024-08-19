class Solution {
public:
    vector<vector<vector<int>>>dp;
    int n ;
    // int solve(int i,int day,int buy,vector<int>&prices){
    //     if(day==0)return 0;
    //     if(i>=n)return 0;
    //     if(dp[i][day][buy]!=-1)return dp[i][day][buy];
    //     //buy
    //     int profit = 0;
    //     if(buy){
    //         profit = max(-prices[i]+solve(i+1,day,0,prices),solve(i+1,day,1,prices));
    //     }
    //     else{
    //         profit =max(prices[i]+solve(i+1,day-1,1,prices),solve(i+1,day,0,prices));
    //     }
    //     return dp[i][day][buy]=profit;
    // }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        dp.resize(n+1,vector<vector<int>>(k+1,vector<int>(2,0)));
    
        for(int i =n-1;i>=0;--i){
            for(int day=1;day<=k;++day){
                for(int buy =0;buy<2;++buy){
                    int profit = 0;
                    if(day==0)dp[i][0][buy]=0;
                    else if(buy){
                        profit = max(-prices[i]+dp[i+1][day][0],dp[i+1][day][1]);
                    }
                    else{
                        profit =max(prices[i]+dp[i+1][day-1][1],dp[i+1][day][0]);
                    }
                    dp[i][day][buy]=profit;
                }
            }
        }

        return dp[0][k][1];
    }
};