class Solution {
public:
    int n, m;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        n = moveTime.size();
        m = moveTime[0].size();

        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>> >pq;

        int dirn[][2] = {{-1,0},{0,-1},{1,0},{0,1}};

         // Track visited state including alterMove
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(2, false)));

        pq.push({0,0,0,0}); // minTime,i,j,alterMove
        vis[0][0][0] = true;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int curr = top[0];
            int i = top[1];
            int j = top[2];
            int alterMove= top[3];
            if(i==n-1 && j==m-1)return curr;
            for(auto dir : dirn){
                int newx = i+dir[0];
                int newy = j+dir[1];

                if(newx < 0 || newy < 0 || newx >= n || newy >= m || vis[newx][newy][alterMove]) continue;
                int newtime = max(curr, moveTime[newx][newy]) +( (alterMove)? 2 : 1);
                
                 // Next state will have opposite alterMove
                int nextAlterMove = 1 - alterMove;
                
                // Skip if we've seen this state before
                if(vis[newx][newy][nextAlterMove]) continue;

                vis[newx][newy][nextAlterMove] = true;

                pq.push({newtime, newx, newy,nextAlterMove});
            }
        }
        return -1;
    }
};