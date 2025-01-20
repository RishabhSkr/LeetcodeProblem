class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int size =arr.size();
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<m;++i){
            for(int j =0;j<n;++j){
                mp[mat[i][j]]={i,j};
            }
        }
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        
        for(int k = 0; k < size; k++) {
            auto [x,y] =mp[arr[k]];
            rowCount[x]++;
            colCount[y]++;
            
            // Check if any row or column is complete
            if(rowCount[x] == n || colCount[y] == m) {
                return k;
            }
        }
        
        return -1;
    }
};