class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>>mp;
        for(auto &x: strs){
            string s = x;
            sort(begin(s),end(s));
            mp[s].emplace_back(x);
        }
        for(auto &x : mp){
            res.emplace_back(x.second);
        }
        return res;
    }
};