class Solution {
public:
int n;
    bool solve(int i ,vector<int>&nums,int sum, vector<vector<int>>&dp){
        if(sum==0)return true;
        if(i==0){
            return (sum==nums[0]);
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool take = false;
        if(nums[i]<=sum) take=solve(i-1,nums,sum-nums[i],dp);
        bool notTake = solve(i-1,nums,sum,dp);
        return dp[i][sum]= take|notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0,n = nums.size();
        for(auto x : nums){
            sum+=x;
        }
        if(sum%2==1)return false;
           
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        return solve(n-1,nums,sum/2,dp);
    }
};