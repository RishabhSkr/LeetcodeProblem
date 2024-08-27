    class Solution {
    public:
        double maxProbability(int n, vector<vector<int>>& edges, vector<double>& Prob, int start_node, int end_node) {
            vector<pair<int,double>>adj[n];
            for(int i =0;i<edges.size();++i){
                int u =edges[i][0];
                int v = edges[i][1];
                double wt = Prob[i];
                adj[u].push_back({v,wt});
                adj[v].push_back({u,wt});
            }
    
            vector<double>res(n,0.0); // 0 se kroge to wrong ans prob ki
            priority_queue<pair<double,int>>pq;
            pq.push({1,start_node});
            res[start_node]=1;
            while(!pq.empty()){
                auto top = pq.top();
                double currProb = top.first;
                int node = top.second;
                pq.pop();

                for(auto nbr : adj[node]){
                    int adjNode = nbr.first;
                    double wt = nbr.second;
                    if(currProb*wt>res[adjNode]){
                        res[adjNode]=currProb*wt;
                        pq.push({currProb*wt,adjNode});
                    }
                }
            }
            return res[end_node];
        }
    };