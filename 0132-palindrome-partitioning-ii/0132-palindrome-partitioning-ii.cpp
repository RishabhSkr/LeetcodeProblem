class Solution {
public:
bool isPallendrome(int i,int j,string &s){
    while(i<=j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}
vector<int>dp;
int solve(int i,string &s,int n){
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];
    int mini = INT_MAX;
    for(int j =i ;j<n;++j){
        if(isPallendrome(i,j,s)){
            int cost = 1+solve(j+1,s,n);
            mini = min(mini,cost);
        }
    }
    return dp[i]=mini;
}
    int minCut(string s) {
        int n = s.size();
        dp.resize(n+1,-1);
        return solve(0,s,n)-1; //last wala cut count nhi krenge
    }
};