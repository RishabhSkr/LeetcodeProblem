//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words){
        unordered_map<string,int>mp;
        sort(words.begin(),words.end()); //custom comparator can be used?
      
        for(auto &i : words)mp[i]++;
        
        
        string str;   int longest = 0;
        for(auto &s : words){
            
            
            string x;    
            int n = s.size();
            
            
            for(int j = 0; j < n; j++){
                
                x += s[j];
                if(!mp[x]){
                    n = 0;  break;
                }
            }
            if(n > longest){
                str = s;  longest = n;
            }
        }
        return str;
    }


};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends