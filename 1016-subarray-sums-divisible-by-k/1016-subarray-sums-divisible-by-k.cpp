class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(),sum=0,cnt=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i =0;i<n;++i){
            sum+=nums[i];
            int mod= (sum%k+k)%k; // for negative integers it will add modulo with negative sign<k so if we add k to it become positive but wait we adding sum to it may be possible it can greater upto k we again have to take modulo
            // cout<<mod<<endl;
            if(mp.count(mod)>0)cnt+=mp[mod];
            mp[mod]++;
        }
        return cnt;
    }
};