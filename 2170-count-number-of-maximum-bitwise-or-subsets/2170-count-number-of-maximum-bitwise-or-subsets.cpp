class Solution {
public:
        // generate subset meanwhile calculate the or check with maxXor val
        // if it is equal then we have found the or subset cnt++;
    int n;
    unordered_map<string ,int>mp; // memoize
    int solve(int i,vector<int>&nums,int orVal,int &maxOR){
        if(i==n){
            return (orVal==maxOR)? 1: 0;
        }
        string key = to_string(i)+','+to_string(orVal);
        if(mp.find(key)!=mp.end())return mp[key];
        // include it 
        int take = solve(i+1,nums,orVal|nums[i],maxOR);
        // not  include it
        int notTake = solve(i+1,nums,orVal,maxOR);
        return mp[key]=take+notTake;

        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        n=nums.size();
        int k = 0;
        for(auto x : nums)k|=x;
        return solve(0,nums,0,k);
    }
};