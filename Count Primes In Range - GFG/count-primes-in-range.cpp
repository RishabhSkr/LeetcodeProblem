//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPrimes(int L, int R) {
        // code here
    int n=R;
    vector<bool>isPrime(R+10,1);
        isPrime[0]=false,isPrime[1]=false;
        
        for(int i = 2;i*i<=n;++i){
            if(isPrime[i]==true){
                for(int j =i*i;j<=n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        
        int count =0;
        for(int i = L ; i<=R;++i){
            if(isPrime[i]==true)count++;
        }
        return count;
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        int ans = ob.countPrimes(L, R);
        cout << ans << "\n";
    }
}
// } Driver Code Ends