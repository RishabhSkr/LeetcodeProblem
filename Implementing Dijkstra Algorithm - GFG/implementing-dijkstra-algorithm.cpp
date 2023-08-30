//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int getMinVertex(vector<int>& dist, vector<int>& vis, int V) {
    int minVertex = -1;
    for (int i = 0; i < V; ++i) {
        if (!vis[i] && (minVertex == -1 || dist[i] < dist[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}

vector<int> help( vector<vector<int>>adj[], int src, int V) {
    vector<int> vis(V, 0);
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < V; ++i) {
        int minVertex = getMinVertex(dist, vis, V);
        vis[minVertex] = 1;

        for (const auto& neighbor : adj[minVertex]) {
            int j = neighbor[0];
            int weight = neighbor[1];

            if (!vis[j] && dist[minVertex] != INT_MAX &&
                dist[j] > dist[minVertex] + weight) {
                dist[j] = dist[minVertex] + weight;
            }
        }
    }

    return dist;
}
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        return help(adj,S,V);
            
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends