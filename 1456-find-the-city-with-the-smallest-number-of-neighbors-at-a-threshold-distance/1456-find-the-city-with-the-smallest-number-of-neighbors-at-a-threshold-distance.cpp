class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>>cost(n,vector<int>(n,1e6));
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int dist = edge[2];
            cost[u][v]=dist;
            cost[v][u]=dist;
        }
        for (int i = 0; i < n; ++i) {
            cost[i][i] = 0;
        }
        for(int via=0;via<n;++via){
            for(int i =0;i<n;++i){
                for(int j = 0;j<n;++j){
                    cost[i][j]= min(cost[i][j],cost[i][via]+cost[via][j]);
                }
            }
        }
        pair<int,int> ans = {1e9,1e9};
        for(int i= 0;i<n;++i){
            int cnt = 0;
            for(int j =0;j<n;++j){
                if(cost[i][j]<=k){
                    cnt++;
                }
            }
            if(ans.first>=cnt){
                ans.first = cnt;
                ans.second = i;
            }
        }
        return ans.second;
        
    }
};