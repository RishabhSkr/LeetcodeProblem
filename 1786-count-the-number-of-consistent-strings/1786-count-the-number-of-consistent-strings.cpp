class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<int,int>mp;
        for(auto x : allowed)mp[x]++;
        int cnt = 0;
        for(auto word : words){
            bool isFound = true;
            for(auto ch : word){
                if(mp.count(ch)==0)isFound = false;
            }
            if(isFound)cnt++;
        }
        return cnt;
    }
};