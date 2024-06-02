class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
     unordered_map<int,int>uniqueColor;
     unordered_map<int,int>ballColor; //ball->color
     vector<int>ans;
     for(auto q:queries){
        int ball = q[0];
        int color = q[1];
        if(ballColor.count(ball)>0){
            int exiCol = ballColor[ball];
            if(uniqueColor[exiCol]==1)uniqueColor.erase(exiCol);
            else uniqueColor[exiCol]--;
            ballColor[ball]=color;
            uniqueColor[color]++;
        }else{
            ballColor[ball]=color;
            uniqueColor[color]++;
        }
        ans.push_back(uniqueColor.size());
     }
     return ans;
    }
};