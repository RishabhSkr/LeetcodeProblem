//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
//   bool detectbfs(int src,int V,vector<int>adj[],vector<int>&vis){
//       vis[src]=1;
//       queue<pair<int,int>>q;
//       q.push({src,-1});
//       while(!q.empty()){
//           int node = q.front().first;
//           int parent = q.front().second;
//           q.pop();
//           for(auto adjNode : adj[node]){
//               if(!vis[adjNode]){
//                   q.push({adjNode,node});
//                   vis[adjNode]=1;
//               }else if(adjNode!=parent)return true;
//           }
          
//       }
//       return false;
//   }
  
   bool detectdfs(int src,int parent,int V,vector<int>adj[],vector<int>&vis){
      vis[src]=1;
          for(auto adjNode : adj[src]){
              if(!vis[adjNode]){
                  if(detectdfs(adjNode,src,V,adj,vis))return true;
              }else if(adjNode!=parent)return true;
          }
          
      return false;
  }
  
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        for(int i = 0 ;i<V; ++i){
            if(!vis[i]){
                if(detectdfs(i,-1,V,adj,vis))return true;
            }
            
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends