class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
       unordered_map<int,int>preSum;//prefixSum,cnt
        int prefixSum = 0;
        preSum[0]=1; // intitally set sum =0 into map as prefixSum==0 
        int cnt =0;
        for(int j =0;j<n;++j){
            prefixSum+=(nums[j]%2);
            // find prefixSum-k
            cnt+=preSum[prefixSum-k];
            preSum[prefixSum]++;
        }
        return cnt;
    }
};