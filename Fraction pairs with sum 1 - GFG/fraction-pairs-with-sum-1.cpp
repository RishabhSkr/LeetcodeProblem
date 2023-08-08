//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
   int countFractions(int n, int num[], int den[]) {
    unordered_map<double, int> mp;

    for (int i = 0; i < n; ++i) {
        
        double val = 1.0 * num[i] / den[i];
        mp[val]++;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int val = den[i] - num[i];
        double ans = 1.0 * val / den[i];
            mp[1.0*num[i]/den[i]]--; 
        if (mp.find(ans) != mp.end()) cnt += mp[ans];
    }
    return cnt;
}

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends