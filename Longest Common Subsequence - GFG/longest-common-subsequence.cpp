//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
int lcs(int n, int m, string s1, string s2)
    {
        // your code here
            vector<vector<int>> dp(n, vector<int>(m, 0));
     for (int i = 0; i <m; ++i) {
        if (s1[0] == s2[i])
            {
            dp[0][i] = 1;
            }
        else if(i>0)
        dp[0][i]=dp[0][i-1];
    }
    // Initialize base cases for the first row
    for (int i = 0; i <n; ++i) {
        if (s1[i] == s2[0]){
            dp[i][0]=1;
        }
        else if(i>0)
        dp[i][0]=dp[i-1][0];
    }

    // Initialize base cases for the first column
   

   
    for (int i = 1; i <n; i++) {
        
        for (int j = 1; j <m; ++j) {
            if (s1[i] == s2[j]) // check previous char is matched or not if then increment it by 1.
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else 
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
   
    return dp[n-1][m-1];
    }

};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends