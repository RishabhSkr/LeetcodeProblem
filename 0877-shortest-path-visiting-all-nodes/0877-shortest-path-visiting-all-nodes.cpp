class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int nodeCount = graph.size();
        queue<pair<int,int>>q; // {node,states of visited node at particular point of time}
        bool vis[nodeCount][1<<nodeCount];
        memset(vis,false,sizeof(vis));
        
        // push all node in queue
        for(int i =0;i<nodeCount;++i){
            int bitmask = 1<<i; // set ith bit of ith node 
            q.emplace(i,bitmask);
            vis[i][bitmask]=true;
        }
        // run the bfs by increasing the pathLength at each iteration
        for(int path = 0;!q.empty();path++){
            int level = q.size();
            while(level--){
                auto [currNode,stateBitmask] = q.front();
                q.pop();

                if(stateBitmask== (1<<nodeCount)-1)return path; // all marked vis

                // explore adj nbr 
                for(auto nbr : graph[currNode]){
                    int nextStateBitMask = stateBitmask | (1<<nbr); // update the bitmask
                    if(!vis[nbr][nextStateBitMask]){
                        vis[nbr][nextStateBitMask]=true;
                        q.emplace(nbr,nextStateBitMask);
                    }

                }
            }
        }
        return -1;

    }
};