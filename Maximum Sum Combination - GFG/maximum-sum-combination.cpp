//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        vector<int>ans;
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>st;
        int sum = A[N-1]+B[N-1];
        pq.push({sum,{N-1,N-1}});
        st.insert({N-1,N-1});
        while(!pq.empty() && K--){
            auto it = pq.top();
            int  maxSum = it.first;
            int x = it.second.first;
            int y = it.second.second;
            ans.push_back(maxSum);
            pq.pop();
            
            if(st.find({x-1,y})==st.end()){
                pq.push({A[x-1]+B[y],{x-1,y}});
                st.insert({x-1,y});
            }
            if(st.find({x,y-1})==st.end()){
                pq.push({A[x]+B[y-1],{x,y-1}});
                st.insert({x,y-1});
                
            }
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends