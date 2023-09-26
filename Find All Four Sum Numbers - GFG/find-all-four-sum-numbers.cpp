//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
   vector<vector<int>> fourSum(vector<int>& arr, int target) {
      int n = arr.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(arr.begin(), arr.end());

      for (int i = 0; i <n; ++i) {
        for (int j = i + 1; j<n; ++j) {
          int p1 = j + 1, p2 = n - 1;
          while (p1 < p2) {
            if (arr[p1] + arr[p2] + arr[i] + arr[j] == target) {
                vector<int>quad = {arr[i],arr[j],arr[p1],arr[p2]};
                        st.insert(quad);
                        p1++; p2--;
           
            } else if (arr[p1] + arr[p2] + arr[i] + arr[j] < target) {
              ++p1;
            } else {
              --p2;
            }
          }
        }
      }

    for(auto x:st)
        ans.push_back(x);
        
        return ans;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends