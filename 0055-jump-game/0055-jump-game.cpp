class Solution {
public:
int dp[10001];
bool solve(int ind,int n,vector<int>&nums){
    if(ind==n-1)return true;
    if(nums[ind]==0)return false;
    if(dp[ind]!=-1)return dp[ind];
    int reach = ind+nums[ind];
    for(int steps = ind+1;steps<=reach;++steps){
        if(steps<n && solve(steps,n,nums))return dp[ind]=true;
    }
    return dp[ind]=false;
}
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums.size(),nums);
    }
};