class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int n = mat.size();
        int m = mat[0].size();
        int left  =0, top = 0, right = m-1,down = n-1;
        while(top<=down && left<=right){

            //left to right side
                for(int i = left ;i<= right ;++i){
                    ans.push_back(mat[top][i]);
                }
                top++;
                // right to down side 
                for(int i = top ;i<= down ;++i){
                    ans.push_back(mat[i][right]);
                }
                right--;

                if(top<= down){
                    // right to left
                    for(int i = right ;i>= left ;--i){
                        ans.push_back(mat[down][i]);
                    }
                    down--;
                }
                
                // left to top
                if(left<=right){
                    for(int i =  down;i>=top ;--i){
                        ans.push_back(mat[i][left]);
                    }
                    left++;
                }
        }
        return ans;

    }
};