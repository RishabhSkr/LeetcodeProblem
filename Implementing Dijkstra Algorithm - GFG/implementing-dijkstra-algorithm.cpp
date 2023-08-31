//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
// int getMinVertex(vector<int>& dist, vector<int>& vis, int V) {
//         int minVertex = -1;
//         for (int i = 0; i < V; ++i) {
//             if (!vis[i] && (minVertex == -1 || dist[i] < dist[minVertex])) {
//                 minVertex = i;
//             }
//         }
//     return minVertex;
// }

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        // Define your custom comparison logic here
        // For example, to create a min-heap based on the second element of the pairs.
        return a.first < b.first;
    }
};
vector<int> help( vector<vector<int>>adj[], int src, int V) {
   
    vector<int> vis(V, 0);
    vector<int> dist(V, INT_MAX);
    
    priority_queue<int,vector<pair<int,int>>,Compare>que;
    vis[src]=1;
    dist[src] = 0;
    que.push({dist[src],src});

    while(!que.empty()){
        int dis = que.top().first;
        int node = que.top().second;
        que.pop();
        for (const auto& neighbor : adj[node]) {
            int j = neighbor[0];
            int weight = neighbor[1];

            if (!vis[j] && dist[node] != INT_MAX &&
                dist[j] > dist[node] + weight) {
                dist[j] = dist[node] + weight;
                que.push({dist[j],j});
            }
        }
    }
    // for (int i = 0; i < V; ++i) {
    //     int minVertex = getMinVertex(dist, vis, V);
    //     vis[minVertex] = 1;

    // }
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