class Solution {
public:
    int dp[2001][4001];
 int solve(int ind,int n,vector<int>&reward,int x){
    if(ind>=n)return 0;
    if(dp[ind][x]!=-1)return dp[ind][x];
    int take = 0;
    if(reward[ind]>x){
        take =reward[ind]+solve(ind+1,n,reward,x+reward[ind]);
    }
    int notTake = solve(ind+1,n,reward,x);
    return dp[ind][x]=max(take,notTake);
 }  
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        memset(dp,-1,sizeof(dp));
        sort(rewardValues.begin(),rewardValues.end());
        return solve(0,n,rewardValues,0);
    }
};