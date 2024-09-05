class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum =0;
        for(auto x : rolls)sum+=x;
        int rem = mean*(n+m)-sum;
        if(rem<n)return {};
        vector<int>res(n,1);
        rem-=n;
        int i =0;
        while(rem--){
            res[i%n]++;
            if(res[i%n]>6)return {};
            i++;
        }
        return res;
        
    }
};