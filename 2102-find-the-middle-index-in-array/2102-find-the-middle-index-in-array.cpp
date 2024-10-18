class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum =0;
     for(auto x : nums)sum+=x;
     int curr =0;
     for(int i =0;i<nums.size();++i){
        curr+=nums[i];
        if((sum-(curr-nums[i]))==curr)return i;
     }  
     return -1; 
    }
};