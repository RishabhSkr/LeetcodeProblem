class Solution {
public:
    int getLucky(string s, int k) {
        string sum = "";
        for(auto ch : s){
            sum+=to_string(ch-'a'+1);
        }
        // cout<<sum<<endl;
        int res = 0;
        while(k--){
            int ans = 0;
            for(auto x : sum){
                ans+=(x-'0');
            }
            sum = to_string(ans);
        }
        
        return stoi(sum);
    }
};