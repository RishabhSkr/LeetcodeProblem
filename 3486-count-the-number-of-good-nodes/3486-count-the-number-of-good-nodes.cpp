class Solution {
public:
int ans =0;
    int dfs(int u,int parent,vector<int>adj[]){
        int totalNodes =0;
        int subtreeSize = -1;
        bool isGood = true;

        for(auto nbr : adj[u]){
            if(nbr==parent)continue;
            int currSize = dfs(nbr,u,adj);
            if(subtreeSize == -1)subtreeSize = currSize;
            else if(currSize!=subtreeSize)isGood = false;
            totalNodes +=currSize;
        }
        if(isGood)ans++;
        return totalNodes+1;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int>adj[n];
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,adj);
        return ans;
    }
};