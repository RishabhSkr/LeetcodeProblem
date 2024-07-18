class Solution {
public:
// T.C O(n*m) S.C(O(n*m))
// converted into 1 based indexing
    bool isMatch(string s, string p) {
        int n = s.size(),m = p.size();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,0));
        // return solve(m,n,p,s);
     // method 2 : dp
            dp[0][0]=true;
            for(int i =1;i<=m;++i){
                bool flag = true;
                for(int ii =1;ii<=i;++ii){
                    if(p[ii-1]!='*'){
                        flag = false;
                        break;
                    }
                }
                dp[i][0]=flag;
            }

            for(int j = 1;j<=n;++j){
                dp[0][j]=false;
            }

            for(int i =1;i<=m;++i){
                for(int j =1;j<=n;++j){
                    if(p[i-1]==s[j-1] || p[i-1]=='?'){
                        dp[i][j]= dp[i-1][j-1];
                    }
                    else if(p[i-1]=='*'){
                        // case 1: * as empty string || case 2: * as considered as whole sequence
                        dp[i][j]= dp[i-1][j] | dp[i][j-1];
                    }
                   else  dp[i][j]=false;
                }
            }
            return dp[m][n];
    }
};