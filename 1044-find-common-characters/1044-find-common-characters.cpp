class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>cnt(26,INT_MAX);
        for(auto str : words){
            vector<int>hash(26,0);
            for(auto ch : str)hash[ch-'a']++;
            for(auto i = 0;i<26;++i)cnt[i]= min(hash[i],cnt[i]);
        }

        vector<string>res;
        for(auto i =0;i<26;++i){
            for(auto j =0;j<cnt[i];++j){
                res.push_back(string(1,i+'a'));
            }
        }
        return res;
    }
};