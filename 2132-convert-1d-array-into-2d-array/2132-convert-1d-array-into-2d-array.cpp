class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& ori, int m, int n) {
        int len = m*n;
        int size = ori.size();
        if(size!=m*n)return {};
         vector<vector<int>>mat(m,vector<int>(n,0));
        for(int i = 0;i<size;++i){
            int x = i/n; // col major
            int y = i%n; // col major
            mat[x][y]=ori[i];
        }
        return mat;
    }
};