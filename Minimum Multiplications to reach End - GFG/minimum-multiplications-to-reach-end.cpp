//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int mod = 1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        queue<pair<int,int>>q;
        vector<int>ans(1e5,-1);
        q.push({0,start});
        ans[start]=0;
        while(!q.empty()){
            int step= q.front().first;
            int no = q.front().second;
            q.pop();
            if(no == end)return step;
            for(int i = 0 ;i<n; ++i){
                
                    int multi = no*arr[i]%mod;
                    if(ans[multi]==-1){
                        ans[multi]=step;
                        q.push({step+1,multi});
                    }
                    
                    
                
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends