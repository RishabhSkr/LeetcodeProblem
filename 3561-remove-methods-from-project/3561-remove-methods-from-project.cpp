class Solution {
public:

    void dfs(vector<int>&vis,int node,vector<int>adj[]){
        vis[node]=1;
        for(auto &it : adj[node]){
            if(!vis[it]){
                dfs(vis,it,adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // create adj list
        vector<int>adj[n];
        for(auto it : invocations){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        // mark the suspected from given node k
       vector<int>vis(n,0);
       dfs(vis,k,adj);
        // now if non suspected which is not vis and has edge with suspected node 
        // if(yes) all node will be inserted else only component will removed in which all suspected node present
       bool isSus = true;
       for(int i =0;i<n;++i){
        if(!vis[i]){
            for(auto it : adj[i]){
                if(vis[it])isSus=false;
            }
        }
       }

        vector<int> ans;
        if(isSus){
       // all suspected node component removed only push non sus component
            for(int i =0;i<n;++i){
                if(!vis[i])ans.push_back(i);
            }
        }else{
            for (int i = 0; i < n; ++i) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};