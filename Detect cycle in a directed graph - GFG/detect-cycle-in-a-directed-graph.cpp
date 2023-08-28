//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here:  Kahn Algorithm
	   
	    // step 1: calulate indegree of nodes
	    int indegree[V]={0};
	    
	    for(int u = 0 ;u<V ; ++u){
	        for(auto v : adj[u]){
	            
	                indegree[v]++;
	            
	        }
	    }
	    
	   // step 2: push indegree == 0 in queue 
	    queue<int>q;
	    for(int i = 0 ;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	   // step 3: pop out all the element who is hae indegree ==0 one by one 
	   // and make them indepenedent by removing edges and repeate step2;
	   int cnt =0;
	   while(!q.empty()){
	               
	       int node = q.front();
	       q.pop();
	       cnt++;
	        for(auto it : adj[node]){
	           indegree[it]--;
	           if(indegree[it]==0)q.push(it);
	        }
	                
	   }
	    if(cnt<V)return true;
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