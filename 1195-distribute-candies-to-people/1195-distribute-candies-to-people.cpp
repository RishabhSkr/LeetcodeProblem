class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        int ind =0;
        vector<int>ans(n,0);
        while(candies>=0){
            ans[ind%n] += min(ind+1,candies);
            ind = (ind+1);
            candies-=ind;

        } 
        return ans;
       
    }
};