class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int sum = 0;
        for(auto x : nums)sum=(sum+x)%p;
        int tar = sum%p;
        if(tar==0)return 0;
        unordered_map<int,int>mp;
        int mini =1e9;
        int curr = 0;
        mp[0]=-1; // for zero sum j-i
        for(int j =0;j<n;++j){
            curr=(curr+nums[j])%p;
            int prev = (curr-tar+p)%p;
            if(mp.find(prev)!=mp.end()){
                mini = min(mini,j-mp[prev]);
            }
            mp[curr]=j;

        }
        if(mini==n)return -1;
        return mini;
    }
};