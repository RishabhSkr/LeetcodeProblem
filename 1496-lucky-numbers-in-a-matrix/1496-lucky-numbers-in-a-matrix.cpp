class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n  = matrix[0].size();
        vector<int>minEle;
        vector<int>maxi(n,-1e9);
        for(int i =0;i<m;++i){
            int mini = 1e9;
            for(int j =0;j<n;++j){
                mini = min(mini,matrix[i][j]);
                maxi[j] = max(maxi[j],matrix[i][j]);
                
            }
            minEle.push_back(mini);
        }
        
        vector<int>lucky;
        for(int i =0;i<minEle.size();++i){
            for(int j =0;j<maxi.size();++j){
                if(maxi[j]==minEle[i]){
                    if(!lucky.empty() && maxi[j]==lucky.back() )continue;
                    lucky.push_back(maxi[j]);
                }
                
            }

        }
       return lucky;
    }
};