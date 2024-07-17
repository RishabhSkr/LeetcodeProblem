class Solution {
public:
    int dp[1001][1001];
    int solve(int i ,int j ,string &s,string &t){
        if(j<0)return 1;
        if(i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int take =0,notTake = 0;
        if(s[i]==t[j]){
            take = solve(i-1,j-1,s,t)+solve(i-1,j,s,t);
        }else{
            notTake = solve(i-1,j,s,t);
        }   
        return dp[i][j]=take+notTake;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
            memset(dp,-1,sizeof(dp));
            return solve(n-1,m-1,s,t);
    }
};