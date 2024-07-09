class Solution {
public:
vector<vector<int>>dp;
int mod = 1e9+7;
int solve(int i,int sum,vector<int>&arr){
    if(i==0){
        if(sum==0 && arr[0]==0)return 2;
        if(sum==0 || sum==arr[0])return 1;
        return 0;
    }
    if(dp[i][sum]!=-1)return dp[i][sum];
    int notTake = solve(i-1,sum,arr);
    int take =0;
    if(sum>=arr[i])take = solve(i-1,sum-arr[i],arr);
    return dp[i][sum]=(take%mod+notTake%mod)%mod;
}
    int findTargetSumWays(vector<int>& nums, int d) {
         int n = nums.size();
        int sum = 0;
        for(auto x : nums) sum += x;
    
        // If (sum + d) is odd, it's not possible to partition
        if ((sum + d) % 2 != 0 || (sum + d)<0) return 0;
    
        int tar = (sum + d) / 2;
        dp.resize(n, vector<int>(tar + 1, -1));
        return solve(n-1,tar,nums);
    }
};