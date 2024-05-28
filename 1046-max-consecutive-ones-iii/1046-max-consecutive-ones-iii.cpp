class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt0 = 0;
        int i =0;
        int n =nums.size();
        int maxLen = 0;
        for(int j = 0;j<n;++j){
            if(nums[j]==0)cnt0++;
            while(cnt0>k){
                if(nums[i]==0)cnt0--;
                i++;
            }
            if(cnt0<=k)maxLen = max(j-i+1,maxLen);
        }
        return maxLen;
    }
};