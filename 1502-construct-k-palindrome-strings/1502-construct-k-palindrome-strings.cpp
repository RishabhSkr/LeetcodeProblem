class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.size())return false;
        unordered_map<char,int>mp;
        for(auto x : s)mp[x]++;
        int cntOdd = 0;
        for(auto [x,f] : mp)if(f%2)cntOdd++;
        if(cntOdd>k)return false;
        return true;
    }
};