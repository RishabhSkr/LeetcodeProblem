//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    	
// 	int help(int n,int i ,int *arr,int sum){
	    
// 	    if(i==n){
// 	        if(sum == 0)return 1;
// 	        return 0;
// 	    }
	  
	  
	   
// 	   // if(dp[i][sum]!=-1)return dp[i][sum];
	    
// 	    int ans =0;
	    
// 	    ans = help(n,i+1,arr,sum-arr[i]) || help(n,i+1,arr,sum);
	    
// 	    return ans;
// 	}
    
    int equalPartition(int N, int arr[])
    {
         int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += arr[i];
    }

    // If the total sum is odd, it's impossible to divide into two equal partitions.
    if (sum % 2 != 0) {
        return false;
    }

    int targetSum = sum / 2;
    
    vector<vector<bool>> dp(N + 1, vector<bool>(targetSum + 1, false));
    
    // Base case: If the target sum is 0, we can achieve it by not selecting any elements.
    for (int i = 0; i <= N; ++i) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= targetSum; ++j) {
            // If the current element (arr[i - 1]) is greater than the current sum (j),
            // we can't include it in the subset, so the result is the same as without it.
            if (arr[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // We have two options: include the current element or exclude it.
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[N][targetSum];
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends