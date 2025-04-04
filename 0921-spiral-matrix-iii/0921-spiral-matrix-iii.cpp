class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        // try simulation just find where you have to increase the steps and you are traversing in square
        int dirn[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // E, S, W, N
        vector<vector<int>>res;
        int dir = 0,steps =0;
        res.push_back({rStart,cStart});
        while(res.size()<rows*cols){
            if(dir==0 || dir ==2)steps++;
            
            for(int i =0;i<steps;++i){  
                rStart+=dirn[dir][0];
                cStart+=dirn[dir][1];
                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols)res.push_back({rStart,cStart});
            }
            dir=(dir+1)%4;
        }
        return res;
    }
};