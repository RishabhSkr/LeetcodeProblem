class Solution {
public:
vector<vector<int>>dp;
    int solve(int i,vector<int>&arr,int sum){
        if(i==0){
            if(sum%arr[0]==0)return sum/arr[0];
            return 1e9;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        int notTake = solve(i-1,arr,sum);
        int take =1e9;
        if(arr[i]<=sum){
            take = 1+solve(i,arr,sum-arr[i]);
        }
        return dp[i][sum]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        int ans =solve(n-1,coins,amount);
        if(ans>=1e9)return -1;
        return ans;
    }
};