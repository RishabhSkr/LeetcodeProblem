//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
   bool dfs(int node, vector<int>adj[], vector<int>& vis, vector<int>& visPath) {
  vis[node] = 1;
  visPath[node] = 1;

  for (int neighbor : adj[node]) {
    if (!vis[neighbor]) {
      if (dfs(neighbor, adj, vis, visPath)) {
        return true;
      }
    } else if (visPath[neighbor]) {
      return true;
    }
  }

  visPath[node] = 0;
  return false;
}

bool isCyclic(int V, vector<int>graph[]) {
  vector<int> vis(V, 0);
  vector<int> visPath(V, 0);

  for (int i = 0; i < V; ++i) {
    if (!vis[i]) {
      if (dfs(i, graph, vis, visPath)) {
        return true;
      }
    }
  }

  return false;
}

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends