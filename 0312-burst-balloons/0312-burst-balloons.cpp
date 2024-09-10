class Solution {
public:
vector<vector<int>>dp;
int solve(int i,int j,vector<int>&arr){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int maxi =0;
    for(int  k = i;k<=j;++k){
        int cost = arr[i-1]*arr[k]*arr[j+1]+solve(i,k-1,arr)+solve(k+1,j,arr); // try to think in opp dirn 
        maxi = max(maxi,cost);
    }
    return dp[i][j]=maxi;
}
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n+2,1);
        for(int i =0;i<n;++i){
            arr[i+1]=nums[i];
        }
        dp.resize(arr.size(),vector<int>(arr.size(),-1));
       return solve(1,arr.size()-2,arr);
    }
};