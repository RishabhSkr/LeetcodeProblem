class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int>mp;
        for(auto x : banned)mp[x]++;
        int no = 1;
        int sum = 0;
        int cnt = 0;
        while(no<=n){
            if(sum+no<=maxSum && mp.count(no)==0 ){
                sum+=no;
                cnt++;
                mp[no]++;
            }
            no++;
        }
        return cnt;
    }
};