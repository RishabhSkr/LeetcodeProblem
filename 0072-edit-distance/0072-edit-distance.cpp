class Solution {
public:
    int minDistance(string s1, string s2) {
        int n1 = s1.size(),n2= s2.size();
        if(n1==0)return n2;
        if(n2==0)return n1;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1, 0));

        for(int i=0;i<=n1;++i)dp[i][0]=i;  // len will be i<=n1
        for(int i =0;i<=n2;++i)dp[0][i]=i; // here len will be i<=n2
        for (int i=0; i<n1; i++){
            for (int j=0; j<n2; j++){
                if (s1[i]==s2[j]){
                    dp[i+1][j+1]=dp[i][j];
                }else{
                    dp[i+1][j+1]= 1+min(dp[i][j+1],min(dp[i+1][j],dp[i][j]));
                }
            }
        }
        return dp[n1][n2];
    }
};