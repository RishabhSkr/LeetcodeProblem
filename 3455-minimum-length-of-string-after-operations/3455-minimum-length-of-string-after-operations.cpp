class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        for(auto x: s)mp[x]++;
        int ans = 0;
        for(auto [x,f] : mp){
            if(f>2){
                if(f%2){
                    ans+=1;
                }else{
                    ans+=2;
                }
            }else ans+=f;
        }
        return ans;
    }
};