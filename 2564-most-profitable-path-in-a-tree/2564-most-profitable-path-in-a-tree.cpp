class Solution {
public:
    unordered_map<int, int> mp;
    unordered_map<int, vector<int>> adj;
    vector<int> vis;
    int res = INT_MIN;

    bool dfs(int node, int time) {
        mp[node] = time;
        vis[node] = 1;
        if (node == 0) return true;
        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {
                if (dfs(nbr, time + 1)) return true;
            }
        }
        mp.erase(node);
        return false;
    }

    void dfsAlice(int curr, int t, vector<int>& amt, int ans) {
        vis[curr] = 1;
        
        if (!mp.count(curr) || t < mp[curr]) ans += amt[curr];  
        else if (t == mp[curr]) ans += amt[curr] / 2; 
        
        if (adj[curr].size() == 1 && curr!=0 ) res = max(res, ans); 

        for (auto nbr : adj[curr]) {
            if (!vis[nbr]) {
                dfsAlice(nbr, t + 1, amt, ans);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size();
        vis.resize(n + 1, 0);
        
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Bob's path
        dfs(bob, 0);
        
        // Alice's path
        int ans = 0;
        vis = vector<int>(n + 1, 0);  // Properly reset vis
        dfsAlice(0, 0, amount, ans);

        return res;
    }
};
