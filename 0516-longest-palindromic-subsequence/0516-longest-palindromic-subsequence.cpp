class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t="";
        for(auto x:s)t.push_back(x);
        reverse(t.begin(),t.end());
        int n1 = s.size(),n2 = t.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i =0;i<n1;++i){
            for(int j = 0;j<n2;++j){
                if(s[i]==t[j]){
                    dp[i+1][j+1]= 1+dp[i][j];
                }
                else{
                    dp[i+1][j+1]= max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[n1][n2];
    }
};