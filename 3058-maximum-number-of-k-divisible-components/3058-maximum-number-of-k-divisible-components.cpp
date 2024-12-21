class Solution {
public:
    long long dfs(int node,int parent, vector<vector<int>>&adj,vector<int>&values,int k,int &ans){
        long long sum = values[node];

        // node add krte jaao root leaf tk
        for(auto child : adj[node]){
            if(child!=parent)
                sum+=dfs(child,node,adj,values,k,ans);
        }
        if(sum%k==0){
            ans++;
            return 0; // parent ko 0 return  kyunki ye alg ho gya
        }

        return sum;
        
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
         vector<vector<int>> adj(n);
        for(auto edge : edges){
            int u  = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans =0;
        dfs(0,-1,adj,values,k,ans);
        
        return ans;
    }
};