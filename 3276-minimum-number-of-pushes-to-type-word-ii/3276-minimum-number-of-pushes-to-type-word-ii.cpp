class Solution {
public:
    int minimumPushes(string word) {
       vector<int>mp(26,0);
        // mark the freq
        for(auto &ch :word)mp[ch-'a']++; 
        // use greedy assign max freq at first key
        sort(mp.rbegin(),mp.rend());
        int ans = 0;
        for(int i =0;i<26;++i){ // iteerate thorough each appear in word
            if(mp[i]==0)break;  // early return
            ans+=((i/8)+1)*mp[i]; // this is logic where after every 1 cycle of 8 elemen every other character will get rank or place i.e first,second,third
        }
        return ans;
    }
};