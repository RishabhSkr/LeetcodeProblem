class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<5)return 0;
        int ans =INT_MAX;
            // 3 moves ka use piche ele ko change krne me laga do.max ele n-4 pr hga
            ans = min(ans,nums[n-4]-nums[0]);
            ans = min(ans,nums[n-3]-nums[1]);
            ans = min(ans,nums[n-2]-nums[2]); // 2 front aur 1 piche
            ans = min(ans,nums[n-1]-nums[3]); // 3 moves me 0 1 2 ko change 4th elem min hga
             
        return ans;
    }
};