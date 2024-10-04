class Solution {
public:
    int beautySum(string s) {
      int n = s.size();
      int ans =0;
        for(int i =0;i<n;++i){
            unordered_map<char,int>mp; // har ek i ke liye freq store kr
            for(int j = i;j<n;++j){
                mp[s[j]]++;
                int mini = INT_MAX;
                int maxi = INT_MIN;
                for(auto [x,f] : mp){
                    maxi = max(maxi,f);
                    mini = min(mini,f);
                }
                ans+=maxi-mini;
            }

        }
        return ans;
    }
};