//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[1001][1001];
int solve(int w,int n,int * val,int * wt,int i){
    if(w<=0|| i>=n)return 0;
    
    if(dp[w][i]!=-1)return dp[w][i];
    int notTake = solve(w,n,val,wt,i+1);
    int take = 0;
    if(wt[i]<=w)take = val[i]+solve(w-wt[i],n,val,wt,i);
    int sameTake = 0;
    if(wt[i]<=w)sameTake = val[i]+solve(w-wt[i],n,val,wt,i);
    return dp[w][i]=max(take,max(sameTake,notTake));
}
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(W,N,val,wt,0);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends