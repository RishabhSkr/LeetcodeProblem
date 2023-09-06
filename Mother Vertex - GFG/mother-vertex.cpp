//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    void dfs(vector<int>adj[],vector<int>&vis,int i){
        vis[i]=true;
        for(auto it :adj[i]){
            if(!vis[it])
            dfs(adj,vis,it);
        }
        
    }
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int>vis(V,0);
	    int lastVisited=-1;
	    
	    for(int i= 0 ;i<V ; ++i){
	        if(!vis[i]){
	            dfs(adj,vis,i);
	            lastVisited = i;
	        }
	    }
	    
	    for(int i = 0;i<V;++i){
	        vis[i]=0;
	    }
	    
	    dfs(adj,vis,lastVisited);
	    for(int i  = 0;i<V; ++i){
	        if(!vis[i])return -1;
	    }
	    return lastVisited;
	    
	    
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends