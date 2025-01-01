class Solution {
public:
    int maxScore(string s) {
        int n= s.size();
        int zero = 0,one = 0;
        
        for(int i=0;i<n;++i){
            if(s[i]=='0')zero++;
            else one++;
        }
        int currZero = 0;
        int currOne = 0;
        int ans = 0;
        for(int i =0;i<n-1;++i){
            if(s[i]=='0'){
                currZero++;
            }else{
                currOne++;
            }
            ans = max(ans,((one-currOne)+currZero));
        }
        // if(zero==0)return ans/2;
        return ans;
    }
};