class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int maxLen = 1;
        int idx =0;
        // single len
        for(int i =0;i<n;++i)dp[i][i]=1;

        // len 2 
        for(int i =0;i+1<n;++i){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                maxLen = 2;
                idx =i;
            }
        }
        // for len >=3
        for(int len = 3 ;len<=n;++len){
            for(int i =0;i<n-len+1;++i){
                int j = i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    if (len > maxLen) {
                        maxLen = len;
                        idx = i;
                    }
                }   
            }
        }
        return s.substr(idx,maxLen);
    }
};