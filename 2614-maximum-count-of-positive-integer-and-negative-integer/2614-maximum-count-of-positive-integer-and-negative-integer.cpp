class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cnt1 = 0,cnt2 =0;
        int i =0,n = nums.size();
        while(i<n){
          
            if(nums[i]<0)cnt1++;
            if(nums[i]>0)cnt2++;
            i++;
        }
        return max(cnt1,cnt2);
    }
};