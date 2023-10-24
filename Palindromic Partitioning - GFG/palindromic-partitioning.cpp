//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isPalindrome(int s, int e, string str) {
    while (s <= e) {
        if (str[s++] != str[e--]) return false;
    }
    return true;
}

int palindromicPartition(string str) {
    int n = str.size();
    vector<int> dp(n, INT_MAX);
    for (int i = 0; i < n; ++i) {
        if (isPalindrome(0, i, str)) {
            dp[i] = 0;
            continue;
        }
        for (int j = 0; j < i; ++j) {
            if (isPalindrome(j + 1, i, str)) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n - 1];
}

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends