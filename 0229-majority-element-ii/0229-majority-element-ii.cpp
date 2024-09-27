class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(auto x : nums)mp[x]++;
        for(auto [x,f] : mp)if(f>(nums.size()/3))res.push_back(x);
        return res;
    }
};