class Solution {
public:
#define int long long
int mod = 1e9+7;
vector<vector<int>>dp;
    int solve(int ind,int stage,int &n,int &x,int &y){
        if(ind==n )return stage<=x;
        if(stage>x)return 0;

        if(dp[ind][stage]!=-1)return dp[ind][stage];
        int newStage = 1LL*(x-stage)*y*solve(ind+1,stage+1,n,x,y)%mod;
        int oldStage = 1LL*(stage)*solve(ind+1,stage,n,x,y)%mod;

        return dp[ind][stage]=(oldStage%mod + newStage%mod)%mod;
    }
    int numberOfWays(int n, int x, int y) {
        dp.resize(n+1,vector<int>(x+1,-1));
        return solve(0,0,n,x,y);
    }
#undef int
};