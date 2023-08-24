//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    vector<vector<int>>dirns = {{0,1},{1,0},{0,-1},{-1,0}};
   
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        
 
        
         vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i  = 0 ;i<n ; ++i){
            for(int j = 0 ;j<m ; ++j){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        int totalTime = 0;
        
        while( !q.empty()){
            auto node  =  q.front();
            q.pop();
            int x = node.first.first;
            int y = node.first.second;
            int cnt = node.second;
            totalTime = max(totalTime , cnt);
            for(auto &dir : dirns){
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                
                if(new_x>=0 && new_x<n && new_y >=0 && new_y<m && vis[new_x][new_y]!= 2 && grid[new_x][new_y]==1){
                    q.push({{new_x,new_y},cnt+1});
                    vis[new_x][new_y] = 2;
                }

            }
            
        }
        
        for(int i = 0 ; i< n ;++i){
            for(int j =0 ;j<m ; ++j){
                if(vis[i][j]==0 && grid[i][j]==1)return -1;
            }
        }
        
        return totalTime;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends