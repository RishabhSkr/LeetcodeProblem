class Solution {
public:
    bool check(vector<vector<int>>&grid,int row,int col){
        vector<int>mp(10,0);
        int magicSum = 15;
        bool isfalse = true;
        // check 1 to 9 in magicSuare
        for(int i =row;i<row+3;++i){
            for(int j  =col;j<col+3;++j){
              if(grid[i][j]<1 || grid[i][j]>9 || mp[grid[i][j]]>=1){
                return false;
              }
              mp[grid[i][j]]++;
            }
        }
        // check for every row,colsum == magic Sum
        for(int i =0;i<3;++i){
           int rowSum =0,colSum=0;
           for(int j= 0;j<3;++j){
            rowSum +=grid[row+i][col+j]; // rowsum
            colSum +=grid[row+j][col+i]; // col sum
           }
           if(rowSum!=magicSum || colSum!=magicSum)return false;   
        }
        // diagonal
        int dia1 =0,dia2 = 0;
        for(int i =0;i<3;++i){
            dia1+=grid[row+i][col+i];
            dia2+=grid[row+i][col+2-i];
        }
        if(dia1!=magicSum || dia2!=magicSum)return false;
        return true;

    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
         int cnt = 0;
         for(int i=0;i<=m-3;++i){
            for(int j =0;j<=n-3;++j){
                if(check(grid,i,j))cnt++;
            }
         }
        
         return cnt; 
    }
};