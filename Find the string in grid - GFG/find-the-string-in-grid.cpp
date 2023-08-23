//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int  n;
	int  m; 
    

 bool dfs(int i ,int j , int idx,vector<vector<char>>&grid,string &word,int new_x,int new_y){
  
   if(idx == word.size())return true;
   if(i>=0 && i<n && j>=0 && j<m && word[idx]==grid[i][j]){
       return dfs(i+new_x,j+new_y,idx+1,grid,word,new_x,new_y);
   }
   return false;
     
 }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    n = grid.size();
	    m= grid[0].size();
	     int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	    
	    vector<vector<int>>ans;
	   
	    for(int  i =0 ;i<n ;++i){
	        for(int j = 0 ;j<m ; ++j){
	            
	            if(grid[i][j]==word[0]){
	                 for (int k = 0; k < 8; k++) {
    	                        if(dfs(i,j,0,grid,word,dx[k],dy[k])){
    	                        ans.push_back({i,j});
    	                        break;
	                        }
	                    }
	                
	                 
	            }
	            
	               
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends