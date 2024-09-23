class Solution {
public:
vector<int>dp;
int help(const string &s1,vector<string>&dict,int i){
    if(i==s1.size())return 0;
    int ans = 1+help(s1,dict,i+1);
    if(dp[i]!=-1)return dp[i];
    for(auto &w : dict){
        if(s1.compare(i,w.size(),w)==0){
            ans = min(ans,help(s1,dict,i+w.size()));
        }
    }
    return dp[i]=ans;
}
    int minExtraChar(string s, vector<string>& dictionary) {
        dp.assign(51,-1);
     return help(s,dictionary,0);   
    }
};