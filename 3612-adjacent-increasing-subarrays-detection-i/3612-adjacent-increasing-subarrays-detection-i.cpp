class Solution {
public:

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>arr(n+1,1);
        for(int i =n-2;i>=0;--i){
            if(nums[i+1]>nums[i])arr[i]=arr[i+1]+1;
            else arr[i]=1;
        }

        for(int i = 0;i<=n-2*k;++i){
            if(arr[i]>=k && arr[i+k]>=k){
                    return true;
            }
        }

        return false;
    }
};
