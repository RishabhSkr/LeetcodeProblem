//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	
	int help(int *arr,int i ,int n,int sum,vector<vector<int>>&dp){
	    
	    if(i==n){
	        if(sum == 0)return 1;
	        return 0;
	    }
	  
	   if(sum<0)return 0;
	   
	    if(dp[i][sum]!=-1)return dp[i][sum];
	    
	    int ans =0;
	    
	    ans = help(arr,i+1,n,sum-arr[i],dp) + help(arr,i+1,n,sum,dp);
	    
	    return dp[i][sum]=ans%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
      vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return help(arr,0,n,sum,dp)%mod;
        
        
	}
};
// 10 31
// 9 7 0 3 9 8 6 5 7 6

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends