//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    vector<long long>dp;
    int mod = 1e9+7;
    long long help(int n ){
        if(n==0)return 1;
        if(n<0)return 0;
        long long ans =0;
        if(dp[n]!=-1)return dp[n];
        ans = help(n-1)%mod+help(n-2)%mod+help(n-3)%mod;
        return dp[n]=ans%mod;
        
    }
    long long countWays(int n)
    {
        
        // your code here
        dp.resize(n+1,-1);
        dp[0]=1;
        return  help(n);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends