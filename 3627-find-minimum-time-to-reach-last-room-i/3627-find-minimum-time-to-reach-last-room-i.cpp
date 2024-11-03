class Solution {
public:
    int n, m;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        n = moveTime.size();
        m = moveTime[0].size();

        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>> >pq;
        pq.push({0,0,0}); // minTime,i,j

        int dirn[][2] = {{-1,0},{0,-1},{1,0},{0,1}};
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0] = 1;

        int ans =0;

        while(!pq.empty()){
            auto top = pq.top();
            // cout<<top[0]<<endl;
            pq.pop();
            int curr = top[0];
            int i = top[1];
            int j = top[2];
            if(i==n-1 && j==m-1)return curr;
            for(auto dir : dirn){
                int newx = i+dir[0];
                int newy = j+dir[1];

                if(newx < 0 || newy < 0 || newx >= n || newy >= m || vis[newx][newy]) continue;
                
                int newtime = max(curr, moveTime[newx][newy]) + 1;
                vis[newx][newy] = 1;
                pq.push({newtime, newx, newy});
            }
        }
        return -1;
    }
};