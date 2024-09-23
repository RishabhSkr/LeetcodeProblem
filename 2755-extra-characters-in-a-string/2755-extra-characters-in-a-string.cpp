class Solution {
public:
    vector<int>dp;
    int n;
    int solve(string s,int i,vector<string>&dict){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans = 1+solve(s,i+1,dict);
        for(auto &w : dict){
            if(s.compare(i,w.size(),w)==0){
                ans = min(ans,solve(s,i+w.size(),dict));
            }
        }
        return dp[i]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size();
        dp.resize(n,-1);
        return solve(s,0,dictionary);
    }
};  