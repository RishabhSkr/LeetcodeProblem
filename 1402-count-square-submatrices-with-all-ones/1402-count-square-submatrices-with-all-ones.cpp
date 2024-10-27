class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) { 
        // intuition: yhi h ki hme largest sqr ki side nikani jo only 1's se filled ho
        //min side of sqr containing 1 kitna size ka hga =1*1 side ka
        // agr hm kisi me store kr le prev side kitne len ka tha usme agr hme add kren curr 1 to side badhegi if(curr mat[row][col]=='1')else 0;
        // to ham min side dekhenge prev diag ,lef and up me useme plus 1 kr denge to 2 size ka side ho jaega if min 1 and curr bhi 1 h mtlb isse pahle wale sare 1 honge tbhi to 1+1 =2 size ka side hga .
         int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        int ans = 0;
        for(int i =0;i<m;++i){
            for(int j =0;j<n;++j){
                if(matrix[i][j]==1){
                    dp[i+1][j+1]=1+min({dp[i][j],dp[i][j+1],dp[i+1][j]});
                    ans+=dp[i+1][j+1];
                }else dp[i+1][j+1]=0;
            }
        }
        
        
        return ans;
    }
};