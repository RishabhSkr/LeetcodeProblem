//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<vector<long long int>>dp;
  long long int help(int *coins,int sum,int n){
      if(n==0){
          if(sum%coins[0]==0)return 1;
          else return 0;
      }
      if(dp[sum][n]!=-1)return dp[sum][n];
      long long int notTake = help(coins,sum,n-1);
      long long int take = 0;
      if(coins[n]<=sum) take = help(coins,sum-coins[n],n);
      return dp[sum][n]=take+notTake;
  }
    long long int count(int coins[], int N, int sum) {
         dp.assign(sum + 1, vector<long long int>(N, -1));
        return help(coins,sum,N-1);
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends