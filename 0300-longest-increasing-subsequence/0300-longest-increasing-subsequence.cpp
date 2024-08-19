class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int ind,int prev){
        if(ind>=n)return 0;

        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int take =0,notTake = 0;

        notTake = solve(nums,ind+1,prev);
        if(prev == -1 || nums[prev]<nums[ind]){
            take = 1+solve(nums,ind+1,ind);
        }

        return dp[ind][prev+1   ]= max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
         n = nums.size();
        int ans = INT_MIN;
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(nums,0,-1);
    }
};