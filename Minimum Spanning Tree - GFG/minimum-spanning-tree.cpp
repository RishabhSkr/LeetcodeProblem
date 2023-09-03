//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
// void printMST(int V, vector<int> parent, vector<vector<int>> adj[]) {
//     cout << "Edges in Minimum Spanning Tree:" << endl;
//     for (int i = 1; i < V; i++) {
//         if (parent[i] != -1 && parent[i] < V && i < V && parent[i] >= 0 && i >= 0) {
//             cout << "Edge: " << parent[i] << " - " << i << " (Weight: " << adj[i][parent[i]][1] << ")" << endl;
//         }
//     }
    
// }
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> parent(V, INT_MAX);
    vector<int> dist(V, INT_MAX);
    vector<int> vis(V, -1);

    // wt, {node, parent}
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int, int>>>,
    greater<pair<int,pair<int, int>>>> pq;
    dist[0] = 0;
    parent[0] = -1;
    pq.push({0, {0, -1}});

    int sum = 0;
    while (!pq.empty()) {
        auto current = pq.top();

        int wt = current.first;
        int node = current.second.first;
        int pare = current.second.second;
        pq.pop();
        if (vis[node] == 1) continue;
		// add it to the mst
		vis[node] = 1;
		sum += wt;
        for (auto neighbor : adj[node]) {
            int v = neighbor[0];   // Corrected indexing
            int cost = neighbor[1]; // Corrected indexing

            if (vis[v] == -1) {
                dist[v]=cost;
                parent[v] = pare;
                pq.push({dist[v], {v, pare}});
            }
        }
    }
    return sum;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends