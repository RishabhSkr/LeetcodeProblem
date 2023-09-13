//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        if(N>1 && S<1)return "-1";
         if (S < 0 || S > 9 * N) {
        return "-1"; // Invalid input, not possible to form such a number
    }

    string result;

    while (N--) {
        if (S >= 9) {
            result += '9'; //ADDING FROM LEFTMOST  LARGEST AND DECREASING THE  S BY 9 IF(S<9)ADD IT TO THE RES;
            S -= 9;
        } else {
            result += to_string(S);
            S = 0;
        }
    }

    return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends