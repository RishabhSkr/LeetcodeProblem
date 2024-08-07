class Solution {
public:
    int minimumPushes(string word) {
        int key = 2;
        vector<int>mp(10,0);
        int ans = 0;
        // 2 3 4 5 6 7 8 
        for(auto ch : word){
            if(key>9){
                key= 2;
            }
            mp[key]++;
            ans+=mp[key];
            key++;
        }
        return ans;
    }
};