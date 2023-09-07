//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
 const int mod = (int)1e9 + 7;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<long long> dist(n, LLONG_MAX); // Use long long for dist
    vector<int> ways(n, 0);

    vector<pair<int, int>> adj[n];
    for (auto it : roads) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    dist[0] = 0;
    ways[0] = 1;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto iter = pq.top();
        long long cost = iter.first; // Use long long for cost
        int node = iter.second;
        pq.pop();

        for (auto it : adj[node]) {
            int v = it.first;
            int wt = it.second;

            if ((cost + wt)< dist[v]) {
                dist[v] = (cost + wt);
                pq.push({dist[v], v}); // Push the updated distance
                ways[v] = ways[node];
            } else if (cost + wt == dist[v]) {
                ways[v] = (ways[v] + ways[node]) % mod;
            }
        }
    }
    return ways[n - 1] % mod;
}
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends