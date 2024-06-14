class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int cnt =0;
        sort(nums.begin(),nums.end());
        for(int i =1;i<nums.size();++i){
            if(nums[i-1]>=nums[i]){
                int diff =nums[i-1]-nums[i];
                cnt+=diff+1;
                nums[i]=diff+nums[i]+1;
            }
        }
        return cnt;
    }
};