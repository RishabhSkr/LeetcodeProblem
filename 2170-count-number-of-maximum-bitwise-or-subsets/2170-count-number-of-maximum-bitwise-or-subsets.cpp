class Solution {
public:
        // generate subset meanwhile calculate the or check with maxXor val
        // if it is equal then we have found the or subset cnt++;
    int n;
    vector<vector<int>>dp; // memoize
    int solve(int i,vector<int>&nums,int orVal,int &maxOR){
        if(i==n){
            return (orVal==maxOR)? 1: 0;
        }
        if(dp[i][orVal]!=-1)return dp[i][orVal];
        // include it 
        int take = solve(i+1,nums,orVal|nums[i],maxOR);
        // not  include it
        int notTake = solve(i+1,nums,orVal,maxOR);
        return dp[i][orVal]=take+notTake;
        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        n=nums.size();
        int k = 0;
        for(auto x : nums)k|=x;
        dp.resize(n+1,vector<int>(k+1,-1));
        return solve(0,nums,0,k);
        // 2nd approach DP+bitmask
    }
};