//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int MinSquares(int n)
	{
	    vector<int> dp(n+1,n);
	    dp[0]=0;
	    if(dp[n]!=n)return dp[n];
	    
	    for(int i =1;i<=n; ++i){
	        for(int j =1;i-(j*j)>=0;++j){
	           
	            dp[i]=min(dp[i],1+dp[i-j*j]);
	        }
	    }
	    return dp[n];
	    
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends