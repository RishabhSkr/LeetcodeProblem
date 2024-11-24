class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
       int neg = 1e7;
       int cntneg = 0;
        
        long long ans = 0;
        for(auto row : matrix){
            for(auto x : row){
                ans+=abs(x);
                neg = min(neg,abs(x));// hume min positive element sum me se minus krna h and mini neg element jo positive ho
                if(x<0)cntneg++;
            }
            cout<<endl;
        }

        if(cntneg%2==0){
           return ans;
        }
             
        ans-=2*neg;
        return ans;
    }
};