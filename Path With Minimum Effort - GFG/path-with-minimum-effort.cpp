//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
 

//   Dijktras Concept : pq and dist 
    int MinimumEffort(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Code here
        // {{diff,{row,col}}}
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
         
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(x==n-1 && y == m-1)return diff;
            
            for(int i =0 ;i<4 ; ++i){
                
                int nrow = x + dr[i];
                int ncol = y + dc[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                   // Effort can be calculated as the max value of differences 
                    // between the heights of the node and its adjacent nodes.
                    int newEffort = max(abs(grid[x][y] - grid[nrow][ncol]), diff);
                   
                   if(newEffort<dist[nrow][ncol]){
                        dist[nrow][ncol]=newEffort;
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                       
                   }
                }
                
            }
        }
        return 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends