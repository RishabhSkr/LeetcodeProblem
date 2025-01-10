class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        int m = pref.size();
        for(auto word:words){
            string sub = word.substr(0,m);
            if(sub==pref)ans++;
        }
        return ans;
    }
};