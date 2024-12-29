class Solution {
public:
       
        const int mod = 1e9+7;
    // long long solve(int tarInd,int colIdx ,string target){
    //     if(tarInd==target.size())return 1;
    //     if(colIdx>=mp.size())return 0;
    //     if(dp[tarInd][colIdx]!=-1)return dp[tarInd][colIdx];
    //     long long take = 0;
    //     if(mp[colIdx][target[tarInd]-'a']>0)take = (1LL *(mp[colIdx][target[tarInd]-'a'])%mod*solve(tarInd+1,colIdx+1,target)%mod)%mod;
    //     long long notTake = solve(tarInd,colIdx+1,target);
    //     return dp[tarInd][colIdx]=(take+notTake)%mod;
    // }
    int numWays(vector<string>& words, string target) {
        // store the freq of each char at each index
        // use this freq to calulate the the number of ways by dp
        int n = words[0].size();
        int m = target.size();
        if(m > n) return 0;
        vector<vector<int>>mp(n,vector<int>(26,0));
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,0));

        for(auto word : words){
            for(int j =0;j<n;++j){
                mp[j][word[j]-'a']++;
            }
        }
        dp[0][0]=1;
        for(int j = 0;j<=n;++j){
            dp[0][j]=1;
        }
        //If at target char i, then m-i characters still remaining
        // So can't go beyond n-(m-i) = n-m+i
        for(int i = 1;i<=m;++i){
            for(int j =i;j<=n-(m-i);++j){
                 dp[i][j] = dp[i][j-1];
            long long cur = mp[j-1][target[i-1] - 'a'];
            if(cur > 0) {
                dp[i][j] = (dp[i][j] + (cur * dp[i-1][j-1]) % mod) % mod;
            }
            }
        }
        return dp[m][n];
    }
};