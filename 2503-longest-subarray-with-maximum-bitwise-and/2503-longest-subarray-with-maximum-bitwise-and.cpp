class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // find consecutive max element
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int cnt =0,ans =0;
        for(int i =0;i<n;++i){
           if(nums[i]==maxi){
            ans =  max(ans,++cnt);
           }else cnt =0;
        }
        return ans;

    }
};