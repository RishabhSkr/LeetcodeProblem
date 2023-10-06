//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int substrCount (string s, int k) {
        return countAtmostK(s,k)-countAtmostK(s,k-1);
        // return countSubs(s,k);
    }
    
    // brute force approach
    int countSubs(string s,int k){
        int res = 0;
    int n = s.length();
    
    for (int i = 0; i < n; ++i) {
        int dist_cnt = 0;
        int charSet[26] = {0}; // Initialize the character set array
        
        for (int j = i; j < n; ++j) {
            if (charSet[s[j] - 'a'] == 0) {
                dist_cnt++;
            }
            charSet[s[j] - 'a']++;
            
            if (dist_cnt == k) {
                res++;
            }
           
        }
    }
    return res;
    }
    
    int countAtmostK(string s, int k){
        int i = 0;
        int j = 0;
        int n = s.length();
        int charFreq[26] = {0};
        int dist_cnt = 0;
        int res = 0;
        while(j<n){
            int curr = s[j]-'a';
            charFreq[curr]++;
            if(charFreq[curr]==1)dist_cnt++;
            
            while(dist_cnt>k){
                 int prev = s[i] - 'a';
                charFreq[prev]--;
                if (charFreq[prev] == 0) {
                    dist_cnt--;
                }
                i++;
            }
            
            res+=j-i+1;
            j++;
        }
        
        return res;
    }
    
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends