class Solution {
public:
int n;
    // bool solve(int i ,vector<int>&nums,int sum, vector<vector<int>>&dp){
    //     if(sum==0)return true;
    //     if(i==0){
    //         return (sum==nums[0]);
    //     }
    //     if(dp[i][sum]!=-1)return dp[i][sum];
    //     bool take = false;
    //     if(nums[i]<=sum) take=solve(i-1,nums,sum-nums[i],dp);
    //     bool notTake = solve(i-1,nums,sum,dp);
    //     return dp[i][sum]= take|notTake;
    // }
    bool canPartition(vector<int>& nums) {
        int total=0,n = nums.size();
        for(auto x : nums){
            total+=x;
        }
        if(total%2==1)return false;
        int sum = total/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        // dp method 2
        // base case
        for(int i =0;i<n;++i){
            dp[i][0]=1;
        }
        dp[0][nums[0]];
        for(int i =1;i<n;++i){
            for(int tar = 1 ;tar<=sum;tar++){
                bool take = false;
                if(nums[i]<=tar) take|=dp[i-1][tar-nums[i]];
                bool notTake = dp[i-1][tar];
                dp[i][tar]= take|notTake;
            }
        }
        return dp[n-1][sum];
    }
};