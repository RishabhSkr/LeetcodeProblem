//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
        long long int ans = 0;
        for(int i =  0 ;i<32;++i){
           long long  cnt0 = 0,cnt1 = 0;
            for(int j =0 ;j<n;++j){
                if(arr[j]%2==0)cnt0++;
                else cnt1++;
                arr[j]/=2;
            }
            ans += (cnt0*cnt1)*pow(2,i);
        }
        return ans;
    	
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends