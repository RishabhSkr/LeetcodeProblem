class Solution {
public:
    int n;
    vector<vector<vector<int>>>dp;
    int solve(int per,int i,int M,vector<int>&piles){
        if(i>=n)return 0;
        if( dp[per][i][M]!=-1)return  dp[per][i][M];
        int res = (per==1)?-1:INT_MAX;
        int stones =0;
        for(int x=1;x<=min(2*M,n-i);++x){
            stones +=piles[i+x-1];
            if(per ==1){
                res = max(res,stones+solve(0,i+x,max(M,x),piles));
            }else{
                res = min(res,solve(1,i+x,max(M,x),piles));
            }
        }
        return dp[per][i][M]=res;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp.resize(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return solve(1,0,1,piles);   
    }
};   