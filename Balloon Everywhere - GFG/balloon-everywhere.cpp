//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string str){
        int A=0,B=0,L=0,O=0,N=0;
        for(auto s : str){
            if(s=='a')A++;
            if(s=='b')B++;
            if(s=='l')L++;
            if(s=='o')O++;
            if(s=='n')N++;
        }
        
        int cnt2 = min(L/2,O/2),cnt1 = min(A,min(B,N));
        return min(cnt1,cnt2);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends