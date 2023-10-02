//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
  const int MOD = 1000000007;
	int distinctSubsequences(string s)
	{
	    int n = s.length();
    
    // Initialize a vector to store the count of distinct subsequences
    vector<int> dp(n + 1, 0);
    
    // Initialize the base case
    dp[0] = 1;
    
    // Create an unordered_map to store the last index at which each character appeared
    unordered_map<char, int> last_seen;
    
    for(int i =1 ;i<=n; ++i){
        dp[i]= (2*dp[i-1])%MOD;
        if(last_seen.find(s[i-1])!=last_seen.end()){
            dp[i]=dp[i] - dp[last_seen[s[i-1]]-1];
        }
        last_seen[s[i-1]]=i;
        
        dp[i]=(dp[i]+MOD)%MOD;
    }
    
    
    
 
    return (dp[n]) % MOD;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends