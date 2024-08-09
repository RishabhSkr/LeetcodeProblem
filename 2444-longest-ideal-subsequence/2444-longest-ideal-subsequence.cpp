class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int>dp(26,0);
        int res = INT_MIN;
        for(int i =0;i<n;++i){
            int ind = s[i]-'a';
            int left = max(ind-k,0);
            int right = min(ind+k,25);
            int longest = 0;
            for(int j =left; j<=right;++j){
                longest = max(dp[j],longest);
            }
            dp[ind]= max(dp[ind],longest+1);
            res = max(res,dp[ind]);
        }
        return res;
    }
};