class Solution {
public:
/*
    Yahan key observation hai:

Jab difference even hai (4,2), code '+1' add karta hai -> ye ensure karta hai ki hum minimum requirement se ek step aage jayein
Jab difference odd hai (3,1), code '+0' add karta hai -> kyunki odd difference ke case mein hum exactly minimum time par pahunch sakte hain

Why this works?

Agar difference even hai, toh hum exact minimum time par nahi pahunch sakte (kyunki har move 1 second leti hai)
Agar difference odd hai, toh hum exact minimum time par pahunch sakte hain
Case 1: 
- Current time (t) = 2
- grid[r][s] = 5
- diff = 5-2 = 3 (odd)
- w = 0
- nextTime = max(3, 5+0) = 5

Case 2:
- Current time (t) = 2
- grid[r][s] = 4
- diff = 4-2 = 2 (even)
- w = 1
- nextTime = max(3, 4+1) = 5
the real problem is sTatemene is this
You are standing in the top-left cell of the matrix in the 0th second, and you must move to any adjacent cell in the four directions: up, down, left, and right. Each move you make takes 1 second.
-----------------hinglish
hame wait nhi kr ham aage piche move krte rhna jiss time increas hga 
ekin actual problem yeh keh raha hai ki hum wait nahi kar sakte - hum bas adjacent cells mein move kar sakte hain, jahan bhi jaayein 1 second lagega.
*/
    int dirn[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int minimumTime(vector<vector<int>>& grid) {
        // Edge case: Check if we can move from start
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;

        // pq minHeap(mintime,i,j)
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        priority_queue<vector<int>>pq;// use as minHeap

        dist[0][0]=0;
        pq.push({0,0,0}); //{-time,0,0}
        while(!pq.empty()){
            auto top = pq.top();
            int currTime = -1*top[0];
            int i = top[1];
            int j  = top[2];
            pq.pop();
            if(currTime > dist[i][j]) continue;
            for(auto dir : dirn){
                int x = i+dir[0];
                int y = j+dir[1];
                if(x>=0 && x<m && y>=0 && y<n){
                     // Agar next cell ka time bada hai currTime se
                    // toh hume back-and-forth jana padega
                    // Har back-and-forth se 2 second badhega
                    int waitTime = (grid[x][y] - (currTime + 1));
                    int extraTime = waitTime > 0 ? ((waitTime + 1) / 2) * 2 : 0; // yhi wo time h lagega ood / even check (even ke case ek bar piche jana padege fir wapas aayenge fir 1 to total 2 )
                    int nextTime = currTime + 1 + extraTime;

                    if(nextTime<dist[x][y]){
                        dist[x][y]= nextTime;
                        pq.push({-1*nextTime,x,y});
                    }  
                }
            }
        }
        return dist[m-1][n-1]==INT_MAX?-1:dist[m-1][n-1];
    }
};