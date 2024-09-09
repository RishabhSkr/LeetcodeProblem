class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int top = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;
        vector<int>ans;
        // dirn = 0 ->left to right
        //        1=top to down
        //        2= right->left
        //        3 = down to top
        int dirn = 0;
        while(top<=down && left<=right){
            if(dirn==0){
                // const = row
                // order = left to right 
                for(int i =left;i<=right;++i){
                    ans.push_back(mat[top][i]);
                }
                top++;
            }
            if(dirn ==1){
                // const = col
                // order =  top to bottom 
                for(int i =top;i<=down;++i){
                    ans.push_back(mat[i][right]);
                }
                right--;
            }
            if(dirn==2){
                // const = row
                // order =  right to left 
                for(int i =right;i>=left;--i){
                    ans.push_back(mat[down][i]);
                }
                down--;
            }
            if(dirn == 3){
                // const = col
                // order =  down to top 
                for(int i =down;i>=top;--i){
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
            dirn= (dirn+1)%4;
        }
        return ans;
    }
};