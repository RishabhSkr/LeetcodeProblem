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
    // long long help(int n ){
    //     if(n==0)return 1;
    //     if(n<0)return 0;
    //     long long ans =0;
    //     if(dp[n]!=-1)return dp[n];
       
    //     ans = help(n-1)%mod+help(n-2)%mod+help(n-3)%mod;
    //     return dp[n]=ans%mod;
        
    // }
    long long countWays(int n)
    {
        dp.resize(n+1,0);
        dp[0]=1;
         long long op1 = 0,op2 = 0,op3 =0;
         
         for(int i  = 1 ;i<=n;++i){
            if(i-1>=0){
            op1 = dp[i-1];
            }
            if(i-2>=0){
                op2 = dp[i-2];
            }
            
            if(i-3>=0){
                    op3 = dp[i-3];
            }
            dp[i]=(op1 + op2 + op3)%mod;
         }
       return dp[n]%mod;
        
        
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