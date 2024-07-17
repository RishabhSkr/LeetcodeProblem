class Solution {
public:
    int minDistance(string s1, string s2) {
        int n1 = s1.size(),n2= s2.size();
        if(n1==0)return n2;
        if(n2==0)return n1;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1, 0));
        // logic yeh LCS find kron ->add kro return word1-dp[n][m]+word2-dp[n][m]
        for (int i=0; i<n1; i++){
            for (int j=0; j<n2; j++){
                if (s1[i]==s2[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                }else{
                    dp[i+1][j+1]= max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return n1-dp[n1][n2]+n2-dp[n1][n2];
    }
};