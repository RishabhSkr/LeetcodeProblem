class Solution {
public:
vector<vector<int>>dp;

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n,vector<int>(amount+1,1e9));
      // understand the base case and your are good to go
        // method 2 : dp
        for(int i=0;i<=amount;++i){
            if(i%coins[0]==0)dp[0][i]=i/coins[0];
        }
        for(int i =1;i<n;++i){
            for(int amt =0;amt<=amount;amt++){
                int notTake = dp[i-1][amt];
                int take =1e9;
                if(coins[i]<=amt){
                    take = 1+dp[i][amt-coins[i]];
                }
                dp[i][amt]=min(take,notTake);   
            }
        }
        int ans = dp[n-1][amount];
        if(ans>=1e9)return -1;
        return ans;
    }
};