class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,0);
        // mark the freq
        for(auto &ch :word)mp[ch-'a']++; 
        // use greedy assign max freq at first key
        sort(mp.rbegin(),mp.rend());
        int ans = 0;
        for(int i =0;i<word.size();++i){
            if(mp[i]==0)continue;
            ans+=((i/8)+1)*mp[i];
        }
        return ans;
    }
};