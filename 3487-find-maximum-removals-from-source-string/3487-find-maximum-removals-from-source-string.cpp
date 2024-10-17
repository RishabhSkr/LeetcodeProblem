class Solution {
public:
    vector<int>mark;
    int n;
    vector<vector<int>>dp;
    int solve(int i ,int j ,string &pat,string &source){
        if(j==pat.size())return 0;
        if(i==source.size())return 1e3;
        if(dp[i][j]!=-1)return dp[i][j];
        int take= 1e3;
        // take 
        if(source[i]==pat[j])take=mark[i]+solve(i+1,j+1,pat,source);
        // not take
        int notTake= solve(i+1,j,pat,source);
        return dp[i][j]=min(take,notTake); 

    }
    int maxRemovals(string source, string pattern, vector<int>& tar) {
        n= source.size();
        mark.resize(n,0);
        dp.resize(n,vector<int>(n,-1));
        for(auto ind : tar){
            mark[ind]=1;
        }
        return tar.size()-solve(0,0,pattern,source);
    }  
};