//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int mod = 1e9+7;
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        vector<long long int>dp(n+1,0);
        dp[0]=1,dp[1]=1;
        for(int i =2;i<=n;++i){
      
            for(int j =1;j<=i;j++){
                dp[i]=dp[i]%mod+(dp[j-1]*dp[i-j])%mod;
            }
           
        }
        return dp[n]%mod;
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends