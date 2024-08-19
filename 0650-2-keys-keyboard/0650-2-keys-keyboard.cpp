class Solution {
public:
vector<vector<int>>dp;
int solve(int len,int last,int n){
    if(len>n)return 1e9;
    if(len==n)return 0;
     if( dp[len][last]!=-1)dp[len][last];
    // explore 
        int copy = 2+solve(2*len,len,n);

       int paste =  1+solve(len+last,last,n);
    
    return dp[len][last]=min(copy,paste);
}
    int minSteps(int n) {
        if(n==1)return 0;
        dp.resize(n+1,vector<int>(n+1,-1));
        return 1+solve(1,1,n);
    }
};