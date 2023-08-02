//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int n,m;
    vector<pair<int,int>>dirn={{0,1},{1,0},{-1,0},{0,-1}};
   bool isValid(int i , int j, vector<vector<int>>&arr){
        if(i>=0 && i< n && j>=0 && j<m && arr[i][j]!=0) return true;
        return false;
  }
  
  int solve( vector<vector<int>>arr,int X,int Y){
      int ans =INT_MAX;
   queue<pair<int,pair<int,int>>>q;
   q.push({0,{0,0}});
   while(!q.empty()){
       
       auto temp = q.front();
       q.pop();
       
       int dis = temp.first;
       int new_x=temp.second.first;
       int new_y=temp.second.second;
       if(new_x ==X && new_y==Y)return dis;
       for(auto dir: dirn){
          int i  =new_x+dir.first;
           int j =new_y+dir.second;
           if(isValid(i,j,arr)){
               arr[i][j]=0;
                q.push({dis+1,{i,j}});
            }
       }
     
    
   }
   return -1;

  }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        n = N,m=M;
        return solve(A,X,Y);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends