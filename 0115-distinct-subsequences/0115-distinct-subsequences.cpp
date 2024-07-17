class Solution {
public:

  
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
            double dp[n+1][m+1];
            memset(dp,0,sizeof(dp));
         
            // method 2 : dp top down
            for(int i = 0;i<=n;++i){
                dp[i][0]=1;
            }
            for(int i = 1;i<=m;++i){ // if from 0 it will rewrite the case of above which leads to wrong ans
                dp[0][i]=0;
            }
            for(int i =1;i<=n;++i){
                for(int j =1;j<=m;++j){
                    double take =0,notTake = 0;
                    if(s[i-1]==t[j-1]){
                        take = dp[i-1][j-1]+dp[i-1][j];
                    }else{
                        notTake = dp[i-1][j];
                    }   
                    dp[i][j]=take+notTake;
                }
            }
            return (int)dp[n][m];
    }
};