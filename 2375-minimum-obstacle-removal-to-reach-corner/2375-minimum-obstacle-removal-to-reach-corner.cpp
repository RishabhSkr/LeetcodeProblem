class Solution {
public:
        // T.C O(m*nlog(m*n))~ (V+E)log(V)
        // Algorithm
        // 1. intialised the prioritypq {0,0,0}(cost,i,j)
        // 2. do while(!pq.empty()) take out the curr pos check if is obs or empty 
        // if empty cost+0 else cost+1 (do for all 4 dirn) check vis(size(m*n) if not vis return min cost if reaches m-1,n-1
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        priority_queue<vector<int>>pq; // max heap (we will use it as min heap)
        pq.push({0,0,0});
        // 4 dirn
        int dirn[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int currCost = -1*top[0];
            int x = top[1];
            int y = top[2];
            if(x==m-1 && y==n-1)return currCost;
            for(auto dir : dirn){
                int newx = x + dir[0];
                int newy = y + dir[1];
                // check if this newx,newy is safe or not
                if(newx>=0 && newx<m && newy>=0 && newy<n && vis[newx][newy]!=1){
                    int newCost = 0;
                    if(grid[newx][newy]==1){
                        newCost = currCost+1;
                    }else{
                        newCost = currCost;
                    }
                    pq.push({-1*newCost,newx,newy});
                    vis[newx][newy]=1;
                }
            }
        }
        return -1;
    }
};