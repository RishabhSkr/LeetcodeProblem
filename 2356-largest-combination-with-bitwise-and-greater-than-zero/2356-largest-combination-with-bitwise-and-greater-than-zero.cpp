class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>mp(32,0);
        int maxi = 0;
        for(auto num : candidates){
            for(int i = 31;i>=0;--i){
                if(num & (1<<i))mp[i]++;
                maxi = max(maxi,mp[i]);
            }
        }
        return maxi;
    }
};