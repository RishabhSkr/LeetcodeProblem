class Solution {
public:
    int minInsertions(string s) {
        // n-len(l c palindromic subseq).
        int n=s.size();
        string s1=s;
        reverse(s1.begin(), s1.end());
        
        vector<vector<int>>dp(n+1,vector<int>(n+1, 0));
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (s1[i]==s[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                }else{
                    dp[i+1][j+1]= max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        int palin=dp[n][n];
        int ans=n-palin;
        return ans;
    }
};