//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int>mp;
     int i =0,j =0,maxi =-1;
        while(j<s.size()){
             mp[s[j]]++;
             
             while(i<j && mp.size()>k){
                 mp[s[i]]--;
                 if(mp[s[i]]==0) mp.erase(s[i]);
                 i++;
             }
             
             if(mp.size()==k)maxi = max(maxi,j-i+1);
             
             j++;
         } 
        return (maxi==-1)? -1:maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends