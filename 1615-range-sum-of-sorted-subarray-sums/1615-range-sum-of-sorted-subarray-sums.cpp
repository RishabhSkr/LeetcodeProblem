class Solution {
public:
    int mod = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long>sub;
        for(int i =0;i<n;++i){
            long sum =0;
            for(int j =i;j<n;++j){
                sum=(sum+(nums[j]%mod))%mod;
                sub.push_back(sum);
            }
        } 
        sort(sub.begin(),sub.end());
        
        int ans =0;
        for(int i =left-1;i<right;++i){
            ans=(ans%mod+(sub[i]%mod))%mod;
        }
        
        return ans;
    }
};