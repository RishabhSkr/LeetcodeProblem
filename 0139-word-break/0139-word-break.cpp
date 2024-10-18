class Solution {
public:
vector<int>dp;
    bool canBrk(int start, string& s,set<string>&st) {
        int n = s.size();
        if(start == n) return 1;
        if(dp[start]!=-1)return dp[start];
        string sub;
        for(int i = start; i<n; i++) {
            if(st.count(sub+=s[i]) && canBrk(i+1,s,st)) 
                return dp[start]=1;
        }
        return dp[start]=0;
        // O(2^N)
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st(wordDict.begin(),wordDict.end());
        dp.resize(s.length()+1,-1);
         return canBrk(0,s,st);    
    }
};
    