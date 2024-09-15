class Solution {
public:
    #define ll long long
    vector<vector<ll>>dp;
    ll solve(int i,int j,vector<int>&a,vector<int>&b){
        if(i>=a.size())return 0;
        if(j>=b.size())return LLONG_MIN/2;
        if(dp[i][j]!=LLONG_MIN/2)return dp[i][j];
        ll take = (1LL)*a[i]*(1LL)*b[j]+solve(i+1,j+1,a,b);
        ll notTake=solve(i,j+1,a,b);
        return dp[i][j]=max(take,notTake);
    }

    long long maxScore(vector<int>& a, vector<int>& b) {
        // long long dp0 = LLONG_MIN / 2, dp1 = LLONG_MIN / 2, dp2 = LLONG_MIN / 2, dp3 = LLONG_MIN / 2;

        // for (int x : b) {
        //     dp3 = max(dp3, dp2 + (1LL) * a[3] * x);
        //     dp2 = max(dp2, dp1 + (1LL) * a[2] * x);
        //     dp1 = max(dp1, dp0 + (1LL) * a[1] * x);
        //     dp0 = max(dp0, (1LL) * a[0] * x);
        // }
        dp.resize(a.size()+1,vector<ll>(b.size()+1,LLONG_MIN/2));
        return solve(0,0,a,b);
    }
};