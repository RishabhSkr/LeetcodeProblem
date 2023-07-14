//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int mod = 1e9+7;
int fun2withDp(int n,vector<int>&dp){
    if(n==1)return 1;
    if(n==2)return 2;
    int x=INT_MAX,y=INT_MAX;
    if(dp[n]!=-1)return dp[n]%mod;
    x = fun2withDp(n-1,dp);
    y = fun2withDp(n-2,dp);
    dp[n]=(x+y)%mod;
  return dp[n]%mod;
}
    int countWays(int n)
    {
        // your code here
            vector<int>dp(n+1,-1);
          return fun2withDp(n,dp);
    }
};




//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends