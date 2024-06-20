class Solution {
public:
// int solve(int n,vector<int>&nums){
//         if(n==0)return nums[0];
//         if(n<0)return 0;
//         int take = 0;
//         if(dp[n]!=-1)return dp[n];
//         take +=nums[n]+solve(n-2,nums);
//         int nottake = solve(n-1,nums);
//         return dp[n]=max(take,nottake);
// }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        if(n<2)return nums[0];
        memset(dp,0,sizeof(dp));
        // return solve(n-1,nums);
        // method 2 : 
        dp[0]=nums[0];
        for(int i =1;i<n;++i){
           int notTake = 0+dp[i-1];
           int take =0;
           if(i>1)
            take = nums[i]+dp[i-2];
            else take=nums[i]; // if neg ind <0 then store neg ind val =0 like in the base 
           dp[i]= max(take,notTake);
        }
        return dp[n-1];
    }
};