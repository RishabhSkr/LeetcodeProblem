//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    // vector<vector<int>>dp;
    // int solve(int m ,int n){
    //     if(m==1 || n==1)return 1;
    //     if(dp[m][n]!=-1)return dp[m][n];
    //     return dp[m][n]=(solve(m-1,n)+solve(m,n-1)) % (int)(1e9+7);
    // }
    int mod = 1000000007;
    
    long long inverse(long long a,long long p){
        long long res=1;
        while(p!=0){
            if(p&1)res = res *a%mod;
            p/=2;
            a =(a*a)%mod;
        }
        return  res%mod;
        
    }
    long long  numberOfPaths(int M, int N)
    {
        // dp.resize(M+1,vector<int>(N+1,-1));
    //   return solve(M,N);
        int n  = N+M-2;
        int r = M-1;
        long long res=1;
        for(int i = 1;i<=r;++i){
            res=(res*(n-r+i)%mod)*(inverse(i,mod-2))%mod;
        }
        return res;
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends