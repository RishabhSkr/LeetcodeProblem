//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> end) {
        // code here
        
    int n = grid.size();
    int m = grid[0].size();
    
    
    // if (n == 0 || m == 0 || grid[0][0] != 1) return -1;
    if(src.first ==end.first  && src.second == end.second)return 0;
    
    //  define dirns
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, pair<int, int>>> pq;
    
    pq.push({0, {src.first, src.second}});
    dist[src.first][src.second] = 0;

    while (!pq.empty()) {
        int currD = pq.front().first;
        int x = pq.front().second.first;
        int y = pq.front().second.second;
        pq.pop();

            for(int i =0 ;i<4 ; ++i){
                
                int nrow = x + dr[i];
                int ncol = y + dc[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && currD + 1 < dist[nrow][ncol]) {
                    
                    dist[nrow][ncol] = currD + 1;
                    
                    if (nrow == end.first && ncol== end.second) return currD+1;
                    
                    pq.push({currD + 1, {nrow, ncol}});
                }
            }
    }
    return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends