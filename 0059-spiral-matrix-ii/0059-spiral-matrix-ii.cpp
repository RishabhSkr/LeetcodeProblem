class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m = n;
        int top = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;
        // dirn = 0 ->left to right
        //        1=top to down
        //        2= right->left
        //        3 = down to top
        vector<vector<int>>mat(m,vector<int>(n));
        int num =1;
        int dirn = 0;
        while(top<=down && left<=right){
            if(dirn==0){
                // const = row
                // order = left to right 
                for(int i =left;i<=right;++i){
                    mat[top][i]=num++;
                }
                top++;
                
            }
            if(dirn ==1){
                // const = col
                // order =  top to bottom 
                for(int i =top;i<=down;++i){
                    mat[i][right]=num++;
                }
                right--;
            }
            if(dirn==2){
                // const = row
                // order =  right to left 
                for(int i =right;i>=left;--i){
                    mat[down][i]=num++;
                }
                down--;
            }
            if(dirn == 3){
                // const = col
                // order =  down to top 
                for(int i =down;i>=top;--i){
                    mat[i][left]=num++;
                }
                left++;
            }
            dirn= (dirn+1)%4;
        }
        return mat;
    }
};