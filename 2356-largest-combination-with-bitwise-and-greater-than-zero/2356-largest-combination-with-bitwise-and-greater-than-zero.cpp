class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // vector<int>mp(32,0);
        int maxi = 0;
       
            for(int i = 31;i>=0;--i){
                int cnt = 0;
                for(auto num : candidates){
                    if(num & (1<<i))cnt++;
                }
                maxi = max(maxi,cnt);
            }
        
        return maxi;
    }
};