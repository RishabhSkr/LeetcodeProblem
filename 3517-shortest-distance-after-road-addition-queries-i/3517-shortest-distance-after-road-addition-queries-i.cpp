class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i =0;i<n-1;++i){
            adj[i].push_back({i+1,1});
        }
        auto dij = [&](){
            vector<int>dist(n,INT_MAX);
            dist[0]=0;
            priority_queue<pair<int,int>,vector<pair<int, int>>, greater<pair<int, int>>>pq;
            pq.push({0,0});
            while(!pq.empty()){
                int currDis = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                if(currDis>dist[node])continue;
                for(auto &nbr : adj[node]){
                    int adjNode = nbr.first;
                    int wt = nbr.second;
                    if(currDis+wt<dist[adjNode]){
                        dist[adjNode]=currDis+wt;
                        pq.push({currDis+wt,adjNode});
                    }
                }

            }
                return dist[n-1];
        };
        vector<int>ans;
        for(auto x: queries){
            int u = x[0];
            int v = x[1];
            adj[u].push_back({v,1});
            int shortest = dij();
            ans.push_back(shortest);

        }
        return ans;

    }
};