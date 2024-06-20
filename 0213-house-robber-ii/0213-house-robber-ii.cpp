class Solution {
public:
int solve(vector<int>& nums) {
  int curr = 0,prev = nums[0],prev2 =0;
        for(int i =1;i<nums.size();++i){
           int notTake = 0+prev;
           int take =0;
           if(i>1)
             take = nums[i]+prev2;
            else take=nums[i]; // if neg ind <0 then store neg ind val =0 like in the base 
            curr= max(take,notTake);
            prev2 =prev;
            prev = curr;
        }
        return prev;
}

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<2)return nums[0];
        vector<int>arr1,arr2;
        for(int i =0;i<n-1;++i){
            arr1.push_back(nums[i]);
        }
        for(int i =1;i<n;++i){
            arr2.push_back(nums[i]);
        }
        return max(solve(arr1),solve(arr2));
    }
};