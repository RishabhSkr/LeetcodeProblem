class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // n*m
        int n = box.size();
        int m = box[0].size();
        // m*n
        vector<vector<char>>ans(m,vector<char>(n));
        for(auto &row : box){
            int emptyPos = m-1;
            for(int col = m-1 ; col>=0;col--){
               
                // obstacle
                if(row[col]=='*'){
                    emptyPos= col-1;
                }else if(row[col]=='#'){
                   
                    row[col]='.';
                    row[emptyPos--]= '#';
                }
            }

        }
        // row 90 degrea
        for(int i =0;i<n;++i){
            for(int j = 0 ;j<m;++j){
                ans[j][n-i-1] = box[i][j];
            }
        }
        return ans;
    }
};