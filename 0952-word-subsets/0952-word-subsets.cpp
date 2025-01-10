class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int mp[26]={0};
        for(auto word : words2){
            int freq[26]={0};
            for(auto c : word){
                char ch = c-'a';
                freq[ch]++;
                mp[ch]= max({mp[ch],freq[ch]});
            }
        }
        vector<string>ans;
        for(auto &word : words1){
            int freq[26]={0};
            for(auto c : word){
                char ch = c-'a';
                freq[ch]++;
            }
            bool isTrue =true;
            for(int i = 0;i<26;++i){
                if(freq[i]<mp[i])isTrue = false;
            }
            if(isTrue)ans.push_back(word);
        }
        return ans;
    }
};