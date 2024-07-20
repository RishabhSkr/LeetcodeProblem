class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n= rowSum.size();
        int m =  colSum.size();
        vector<vector<int>>mat(n,vector<int>(m,0));
        int i =0,j =0;

        while(i<n && j< m){
            if(rowSum[i]<colSum[j]){
                mat[i][j]=rowSum[i];
                colSum[j]-=rowSum[i];
                rowSum[i]=0;
                i++;
            }
            else{
                 mat[i][j]=colSum[j];
                rowSum[i]-=colSum[j];
                colSum[j]=0;
                j++;
            }
        }
        return mat;
    }
};