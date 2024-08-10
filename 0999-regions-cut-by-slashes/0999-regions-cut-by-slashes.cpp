class Solution {
public:
        // logic visualize  then apply number islands dfs to count regions
        // "/" -> 001 similarly '\'->100  " "->all zeros 
             //   010                010
             //   100                001  
    int matrow ,matcol;
    int dirn[4][2]={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool isSafe(vector<vector<int>>&mat,int i,int j){
        return (i<0 || i>=matrow || j>=matcol || j<0 || mat[i][j]==1);
    }
    void dfs(vector<vector<int>>&mat,int i,int j){
        mat[i][j]=1;
        for(auto &dir : dirn){
            int newx = i+dir[0];
            int newy = j+dir[1];
            if(!isSafe(mat,newx,newy)){
                dfs(mat,newx,newy);
            }
        }

    }
    int regionsBySlashes(vector<string>& grid) {
        int row  = grid.size();
        int col =grid[0].size();

        // build matrix
        vector<vector<int>>mat(row*3,vector<int>(col*3,0));
        for(int i =0;i<row;++i){
            for(int j =0;j<col;j++){
                if(grid[i][j]=='/'){
                    mat[i*3][j*3+2]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3]=1;

                }else if(grid[i][j]=='\\'){
                    mat[i*3][j*3]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3+2]=1;
                }
            }
        }
        int ans = 0;
        matrow = mat.size(),matcol=mat[0].size();
        for(int i =0;i<matrow;++i){
            for(int j =0;j<matcol;++j){
                if(mat[i][j]==0){
                    dfs(mat,i,j);
                    ans++;
                }

            }
        }
        return ans;
    }
};