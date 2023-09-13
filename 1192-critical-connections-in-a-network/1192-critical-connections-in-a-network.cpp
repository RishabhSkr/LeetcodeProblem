class Solution {
    private:
    int timer=1;
    void dfs(int node ,int parent,vector<int>adj[],vector<int>&vis,vector<int>&low,vector<int>&tin,vector<vector<int>>&bridges){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it: adj[node]){
            if(parent==it)continue;
            if(vis[it]==0){
                dfs(it,node,adj,vis,low,tin,bridges);
                low[node] = min(low[node],low[it]);
                
                if(low[it]>tin[node]){
                    bridges.push_back({node,it});
                }
                
            }
            else{
                    low[node]=min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       vector<int>adj[n];
       for(auto it : connections){
           adj[it[0]].push_back(it[1]);
           adj[it[1]].push_back(it[0]);
       } 
       vector<int>vis(n,0),low(n,0),tin(n,0);
      vector<vector<int>>bridges;
      dfs(0,-1,adj,vis,low,tin,bridges);
      return bridges;
    }
};