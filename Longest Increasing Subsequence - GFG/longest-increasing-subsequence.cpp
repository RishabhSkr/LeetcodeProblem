//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       vector<int> dp(n, 1);
       vector<int> ans;  // Temporary vector to store the current increasing subsequence
       for (int i = 0; i < n; ++i)
       {
           int s = 0, e = ans.size() - 1;
           while (s <= e)
           {
               int mid = s + (e - s) / 2;
               if (a[i] > ans[mid])
                   s = mid + 1;
               else
                   e = mid - 1;
           }
           if (s == ans.size())
               ans.push_back(a[i]);
           else
               ans[s] = a[i];
           dp[i] = s + 1;  // Length of the increasing subsequence ending at index i
       }
       int maxLen = 0;
       for (int i = 0; i < n; ++i){
           maxLen = max(maxLen, dp[i]);
       }
       return maxLen;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends