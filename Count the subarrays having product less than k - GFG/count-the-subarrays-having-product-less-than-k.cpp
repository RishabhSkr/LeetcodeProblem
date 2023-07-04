//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
  //Approach 1 T.C : O(n^2)
//   Approach 2: O(n) O(1)
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
           
            int res=0;
        // for(int i = 0 ; i<n; ++i){
        //     long p=1;
        //     for(int j=i ; j<n;++j){
        //         p=p*a[j];
        //         if(p<k){
        //             res++;
        //         }
        //         else break;
        //     }
        // }
        int  i=0,j=0;
        long p =1;
        while(j<n){
            p*=a[j];
            
            while(i<=j && p>=k){
                p/=a[i];
                ++i;
            }
            if(p<k)
                res+=j-i+1;
            j++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends