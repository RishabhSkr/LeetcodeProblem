class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
       // logic is sbko peak maano and kyonki mountain array peak ek hi hga
       // left side and right side me check the if ele < curr element then move to the left and right sid of each side 
       int n  = nums.size();
       int ans =n;
        // calculate list from left to right
            vector<int>lis(n,1);
            for(int i =0;i<n;++i){
                for(int j = i -1;j>=0;--j){
                    if(nums[i]>nums[j])lis[i]=max(lis[i],1+lis[j]);
                }
            }
        // right to left decreaing
            vector<int>lds(n,1);
            for(int i =n-1;i>=0;--i){
                for(int j = i+1;j<n;++j){
                    if(nums[i]>nums[j])lds[i]=max(lds[i],1+lds[j]);
                }
            }
        // step 3 
        for(int i = 0;i<n;++i){
             int mountainLength = lis[i] + lds[i] - 1;
            if(lis[i]>1 && lds[i]>1)ans = min({ans,n-mountainLength});
        }
       return ans;
    }
};