//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    // vector<int> dp;

    // int maxMoney(int *arr, int i, int n) {
    // if (i >=n) return 0;  // Change the condition to i > n
    // if (dp[i] != -1) return dp[i];
    // return dp[i] = max(maxMoney(arr, i + 2, n)+arr[i], maxMoney(arr, i + 1, n));
    // }

    
//   vector<int>dp(100001,-1);
int FindMaxSum(int arr[],int n){
   vector<int>dp(n+2,0);
        for(int i=2;i<n+2;i++){
            dp[i]=max(dp[i-1],arr[i-2]+dp[i-2]);
        }
        return dp[n+1];
}


};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends