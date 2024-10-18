class Solution {
public:
        // generate subset meanwhile calculate the or check with maxXor val
        // if it is equal then we have found the or subset cnt++;
    int n;
    void solve(int i,vector<int>&nums,int orVal,int &cnt,int &maxOR){
        if(i==n){
            if(orVal==maxOR)cnt++;
            return;
        }
        // include it 
        solve(i+1,nums,orVal|nums[i],cnt,maxOR);
        // not  include it
        solve(i+1,nums,orVal,cnt,maxOR);

        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        n=nums.size();
        int k = 0;
        int cnt=0;
        for(auto x : nums)k|=x;
        solve(0,nums,0,cnt,k);
        return cnt;
    }
};