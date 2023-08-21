//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

 vector<vector<int>>dirn = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};

    int Count(vector<vector<int> >& matrix) {
        int maxcnt = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i =0; i<n; ++i){
            
            for(int j = 0; j<m; ++j){
                
                
                if(matrix[i][j]==1){
                    int cnt =0;
                    for(auto &dir : dirn){
                        int x = i +dir[0];
                        int y = j +dir[1];
                        if(x>=0&& x<n and y>=0 && y<m and matrix[x][y]==0){
                            cnt++;
                        }
                    }
                if(cnt%2==0 and cnt>0)maxcnt++;
                }
                
            }
        }
        return maxcnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends